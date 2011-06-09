#ifndef INDICATOR_H
#define INDICATOR_H

#include <QWidget>
#include <QLabel>

class Indicator : public QWidget
{
    Q_OBJECT
public:
    explicit Indicator(QWidget *parent = 0);
    QFrame* line;
    QLabel* label;

signals:

public slots:
    void PlaceIndicator(int note, double distance);

};

#endif // INDICATOR_H
