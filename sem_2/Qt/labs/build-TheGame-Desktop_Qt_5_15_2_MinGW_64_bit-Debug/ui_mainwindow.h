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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gameField;
    QPushButton *pushButton_22;
    QPushButton *pushButton_41;
    QPushButton *pushButton_35;
    QPushButton *pushButton_33;
    QPushButton *pushButton_15;
    QPushButton *pushButton_54;
    QPushButton *pushButton_24;
    QPushButton *pushButton_53;
    QPushButton *pushButton_25;
    QPushButton *pushButton_32;
    QPushButton *pushButton_45;
    QPushButton *pushButton_13;
    QPushButton *pushButton_52;
    QPushButton *pushButton_11;
    QPushButton *pushButton_34;
    QPushButton *pushButton_55;
    QPushButton *pushButton_51;
    QPushButton *pushButton_42;
    QPushButton *pushButton_23;
    QPushButton *pushButton_44;
    QPushButton *pushButton_12;
    QPushButton *pushButton_43;
    QPushButton *pushButton_31;
    QPushButton *pushButton_21;
    QPushButton *pushButton_14;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *clearButton;
    QPushButton *checkButton;
    QPushButton *hideButton;
    QPushButton *startButton;
    QLabel *label;
    QLabel *levelLabel;
    QLabel *winLabel;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(200, 10, 510, 381));
        gameField = new QGridLayout(gridLayoutWidget);
        gameField->setObjectName(QString::fromUtf8("gameField"));
        gameField->setContentsMargins(0, 0, 0, 0);
        pushButton_22 = new QPushButton(gridLayoutWidget);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_22->sizePolicy().hasHeightForWidth());
        pushButton_22->setSizePolicy(sizePolicy);
        pushButton_22->setCheckable(false);

        gameField->addWidget(pushButton_22, 1, 1, 1, 1);

        pushButton_41 = new QPushButton(gridLayoutWidget);
        pushButton_41->setObjectName(QString::fromUtf8("pushButton_41"));
        sizePolicy.setHeightForWidth(pushButton_41->sizePolicy().hasHeightForWidth());
        pushButton_41->setSizePolicy(sizePolicy);
        pushButton_41->setCheckable(false);

        gameField->addWidget(pushButton_41, 3, 0, 1, 1);

        pushButton_35 = new QPushButton(gridLayoutWidget);
        pushButton_35->setObjectName(QString::fromUtf8("pushButton_35"));
        sizePolicy.setHeightForWidth(pushButton_35->sizePolicy().hasHeightForWidth());
        pushButton_35->setSizePolicy(sizePolicy);
        pushButton_35->setCheckable(false);

        gameField->addWidget(pushButton_35, 2, 4, 1, 1);

        pushButton_33 = new QPushButton(gridLayoutWidget);
        pushButton_33->setObjectName(QString::fromUtf8("pushButton_33"));
        pushButton_33->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_33->sizePolicy().hasHeightForWidth());
        pushButton_33->setSizePolicy(sizePolicy);
        pushButton_33->setCheckable(false);

        gameField->addWidget(pushButton_33, 2, 2, 1, 1);

        pushButton_15 = new QPushButton(gridLayoutWidget);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        sizePolicy.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy);
        pushButton_15->setMinimumSize(QSize(0, 24));
        pushButton_15->setCheckable(false);

        gameField->addWidget(pushButton_15, 0, 4, 1, 1);

        pushButton_54 = new QPushButton(gridLayoutWidget);
        pushButton_54->setObjectName(QString::fromUtf8("pushButton_54"));
        sizePolicy.setHeightForWidth(pushButton_54->sizePolicy().hasHeightForWidth());
        pushButton_54->setSizePolicy(sizePolicy);
        pushButton_54->setCheckable(false);

        gameField->addWidget(pushButton_54, 4, 3, 1, 1);

        pushButton_24 = new QPushButton(gridLayoutWidget);
        pushButton_24->setObjectName(QString::fromUtf8("pushButton_24"));
        sizePolicy.setHeightForWidth(pushButton_24->sizePolicy().hasHeightForWidth());
        pushButton_24->setSizePolicy(sizePolicy);
        pushButton_24->setCheckable(false);

        gameField->addWidget(pushButton_24, 1, 3, 1, 1);

        pushButton_53 = new QPushButton(gridLayoutWidget);
        pushButton_53->setObjectName(QString::fromUtf8("pushButton_53"));
        sizePolicy.setHeightForWidth(pushButton_53->sizePolicy().hasHeightForWidth());
        pushButton_53->setSizePolicy(sizePolicy);
        pushButton_53->setCheckable(false);

        gameField->addWidget(pushButton_53, 4, 2, 1, 1);

        pushButton_25 = new QPushButton(gridLayoutWidget);
        pushButton_25->setObjectName(QString::fromUtf8("pushButton_25"));
        sizePolicy.setHeightForWidth(pushButton_25->sizePolicy().hasHeightForWidth());
        pushButton_25->setSizePolicy(sizePolicy);
        pushButton_25->setCheckable(false);

        gameField->addWidget(pushButton_25, 1, 4, 1, 1);

        pushButton_32 = new QPushButton(gridLayoutWidget);
        pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));
        sizePolicy.setHeightForWidth(pushButton_32->sizePolicy().hasHeightForWidth());
        pushButton_32->setSizePolicy(sizePolicy);
        pushButton_32->setCheckable(false);

        gameField->addWidget(pushButton_32, 2, 1, 1, 1);

        pushButton_45 = new QPushButton(gridLayoutWidget);
        pushButton_45->setObjectName(QString::fromUtf8("pushButton_45"));
        sizePolicy.setHeightForWidth(pushButton_45->sizePolicy().hasHeightForWidth());
        pushButton_45->setSizePolicy(sizePolicy);
        pushButton_45->setCheckable(false);

        gameField->addWidget(pushButton_45, 3, 4, 1, 1);

        pushButton_13 = new QPushButton(gridLayoutWidget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        sizePolicy.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy);
        pushButton_13->setMinimumSize(QSize(0, 24));
        pushButton_13->setCheckable(false);

        gameField->addWidget(pushButton_13, 0, 2, 1, 1);

        pushButton_52 = new QPushButton(gridLayoutWidget);
        pushButton_52->setObjectName(QString::fromUtf8("pushButton_52"));
        sizePolicy.setHeightForWidth(pushButton_52->sizePolicy().hasHeightForWidth());
        pushButton_52->setSizePolicy(sizePolicy);
        pushButton_52->setCheckable(false);

        gameField->addWidget(pushButton_52, 4, 1, 1, 1);

        pushButton_11 = new QPushButton(gridLayoutWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        sizePolicy.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy);
        pushButton_11->setCheckable(false);

        gameField->addWidget(pushButton_11, 0, 0, 1, 1);

        pushButton_34 = new QPushButton(gridLayoutWidget);
        pushButton_34->setObjectName(QString::fromUtf8("pushButton_34"));
        sizePolicy.setHeightForWidth(pushButton_34->sizePolicy().hasHeightForWidth());
        pushButton_34->setSizePolicy(sizePolicy);
        pushButton_34->setCheckable(false);

        gameField->addWidget(pushButton_34, 2, 3, 1, 1);

        pushButton_55 = new QPushButton(gridLayoutWidget);
        pushButton_55->setObjectName(QString::fromUtf8("pushButton_55"));
        sizePolicy.setHeightForWidth(pushButton_55->sizePolicy().hasHeightForWidth());
        pushButton_55->setSizePolicy(sizePolicy);
        pushButton_55->setCheckable(false);
        pushButton_55->setFlat(false);

        gameField->addWidget(pushButton_55, 4, 4, 1, 1);

        pushButton_51 = new QPushButton(gridLayoutWidget);
        pushButton_51->setObjectName(QString::fromUtf8("pushButton_51"));
        sizePolicy.setHeightForWidth(pushButton_51->sizePolicy().hasHeightForWidth());
        pushButton_51->setSizePolicy(sizePolicy);
        pushButton_51->setCheckable(false);

        gameField->addWidget(pushButton_51, 4, 0, 1, 1);

        pushButton_42 = new QPushButton(gridLayoutWidget);
        pushButton_42->setObjectName(QString::fromUtf8("pushButton_42"));
        sizePolicy.setHeightForWidth(pushButton_42->sizePolicy().hasHeightForWidth());
        pushButton_42->setSizePolicy(sizePolicy);
        pushButton_42->setCheckable(false);

        gameField->addWidget(pushButton_42, 3, 1, 1, 1);

        pushButton_23 = new QPushButton(gridLayoutWidget);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));
        sizePolicy.setHeightForWidth(pushButton_23->sizePolicy().hasHeightForWidth());
        pushButton_23->setSizePolicy(sizePolicy);
        pushButton_23->setCheckable(false);

        gameField->addWidget(pushButton_23, 1, 2, 1, 1);

        pushButton_44 = new QPushButton(gridLayoutWidget);
        pushButton_44->setObjectName(QString::fromUtf8("pushButton_44"));
        sizePolicy.setHeightForWidth(pushButton_44->sizePolicy().hasHeightForWidth());
        pushButton_44->setSizePolicy(sizePolicy);
        pushButton_44->setCheckable(false);

        gameField->addWidget(pushButton_44, 3, 3, 1, 1);

        pushButton_12 = new QPushButton(gridLayoutWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        sizePolicy.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy);
        pushButton_12->setMinimumSize(QSize(0, 24));
        pushButton_12->setCheckable(false);

        gameField->addWidget(pushButton_12, 0, 1, 1, 1);

        pushButton_43 = new QPushButton(gridLayoutWidget);
        pushButton_43->setObjectName(QString::fromUtf8("pushButton_43"));
        sizePolicy.setHeightForWidth(pushButton_43->sizePolicy().hasHeightForWidth());
        pushButton_43->setSizePolicy(sizePolicy);
        pushButton_43->setCheckable(false);

        gameField->addWidget(pushButton_43, 3, 2, 1, 1);

        pushButton_31 = new QPushButton(gridLayoutWidget);
        pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));
        sizePolicy.setHeightForWidth(pushButton_31->sizePolicy().hasHeightForWidth());
        pushButton_31->setSizePolicy(sizePolicy);
        pushButton_31->setCheckable(false);

        gameField->addWidget(pushButton_31, 2, 0, 1, 1);

        pushButton_21 = new QPushButton(gridLayoutWidget);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        sizePolicy.setHeightForWidth(pushButton_21->sizePolicy().hasHeightForWidth());
        pushButton_21->setSizePolicy(sizePolicy);
        pushButton_21->setMinimumSize(QSize(0, 24));
        pushButton_21->setCheckable(false);

        gameField->addWidget(pushButton_21, 1, 0, 1, 1);

        pushButton_14 = new QPushButton(gridLayoutWidget);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        sizePolicy.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy);
        pushButton_14->setMinimumSize(QSize(0, 24));
        pushButton_14->setCheckable(false);

        gameField->addWidget(pushButton_14, 0, 3, 1, 1);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(200, 400, 511, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        clearButton = new QPushButton(horizontalLayoutWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        horizontalLayout->addWidget(clearButton);

        checkButton = new QPushButton(horizontalLayoutWidget);
        checkButton->setObjectName(QString::fromUtf8("checkButton"));

        horizontalLayout->addWidget(checkButton);

        hideButton = new QPushButton(horizontalLayoutWidget);
        hideButton->setObjectName(QString::fromUtf8("hideButton"));

        horizontalLayout->addWidget(hideButton);

        startButton = new QPushButton(horizontalLayoutWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        horizontalLayout->addWidget(startButton);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(28, 510, 281, 41));
        QFont font;
        font.setPointSize(20);
        font.setItalic(true);
        label->setFont(font);
        levelLabel = new QLabel(centralwidget);
        levelLabel->setObjectName(QString::fromUtf8("levelLabel"));
        levelLabel->setGeometry(QRect(50, 60, 121, 16));
        winLabel = new QLabel(centralwidget);
        winLabel->setObjectName(QString::fromUtf8("winLabel"));
        winLabel->setGeometry(QRect(10, 110, 181, 151));
        QFont font1;
        font1.setPointSize(28);
        winLabel->setFont(font1);
        winLabel->setAlignment(Qt::AlignCenter);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(360, 460, 201, 91));
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
        pushButton_22->setText(QString());
        pushButton_41->setText(QString());
        pushButton_35->setText(QString());
        pushButton_33->setText(QString());
        pushButton_15->setText(QString());
        pushButton_54->setText(QString());
        pushButton_24->setText(QString());
        pushButton_53->setText(QString());
        pushButton_25->setText(QString());
        pushButton_32->setText(QString());
        pushButton_45->setText(QString());
        pushButton_13->setText(QString());
        pushButton_52->setText(QString());
        pushButton_11->setText(QString());
        pushButton_34->setText(QString());
        pushButton_55->setText(QString());
        pushButton_51->setText(QString());
        pushButton_42->setText(QString());
        pushButton_23->setText(QString());
        pushButton_44->setText(QString());
        pushButton_12->setText(QString());
        pushButton_43->setText(QString());
        pushButton_31->setText(QString());
        pushButton_21->setText(QString());
        pushButton_14->setText(QString());
        clearButton->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        checkButton->setText(QCoreApplication::translate("MainWindow", "check", nullptr));
        hideButton->setText(QCoreApplication::translate("MainWindow", "hide", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        label->setText(QString());
        levelLabel->setText(QString());
        winLabel->setText(QString());
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Press &quot;start&quot; to begin</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Press &quot;hide&quot; to enter your answer</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Press &quot;check&quot; to check your answer</p>\n"
"<p style=\" marg"
                        "in-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Press &quot;clear&quot; to delete your answer</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Press &quot;next&quot; to go to next level</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
