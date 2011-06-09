/********************************************************************************
** Form generated from reading UI file 'mappingsinterface.ui'
**
** Created: Fri Jun 3 11:20:46 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPPINGSINTERFACE_H
#define UI_MAPPINGSINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MappingsInterface
{
public:
    QWidget *mappingWindow;
    QVBoxLayout *verticalLayout_2;
    QLabel *instructions;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *A_label;
    QLineEdit *A_input;
    QHBoxLayout *horizontalLayout_2;
    QLabel *B_label;
    QLineEdit *B_input;
    QHBoxLayout *horizontalLayout_3;
    QLabel *C_label;
    QLineEdit *C_input;
    QHBoxLayout *horizontalLayout_4;
    QLabel *D_label;
    QLineEdit *D_input;
    QHBoxLayout *horizontalLayout_5;
    QLabel *E_label;
    QLineEdit *E_input;
    QHBoxLayout *horizontalLayout_6;
    QLabel *F_label;
    QLineEdit *F_input;
    QHBoxLayout *horizontalLayout_7;
    QLabel *G_label;
    QLineEdit *G_input;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MappingsInterface)
    {
        if (MappingsInterface->objectName().isEmpty())
            MappingsInterface->setObjectName(QString::fromUtf8("MappingsInterface"));
        MappingsInterface->resize(380, 390);
        mappingWindow = new QWidget(MappingsInterface);
        mappingWindow->setObjectName(QString::fromUtf8("mappingWindow"));
        verticalLayout_2 = new QVBoxLayout(mappingWindow);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        instructions = new QLabel(mappingWindow);
        instructions->setObjectName(QString::fromUtf8("instructions"));
        QFont font;
        font.setPointSize(11);
        instructions->setFont(font);
        instructions->setWordWrap(true);

        verticalLayout_2->addWidget(instructions);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        A_label = new QLabel(mappingWindow);
        A_label->setObjectName(QString::fromUtf8("A_label"));
        QFont font1;
        font1.setPointSize(16);
        A_label->setFont(font1);

        horizontalLayout->addWidget(A_label);

        A_input = new QLineEdit(mappingWindow);
        A_input->setObjectName(QString::fromUtf8("A_input"));

        horizontalLayout->addWidget(A_input);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        B_label = new QLabel(mappingWindow);
        B_label->setObjectName(QString::fromUtf8("B_label"));
        B_label->setFont(font1);

        horizontalLayout_2->addWidget(B_label);

        B_input = new QLineEdit(mappingWindow);
        B_input->setObjectName(QString::fromUtf8("B_input"));

        horizontalLayout_2->addWidget(B_input);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        C_label = new QLabel(mappingWindow);
        C_label->setObjectName(QString::fromUtf8("C_label"));
        C_label->setFont(font1);

        horizontalLayout_3->addWidget(C_label);

        C_input = new QLineEdit(mappingWindow);
        C_input->setObjectName(QString::fromUtf8("C_input"));

        horizontalLayout_3->addWidget(C_input);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        D_label = new QLabel(mappingWindow);
        D_label->setObjectName(QString::fromUtf8("D_label"));
        D_label->setFont(font1);

        horizontalLayout_4->addWidget(D_label);

        D_input = new QLineEdit(mappingWindow);
        D_input->setObjectName(QString::fromUtf8("D_input"));

        horizontalLayout_4->addWidget(D_input);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        E_label = new QLabel(mappingWindow);
        E_label->setObjectName(QString::fromUtf8("E_label"));
        E_label->setFont(font1);

        horizontalLayout_5->addWidget(E_label);

        E_input = new QLineEdit(mappingWindow);
        E_input->setObjectName(QString::fromUtf8("E_input"));

        horizontalLayout_5->addWidget(E_input);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        F_label = new QLabel(mappingWindow);
        F_label->setObjectName(QString::fromUtf8("F_label"));
        F_label->setFont(font1);

        horizontalLayout_6->addWidget(F_label);

        F_input = new QLineEdit(mappingWindow);
        F_input->setObjectName(QString::fromUtf8("F_input"));

        horizontalLayout_6->addWidget(F_input);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        G_label = new QLabel(mappingWindow);
        G_label->setObjectName(QString::fromUtf8("G_label"));
        G_label->setFont(font1);

        horizontalLayout_7->addWidget(G_label);

        G_input = new QLineEdit(mappingWindow);
        G_input->setObjectName(QString::fromUtf8("G_input"));

        horizontalLayout_7->addWidget(G_input);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_2->addLayout(verticalLayout);

        MappingsInterface->setCentralWidget(mappingWindow);
        menuBar = new QMenuBar(MappingsInterface);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 380, 26));
        MappingsInterface->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MappingsInterface);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MappingsInterface->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MappingsInterface);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MappingsInterface->setStatusBar(statusBar);

        retranslateUi(MappingsInterface);

        QMetaObject::connectSlotsByName(MappingsInterface);
    } // setupUi

    void retranslateUi(QMainWindow *MappingsInterface)
    {
        MappingsInterface->setWindowTitle(QApplication::translate("MappingsInterface", "MusicalMappings", 0, QApplication::UnicodeUTF8));
        instructions->setText(QApplication::translate("MappingsInterface", "Press your preferred keyboard control in the box next to the note you want to play for it:", 0, QApplication::UnicodeUTF8));
        A_label->setText(QApplication::translate("MappingsInterface", "A:", 0, QApplication::UnicodeUTF8));
        B_label->setText(QApplication::translate("MappingsInterface", "B:", 0, QApplication::UnicodeUTF8));
        C_label->setText(QApplication::translate("MappingsInterface", "C:", 0, QApplication::UnicodeUTF8));
        D_label->setText(QApplication::translate("MappingsInterface", "D:", 0, QApplication::UnicodeUTF8));
        E_label->setText(QApplication::translate("MappingsInterface", "E:", 0, QApplication::UnicodeUTF8));
        F_label->setText(QApplication::translate("MappingsInterface", "F:", 0, QApplication::UnicodeUTF8));
        G_label->setText(QApplication::translate("MappingsInterface", "G:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MappingsInterface: public Ui_MappingsInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPPINGSINTERFACE_H
