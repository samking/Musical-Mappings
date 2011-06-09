/*===============================================================================================
 Pitch detection example code copyright (c), Firelight Technologies Pty, Ltd 2004-2011.

 This example combines recording with spectrum analysis to determine the pitch of the sound 
 being recorded.
===============================================================================================*/
#include "mappingsinterface.h"
#include "pitch_detector.h"
#include "feedbackwindow.h"
#include "indicator.h"
#include <QtGui/QApplication>
#include <pthread.h>

using namespace std;

pthread_t pitchDetectorThread;
pthread_t feedbackWindowThread;

void *PitchThreadFn (void *_detector) 
{
	PitchDetector *detector = (PitchDetector *)_detector;
	detector->DetectPitch();
	return NULL;
}

void *FeedbackWindowThreadFn (void *UNUSED)
{
	return NULL;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//Configuration window
	MappingsInterface mapWindow;
	mapWindow.show();

	//Feedback window
	//pthread_create(&feedbackWindowThread, NULL,
	//	FeedbackWindowThreadFn, NULL);
	FeedbackWindow feedbackWindow;
	feedbackWindow.show();
	QWidget* centralWidget = feedbackWindow.findChild<QWidget*>("centralWidget");
    Indicator indicator(centralWidget);

	PitchDetector detector(mapWindow, indicator);
	pthread_create(&pitchDetectorThread, NULL, 
		PitchThreadFn, &detector);


	a.exec();
	return 0;
}
