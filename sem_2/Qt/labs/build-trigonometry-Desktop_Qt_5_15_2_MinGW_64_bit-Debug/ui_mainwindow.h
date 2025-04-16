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
#include <QtWidgets/QDoubleSpinBox>
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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QPushButton *cosButton;
    QLabel *label;
    QPushButton *sinButton;
    QPushButton *tgButton;
    QLabel *label_2;
    QSpinBox *gradspinBox;
    QDoubleSpinBox *radSpinBox;
    QLabel *resultLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(270, 160, 201, 88));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        cosButton = new QPushButton(gridLayoutWidget);
        cosButton->setObjectName(QString::fromUtf8("cosButton"));

        gridLayout->addWidget(cosButton, 1, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        sinButton = new QPushButton(gridLayoutWidget);
        sinButton->setObjectName(QString::fromUtf8("sinButton"));

        gridLayout->addWidget(sinButton, 0, 0, 1, 1);

        tgButton = new QPushButton(gridLayoutWidget);
        tgButton->setObjectName(QString::fromUtf8("tgButton"));

        gridLayout->addWidget(tgButton, 2, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        gradspinBox = new QSpinBox(gridLayoutWidget);
        gradspinBox->setObjectName(QString::fromUtf8("gradspinBox"));
        gradspinBox->setSingleStep(5);

        gridLayout->addWidget(gradspinBox, 0, 2, 1, 1);

        radSpinBox = new QDoubleSpinBox(gridLayoutWidget);
        radSpinBox->setObjectName(QString::fromUtf8("radSpinBox"));
        radSpinBox->setDecimals(6);
        radSpinBox->setSingleStep(0.087266000000000);

        gridLayout->addWidget(radSpinBox, 1, 2, 1, 1);

        resultLabel = new QLabel(gridLayoutWidget);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));

        gridLayout->addWidget(resultLabel, 2, 2, 1, 1);

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
        label_3->setText(QCoreApplication::translate("MainWindow", "result", nullptr));
        cosButton->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "grad", nullptr));
        sinButton->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        tgButton->setText(QCoreApplication::translate("MainWindow", "tg", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "rad", nullptr));
        resultLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
