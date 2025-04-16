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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionset_center;
    QAction *actionset_radius;
    QAction *actionset_color;
    QWidget *centralwidget;
    QPushButton *speed_up;
    QPushButton *speed_down;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *set_radius;
    QLineEdit *lineEdit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *colorDialog;
    QComboBox *color;
    QMenuBar *menubar;
    QMenu *menumenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionset_center = new QAction(MainWindow);
        actionset_center->setObjectName(QString::fromUtf8("actionset_center"));
        actionset_radius = new QAction(MainWindow);
        actionset_radius->setObjectName(QString::fromUtf8("actionset_radius"));
        actionset_color = new QAction(MainWindow);
        actionset_color->setObjectName(QString::fromUtf8("actionset_color"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        speed_up = new QPushButton(centralwidget);
        speed_up->setObjectName(QString::fromUtf8("speed_up"));
        speed_up->setGeometry(QRect(20, 10, 75, 24));
        speed_down = new QPushButton(centralwidget);
        speed_down->setObjectName(QString::fromUtf8("speed_down"));
        speed_down->setGeometry(QRect(110, 10, 75, 24));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(470, 10, 216, 58));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        set_radius = new QPushButton(layoutWidget);
        set_radius->setObjectName(QString::fromUtf8("set_radius"));

        horizontalLayout->addWidget(set_radius);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(710, 10, 82, 56));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        colorDialog = new QPushButton(layoutWidget1);
        colorDialog->setObjectName(QString::fromUtf8("colorDialog"));

        verticalLayout->addWidget(colorDialog);

        color = new QComboBox(layoutWidget1);
        color->addItem(QString());
        color->addItem(QString());
        color->addItem(QString());
        color->addItem(QString());
        color->addItem(QString());
        color->setObjectName(QString::fromUtf8("color"));

        verticalLayout->addWidget(color);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menumenu = new QMenu(menubar);
        menumenu->setObjectName(QString::fromUtf8("menumenu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menumenu->menuAction());
        menumenu->addAction(actionset_center);
        menumenu->addAction(actionset_radius);
        menumenu->addAction(actionset_color);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionset_center->setText(QCoreApplication::translate("MainWindow", "set center", nullptr));
        actionset_radius->setText(QCoreApplication::translate("MainWindow", "set radius", nullptr));
        actionset_color->setText(QCoreApplication::translate("MainWindow", "set color", nullptr));
        speed_up->setText(QCoreApplication::translate("MainWindow", "speed+", nullptr));
        speed_down->setText(QCoreApplication::translate("MainWindow", "speed-", nullptr));
        set_radius->setText(QCoreApplication::translate("MainWindow", "set radius", nullptr));
        colorDialog->setText(QCoreApplication::translate("MainWindow", "palette", nullptr));
        color->setItemText(0, QCoreApplication::translate("MainWindow", "red", nullptr));
        color->setItemText(1, QCoreApplication::translate("MainWindow", "green", nullptr));
        color->setItemText(2, QCoreApplication::translate("MainWindow", "blue", nullptr));
        color->setItemText(3, QCoreApplication::translate("MainWindow", "yellow", nullptr));
        color->setItemText(4, QCoreApplication::translate("MainWindow", "black", nullptr));

        menumenu->setTitle(QCoreApplication::translate("MainWindow", "menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
