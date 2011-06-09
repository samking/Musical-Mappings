#include "feedbackwindow.h"
#include "ui_feedbackwindow.h"

FeedbackWindow::FeedbackWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FeedbackWindow)
{
    ui->setupUi(this);
}

FeedbackWindow::~FeedbackWindow()
{
    delete ui;
}
