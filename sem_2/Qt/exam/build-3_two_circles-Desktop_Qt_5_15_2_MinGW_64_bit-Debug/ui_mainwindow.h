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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *rad2_lineEdit;
    QLabel *label_2;
    QLabel *isCrossLabel;
    QComboBox *rad2_comboBox;
    QComboBox *rad1_comboBox;
    QLineEdit *rad1_lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(120, 130, 181, 144));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        rad2_lineEdit = new QLineEdit(formLayoutWidget);
        rad2_lineEdit->setObjectName(QString::fromUtf8("rad2_lineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, rad2_lineEdit);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        isCrossLabel = new QLabel(formLayoutWidget);
        isCrossLabel->setObjectName(QString::fromUtf8("isCrossLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, isCrossLabel);

        rad2_comboBox = new QComboBox(formLayoutWidget);
        rad2_comboBox->addItem(QString());
        rad2_comboBox->addItem(QString());
        rad2_comboBox->addItem(QString());
        rad2_comboBox->addItem(QString());
        rad2_comboBox->addItem(QString());
        rad2_comboBox->addItem(QString());
        rad2_comboBox->addItem(QString());
        rad2_comboBox->setObjectName(QString::fromUtf8("rad2_comboBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, rad2_comboBox);

        rad1_comboBox = new QComboBox(formLayoutWidget);
        rad1_comboBox->addItem(QString());
        rad1_comboBox->addItem(QString());
        rad1_comboBox->addItem(QString());
        rad1_comboBox->addItem(QString());
        rad1_comboBox->addItem(QString());
        rad1_comboBox->addItem(QString());
        rad1_comboBox->addItem(QString());
        rad1_comboBox->setObjectName(QString::fromUtf8("rad1_comboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, rad1_comboBox);

        rad1_lineEdit = new QLineEdit(formLayoutWidget);
        rad1_lineEdit->setObjectName(QString::fromUtf8("rad1_lineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, rad1_lineEdit);

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
        label->setText(QCoreApplication::translate("MainWindow", "radius 1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "radius 2", nullptr));
        isCrossLabel->setText(QString());
        rad2_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        rad2_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "50", nullptr));
        rad2_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "100", nullptr));
        rad2_comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "150", nullptr));
        rad2_comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "200", nullptr));
        rad2_comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "250", nullptr));
        rad2_comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "300", nullptr));

        rad1_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        rad1_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "50", nullptr));
        rad1_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "100", nullptr));
        rad1_comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "150", nullptr));
        rad1_comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "200", nullptr));
        rad1_comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "250", nullptr));
        rad1_comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "300", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
