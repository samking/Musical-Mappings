#pragma once
#include <QObject>
#include <string>
#include "mappingsinterface.h"
#include "feedbackwindow.h"
#include "indicator.h"
using namespace std;

class PitchDetector : public QObject
{
	Q_OBJECT

public:
	PitchDetector(MappingsInterface &mapWindow, Indicator &indicator, QObject *parent = 0);
	~PitchDetector(void);
	int DetectPitch();

private:
	double GetNoteDeviation(double dominantHz, int dominantNote);
	int NoteToIndex(int dominantNote);

signals:
	void UpdateTitleSignal(QString);
	void UpdateNoteDisplaySignal(int, double);

};
