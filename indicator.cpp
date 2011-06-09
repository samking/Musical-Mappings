#include "indicator.h"
#include "feedbackwindow.h"
#include <QPoint>

#define INCREMENT 25
#define START_X 23
#define START_Y 20
#define LABEL_Y 0
#define INDICATOR_WIDTH 2
#define INDICATOR_HEIGHT 32
#define LABEL_PADDING 10


Indicator::Indicator(QWidget *parent) :
    QWidget(parent)
{
    line = new QFrame(parent);
    label = new QLabel(parent);
}

void Indicator::PlaceIndicator(int note, double distance)
{
	if (note == -1) return;

    //to place the vertical line
    line->setGeometry(QRect(START_X + INCREMENT * note + distance * INCREMENT, START_Y, INDICATOR_WIDTH, INDICATOR_HEIGHT));
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Plain);
    line->setLineWidth(3);
    line->show();

    label->setText(QString("YOU"));
    label->setLineWidth(3);
    QPoint* qpoint = new QPoint(START_X + INCREMENT * note + distance * INCREMENT - LABEL_PADDING, LABEL_Y);
    label->move(*qpoint);
    label->show();
}
