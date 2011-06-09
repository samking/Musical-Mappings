#ifndef FEEDBACKWINDOW_H
#define FEEDBACKWINDOW_H

#include <QMainWindow>

namespace Ui {
    class FeedbackWindow;
}

class FeedbackWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FeedbackWindow(QWidget *parent = 0);
    ~FeedbackWindow();

private:
    Ui::FeedbackWindow *ui;

};

#endif // FEEDBACKWINDOW_H
