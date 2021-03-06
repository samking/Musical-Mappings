#include "pitch_detector.h"
#include "mappingsinterface.h"
#include "indicator.h"
#include "pitch_api/inc/fmod.hpp"
#include "pitch_api/inc/fmod_errors.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string>
#include <iostream>
#include <QObject>

void ERRCHECK(FMOD_RESULT result)
{
    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        exit(-1);
    }
}

static const char *note[120] =
{
    "C 0", "C#0", "D 0", "D#0", "E 0", "F 0", "F#0", "G 0", "G#0", "A 0", "A#0", "B 0",  
    "C 1", "C#1", "D 1", "D#1", "E 1", "F 1", "F#1", "G 1", "G#1", "A 1", "A#1", "B 1",  
    "C 2", "C#2", "D 2", "D#2", "E 2", "F 2", "F#2", "G 2", "G#2", "A 2", "A#2", "B 2",  
    "C 3", "C#3", "D 3", "D#3", "E 3", "F 3", "F#3", "G 3", "G#3", "A 3", "A#3", "B 3",  
    "C 4", "C#4", "D 4", "D#4", "E 4", "F 4", "F#4", "G 4", "G#4", "A 4", "A#4", "B 4",  
    "C 5", "C#5", "D 5", "D#5", "E 5", "F 5", "F#5", "G 5", "G#5", "A 5", "A#5", "B 5",  
    "C 6", "C#6", "D 6", "D#6", "E 6", "F 6", "F#6", "G 6", "G#6", "A 6", "A#6", "B 6",  
    "C 7", "C#7", "D 7", "D#7", "E 7", "F 7", "F#7", "G 7", "G#7", "A 7", "A#7", "B 7",  
    "C 8", "C#8", "D 8", "D#8", "E 8", "F 8", "F#8", "G 8", "G#8", "A 8", "A#8", "B 8",  
    "C 9", "C#9", "D 9", "D#9", "E 9", "F 9", "F#9", "G 9", "G#9", "A 9", "A#9", "B 9"
};

static const float noteFreq[120] =
{
      16.35f,   17.32f,   18.35f,   19.45f,    20.60f,    21.83f,    23.12f,    24.50f,    25.96f,    27.50f,    29.14f,    30.87f, 
      32.70f,   34.65f,   36.71f,   38.89f,    41.20f,    43.65f,    46.25f,    49.00f,    51.91f,    55.00f,    58.27f,    61.74f, 
      65.41f,   69.30f,   73.42f,   77.78f,    82.41f,    87.31f,    92.50f,    98.00f,   103.83f,   110.00f,   116.54f,   123.47f, 
     130.81f,  138.59f,  146.83f,  155.56f,   164.81f,   174.61f,   185.00f,   196.00f,   207.65f,   220.00f,   233.08f,   246.94f, 
     261.63f,  277.18f,  293.66f,  311.13f,   329.63f,   349.23f,   369.99f,   392.00f,   415.30f,   440.00f,   466.16f,   493.88f, 
     523.25f,  554.37f,  587.33f,  622.25f,   659.26f,   698.46f,   739.99f,   783.99f,   830.61f,   880.00f,   932.33f,   987.77f, 
    1046.50f, 1108.73f, 1174.66f, 1244.51f,  1318.51f,  1396.91f,  1479.98f,  1567.98f,  1661.22f,  1760.00f,  1864.66f,  1975.53f, 
    2093.00f, 2217.46f, 2349.32f, 2489.02f,  2637.02f,  2793.83f,  2959.96f,  3135.96f,  3322.44f,  3520.00f,  3729.31f,  3951.07f, 
    4186.01f, 4434.92f, 4698.64f, 4978.03f,  5274.04f,  5587.65f,  5919.91f,  6271.92f,  6644.87f,  7040.00f,  7458.62f,  7902.13f, 
    8372.01f, 8869.84f, 9397.27f, 9956.06f, 10548.08f, 11175.30f, 11839.82f, 12543.85f, 13289.75f, 14080.00f, 14917.24f, 15804.26f
};

#define OUTPUT_RATE          48000
#define SPECTRUM_SIZE        8192
#define SPECTRUM_RANGE       ((float)OUTPUT_RATE / 2.0f)      /* 0 to nyquist */
#define BIN_SIZE      (SPECTRUM_RANGE / (float)SPECTRUM_SIZE)

MappingsInterface *mappingsInterface;

PitchDetector::PitchDetector(MappingsInterface &mapWindow, 
							 Indicator &indicator,
							 QObject *parent)
{
	connect(this, SIGNAL(UpdateTitleSignal(QString)), 
		    &mapWindow, SLOT(setWindowTitle(QString)));
	connect(this, SIGNAL(UpdateNoteDisplaySignal(int, double)),
			&indicator, SLOT(PlaceIndicator(int, double)));
	mappingsInterface = &mapWindow;
}

PitchDetector::~PitchDetector(void)
{
}

/* Returns a number between -0.5 and 0.5 representing the deviation between
 * the frequency and the ideal frequency of the note.  For instance, if the
 * note is a C and the frequency is 32.70, then the deviation will be 0.  If
 * the note is a C and the frequency is 33, it will return 0.15 because the 
 * next highest note is a C#, which is 34.65, and 33 is 15% between 32.7 and 
 * 34.65.
 * dominantHz is the frequency
 * dominantNote is the index of the note
 */
double PitchDetector::GetNoteDeviation(double dominantHz, int dominantNote) 
{
	double deviation, range;
	//the deviation between the ideal note and the actual frequency.
	//negative if the actual frequency is below the ideal note frequency
	deviation = dominantHz - noteFreq[dominantNote];
	if (dominantHz > noteFreq[dominantNote]) 
	{
		if (dominantNote == 119) return 0;
		//the range between the two notes surrounding the actual frequency
		range = noteFreq[dominantNote + 1] - noteFreq[dominantNote];
	} 
	else 
	{
		if (dominantNote == 0) return 0;
		range = noteFreq[dominantNote] - noteFreq[dominantNote - 1];
	}
	return deviation / range;
}

/* Turns a note (index into the note array) into the index of that note, where
 * A is 0 and G# is 11
 * TODO: this method was quick-fixed for an off by n error in Placeindicator
 */
int PitchDetector::NoteToIndex(int dominantNote) 
{
	const char *noteName = note[dominantNote];
	int noteIndex = (noteName[0] - 'A') * 2;
	if (noteName[1] == '#') noteIndex ++;
	return noteIndex;

/*	switch(noteName[0]) 
	{
	case 'A': noteIndex = 0; break;
	case 'B': noteIndex = 2; break;
	case 'C': noteIndex = 3; break;
	case 'D': noteIndex = 5; break;
	case 'E': noteIndex = 7; break;
	case 'F': noteIndex = 8; break;
	case 'G': noteIndex = 10; break;
	default: exit(-11);
	}
	if (noteName[1] == '#') noteIndex++;
	return noteIndex;
	*/
}

int PitchDetector::DetectPitch()
{
    FMOD::System          *system  = 0;
    FMOD::Sound           *sound   = 0;
    FMOD::Channel         *channel = 0;
    FMOD_RESULT            result;
    FMOD_CREATESOUNDEXINFO exinfo;
    int                    key, driver, recorddriver, numdrivers, count, bin;
    unsigned int           version;    
	
    /*
        Create a System object and initialize.
    */
    result = FMOD::System_Create(&system);
    ERRCHECK(result);

    result = system->getVersion(&version);
    ERRCHECK(result);

    if (version < FMOD_VERSION)
    {
        printf("Error!  You are using an old version of FMOD %08x.  This program requires %08x\n", version, FMOD_VERSION);
		return(-1);
    }

    /* 
        System initialization
    */
    printf("---------------------------------------------------------\n");    
    printf("Select OUTPUT type\n");    
    printf("---------------------------------------------------------\n");    
    printf("1 :  DirectSound\n");
    printf("2 :  Windows Multimedia WaveOut\n");
    printf("3 :  ASIO\n");
    printf("---------------------------------------------------------\n");
    printf("Press a corresponding number or ESC to quit\n");

    do
    {
        //key = _getch();
		key = '1'; //TODO: this uses the default io device rather than using user input
    } while (key != 27 && key < '1' && key > '5');
    
    switch (key)
    {
        case '1' :  result = system->setOutput(FMOD_OUTPUTTYPE_DSOUND);
                    break;
        case '2' :  result = system->setOutput(FMOD_OUTPUTTYPE_WINMM);
                    break;
        case '3' :  result = system->setOutput(FMOD_OUTPUTTYPE_ASIO);
                    break;
        default  :  return(0); 
    }  
    ERRCHECK(result);
    
    /*
        Enumerate playback devices
    */

    result = system->getNumDrivers(&numdrivers);
    ERRCHECK(result);

    printf("---------------------------------------------------------\n");    
    printf("Choose a PLAYBACK driver\n");
    printf("---------------------------------------------------------\n");    
    for (count=0; count < numdrivers; count++)
    {
        char name[256];

        result = system->getDriverInfo(count, name, 256, 0);
        ERRCHECK(result);

        printf("%d : %s\n", count + 1, name);
    }
    printf("---------------------------------------------------------\n");
    printf("Press a corresponding number or ESC to quit\n");

    do
    {
        //key = _getch();
		key = '1'; //TODO: io devices
        if (key == 27)
        {
            return(0);
        }
        driver = key - '1';
    } while (driver < 0 || driver >= numdrivers);

    result = system->setDriver(driver);
    ERRCHECK(result);

    /*
        Enumerate record devices
    */

    result = system->getRecordNumDrivers(&numdrivers);
    ERRCHECK(result);

    printf("---------------------------------------------------------\n");    
    printf("Choose a RECORD driver\n");
    printf("---------------------------------------------------------\n");    
    for (count=0; count < numdrivers; count++)
    {
        char name[256];

        result = system->getRecordDriverInfo(count, name, 256, 0);
        ERRCHECK(result);

        printf("%d : %s\n", count + 1, name);
    }
    printf("---------------------------------------------------------\n");
    printf("Press a corresponding number or ESC to quit\n");

    recorddriver = 0;
    do
    {
        //key = _getch();
		key = '1'; //TODO: io devices
        if (key == 27)
        {
            return(0);
        }
        recorddriver = key - '1';
    } while (recorddriver < 0 || recorddriver >= numdrivers);

    printf("\n");
 
    result = system->setSoftwareFormat(OUTPUT_RATE, FMOD_SOUND_FORMAT_PCM16, 1, 0, FMOD_DSP_RESAMPLER_LINEAR);
    ERRCHECK(result);

    result = system->init(32, FMOD_INIT_NORMAL, 0);
    ERRCHECK(result);

    /*
        Create a sound to record to.
    */
    memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));

    exinfo.cbsize           = sizeof(FMOD_CREATESOUNDEXINFO);
    exinfo.numchannels      = 1;
    exinfo.format           = FMOD_SOUND_FORMAT_PCM16;
    exinfo.defaultfrequency = OUTPUT_RATE;
    exinfo.length           = exinfo.defaultfrequency * sizeof(short) * exinfo.numchannels * 5;
    
    result = system->createSound(0, FMOD_2D | FMOD_SOFTWARE | FMOD_LOOP_NORMAL | FMOD_OPENUSER, &exinfo, &sound);
    ERRCHECK(result);

    /*
        Start the interface
    */
    printf("=========================================================================\n");
    printf("Pitch detection example.  Copyright (c) Firelight Technologies 2004-2011.\n");
    printf("=========================================================================\n");
    printf("\n");
    printf("Record something through the selected recording device and FMOD will\n");
    printf("Determine the pitch.  Sustain the tone for at least a second to get an\n");
    printf("accurate reading.\n");
    printf("Press 'Esc' to quit\n");
    printf("\n");

    result = system->recordStart(recorddriver, sound, true);
    ERRCHECK(result);
    
    Sleep(100);      /* Give it some time to record something */
    
    result = system->playSound(FMOD_CHANNEL_REUSE, sound, false, &channel);
    ERRCHECK(result);

    /* Dont hear what is being recorded otherwise it will feedback.  Spectrum analysis is done before volume scaling in the DSP chain */
    result = channel->setVolume(0);
    ERRCHECK(result);

    bin = 0;

    /*
        Main loop.
    */
    do
    {
        static float spectrum[SPECTRUM_SIZE];
        float       dominantHz = 0;
        float       max;
        int         dominantNote = 0;
        float       binSize = BIN_SIZE;
		bool		hasUpdated = false;
		char		windowTitle[sizeof("Pitch Detector: ---")] = "Pitch Detector: ---";
		int			noteIndex;
		double		noteDeviation;
		
        if (_kbhit())
        {
            key = _getch();
        }

        result = channel->getSpectrum(spectrum, SPECTRUM_SIZE, 0, FMOD_DSP_FFT_WINDOW_TRIANGLE);
        ERRCHECK(result);

        max = 0;

        for (count = 0; count < SPECTRUM_SIZE; count++)
        {
            if (spectrum[count] > 0.01f && spectrum[count] > max)
            {
                max = spectrum[count];
                bin = count;
				hasUpdated = true;
            }
        }        

        dominantHz  = (float)bin * BIN_SIZE;       /* dominant frequency min */

        dominantNote = 0;
        for (count = 0; count < 120; count++)
        {
             if (dominantHz >= noteFreq[count] && dominantHz < noteFreq[count + 1])
             {
                /* which is it closer to.  This note or the next note */
                if (fabs(dominantHz - noteFreq[count]) < fabs(dominantHz - noteFreq[count+1]))
                {
                    dominantNote = count;
                }
                else
                {
                    dominantNote = count + 1;
                }
                break;
             }
        }

        printf("Detected rate : %7.1f -> %7.1f hz.  Detected musical note. %-3s (%7.1f hz)\r", 
			dominantHz, ((float)bin + 0.99f) * BIN_SIZE, note[dominantNote], noteFreq[dominantNote]);

		// Sets the window title to Pitch Detector: (NOTE)(#|)([0-9]) \| (KEY_MAPPING)
		string noteStr = note[dominantNote];
		noteStr = noteStr[0];
		string keyMapping = " | " + mappingsInterface->GetBoxText(noteStr);
		strncpy(windowTitle + sizeof("Pitch Detector: ") - 1, note[dominantNote], 3);
		if (!hasUpdated) 
		{
			strncpy(windowTitle + sizeof("Pitch Detector: ") - 1, "---", 3);
			keyMapping = "";
		}
		string windowTitleStr = windowTitle;
		emit UpdateTitleSignal(QString((windowTitleStr + keyMapping).c_str()));

		// Sets the feedback of what note is being played
		if (!hasUpdated) 
		{
			noteIndex = -1;
			noteDeviation = 0;
		} 
		else
		{
			noteIndex = NoteToIndex(dominantNote);
			noteDeviation = GetNoteDeviation(dominantHz, dominantNote);
		}
		emit UpdateNoteDisplaySignal(noteIndex, noteDeviation);

        system->update();
        Sleep(10);
    } while (key != 27);

    printf("\n");

    /*
        Shut down
    */
    result = sound->release();
    ERRCHECK(result);

    result = system->release();
    ERRCHECK(result);
	return 0;
}
