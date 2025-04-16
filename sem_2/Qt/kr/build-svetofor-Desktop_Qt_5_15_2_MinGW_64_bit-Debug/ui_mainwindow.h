/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *redButton;
    QPushButton *yellowButton;
    QPushButton *startButton;
    QPushButton *greenButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *yellowBox;
    QSpinBox *greenBox;
    QLabel *label_3;
    QSpinBox *redBox;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_10;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 30, 151, 381));
        label->setStyleSheet(QString::fromUtf8("background: black"));
        redButton = new QPushButton(centralwidget);
        redButton->setObjectName(QString::fromUtf8("redButton"));
        redButton->setGeometry(QRect(340, 50, 101, 101));
        redButton->setStyleSheet(QString::fromUtf8("border-radius: 50%;\n"
"background: white"));
        yellowButton = new QPushButton(centralwidget);
        yellowButton->setObjectName(QString::fromUtf8("yellowButton"));
        yellowButton->setGeometry(QRect(340, 170, 101, 101));
        yellowButton->setStyleSheet(QString::fromUtf8("border-radius: 50%;\n"
"background: white"));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(40, 150, 80, 24));
        greenButton = new QPushButton(centralwidget);
        greenButton->setObjectName(QString::fromUtf8("greenButton"));
        greenButton->setGeometry(QRect(340, 290, 101, 101));
        greenButton->setStyleSheet(QString::fromUtf8("border-radius: 50%;\n"
"background: white"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 200, 160, 111));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        yellowBox = new QSpinBox(gridLayoutWidget);
        yellowBox->setObjectName(QString::fromUtf8("yellowBox"));
        yellowBox->setMaximum(499);
        yellowBox->setSingleStep(10);

        gridLayout->addWidget(yellowBox, 2, 1, 1, 1);

        greenBox = new QSpinBox(gridLayoutWidget);
        greenBox->setObjectName(QString::fromUtf8("greenBox"));
        greenBox->setMaximum(499);
        greenBox->setSingleStep(10);

        gridLayout->addWidget(greenBox, 3, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        redBox = new QSpinBox(gridLayoutWidget);
        redBox->setObjectName(QString::fromUtf8("redBox"));
        redBox->setMaximum(499);
        redBox->setSingleStep(10);

        gridLayout->addWidget(redBox, 1, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 2);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(340, 50, 16, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(330, 60, 16, 21));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(330, 120, 16, 21));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(340, 140, 16, 20));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(430, 50, 16, 20));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(420, 40, 16, 20));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(440, 110, 20, 41));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(430, 129, 21, 31));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(410, 140, 16, 20));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(340, 170, 16, 20));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(340, 160, 31, 16));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(330, 170, 16, 31));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(430, 170, 16, 20));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(410, 160, 31, 16));
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(440, 170, 16, 31));
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(340, 250, 16, 20));
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(330, 240, 16, 31));
        label_23 = new QLabel(centralwidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(340, 260, 31, 16));
        label_24 = new QLabel(centralwidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(430, 250, 16, 20));
        label_25 = new QLabel(centralwidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(440, 240, 16, 31));
        label_26 = new QLabel(centralwidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(410, 260, 31, 16));
        label_27 = new QLabel(centralwidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(340, 290, 16, 20));
        label_28 = new QLabel(centralwidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(340, 280, 31, 16));
        label_29 = new QLabel(centralwidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(330, 300, 16, 31));
        label_30 = new QLabel(centralwidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(410, 280, 41, 16));
        label_31 = new QLabel(centralwidget);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(440, 300, 16, 41));
        label_32 = new QLabel(centralwidget);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(430, 290, 16, 20));
        label_33 = new QLabel(centralwidget);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(440, 340, 16, 41));
        label_34 = new QLabel(centralwidget);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(410, 380, 31, 16));
        label_35 = new QLabel(centralwidget);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(430, 370, 16, 20));
        label_36 = new QLabel(centralwidget);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(330, 350, 16, 41));
        label_37 = new QLabel(centralwidget);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(340, 380, 31, 20));
        label_38 = new QLabel(centralwidget);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(340, 370, 16, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        redButton->setText(QString());
        yellowButton->setText(QString());
        startButton->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        greenButton->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "yellow speed", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "green speed", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "red speed", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "set speed", nullptr));
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label_10->setText(QString());
        label_14->setText(QString());
        label_15->setText(QString());
        label_16->setText(QString());
        label_17->setText(QString());
        label_18->setText(QString());
        label_19->setText(QString());
        label_20->setText(QString());
        label_21->setText(QString());
        label_22->setText(QString());
        label_23->setText(QString());
        label_24->setText(QString());
        label_25->setText(QString());
        label_26->setText(QString());
        label_27->setText(QString());
        label_28->setText(QString());
        label_29->setText(QString());
        label_30->setText(QString());
        label_31->setText(QString());
        label_32->setText(QString());
        label_33->setText(QString());
        label_34->setText(QString());
        label_35->setText(QString());
        label_36->setText(QString());
        label_37->setText(QString());
        label_38->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
