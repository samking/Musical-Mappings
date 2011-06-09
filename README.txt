If you want to run our program, take the executable out of the Debug folder and run that.  You might need to have fmodex.dll in the same directory as it.  If there are any other weird dependencies, try going through the full install process described below.

This program uses FMOD Sound System by Firelight Technologies for its audio processing.  All of the FMOD stuff should be in fmodex.dll and in the pitch_api folder, but if it isn't, download it from http://www.fmod.org/
We use Win32 pthreads for threading.  I think that everything is statically compiled, but if it needs any dlls, then you probably will need to download pthreads from http://sources.redhat.com/pthreads-win32/ and put the dlls somewhere in your dll path.
If you want to continue development or compile it yourself, you will need to install visual studio 2008 (2005 might work; when we tried 2010, it broke everything; you could probably use MinGW and G++ also), the Qt plugin for visual studio, and Qt.  Then, you can double click on the .ui file in the visual studio project to open up the graphical Qt editor to change the user interface.  MOC, part of Qt, will turn the .ui file into source files when you compile.

Regardless of the above, you will need autohotkey installed to do anything.  Once you install autohotkey, when you run the .ahk file, it will respond to your musical mappings (as long as the above described executable is running).  What this file does is listen to the title of the window and send a keypress that is the same as whatever the window title tells it to do.

feedbackwindow contains the feedback window.
indicator has the indicator line on the feedback window.
mappingsinterface has the configuration window.
pitchdetector deals with the audio processing.
main starts everything.

We intend everything to be released under the GNU General Public License version 3.  Keep in mind that we use FMOD, which is only free for non-commercial applications.  Thus, unless you replace the FMOD code, you may not use our application for commercial applications.  All original code for this project was written by Sam King and Rachel Lopatin in 2011.