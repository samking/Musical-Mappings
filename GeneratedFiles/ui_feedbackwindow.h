/********************************************************************************
** Form generated from reading UI file 'feedbackwindow.ui'
**
** Created: Fri Jun 3 11:20:47 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEEDBACKWINDOW_H
#define UI_FEEDBACKWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FeedbackWindow
{
public:
    QWidget *centralWidget;
    QFrame *line;
    QLabel *label;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FeedbackWindow)
    {
        if (FeedbackWindow->objectName().isEmpty())
            FeedbackWindow->setObjectName(QString::fromUtf8("FeedbackWindow"));
        FeedbackWindow->resize(371, 91);
        centralWidget = new QWidget(FeedbackWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 20, 350, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 16, 16));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(30, 20, 2, 16));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(80, 20, 2, 16));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(130, 20, 2, 16));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(230, 20, 2, 16));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(180, 20, 2, 16));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(centralWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(280, 20, 2, 16));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(centralWidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(330, 20, 2, 16));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 40, 16, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 40, 16, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 40, 16, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(230, 40, 16, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(280, 40, 16, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(330, 40, 16, 16));
        FeedbackWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FeedbackWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        FeedbackWindow->setStatusBar(statusBar);

        retranslateUi(FeedbackWindow);

        QMetaObject::connectSlotsByName(FeedbackWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FeedbackWindow)
    {
        FeedbackWindow->setWindowTitle(QApplication::translate("FeedbackWindow", "FeedbackWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FeedbackWindow", "A", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FeedbackWindow", "B", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FeedbackWindow", "C", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FeedbackWindow", "D", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("FeedbackWindow", "E", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("FeedbackWindow", "F", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("FeedbackWindow", "G", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FeedbackWindow: public Ui_FeedbackWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEEDBACKWINDOW_H
