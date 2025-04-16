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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QFormLayout *formLayout_4;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QRadioButton *radioButton;
    QPushButton *readFile;
    QTextEdit *itemsTextEdit;
    QPushButton *findByModel;
    QPushButton *AddButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(928, 548);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        formLayout_4->setWidget(3, QFormLayout::FieldRole, lineEdit_4);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_4->setWidget(4, QFormLayout::LabelRole, label_5);

        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        formLayout_4->setWidget(4, QFormLayout::FieldRole, lineEdit_5);

        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        formLayout_4->setWidget(5, QFormLayout::FieldRole, radioButton);


        formLayout->setLayout(1, QFormLayout::LabelRole, formLayout_4);

        readFile = new QPushButton(centralwidget);
        readFile->setObjectName(QString::fromUtf8("readFile"));

        formLayout->setWidget(1, QFormLayout::FieldRole, readFile);

        itemsTextEdit = new QTextEdit(centralwidget);
        itemsTextEdit->setObjectName(QString::fromUtf8("itemsTextEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, itemsTextEdit);

        findByModel = new QPushButton(centralwidget);
        findByModel->setObjectName(QString::fromUtf8("findByModel"));

        formLayout->setWidget(3, QFormLayout::FieldRole, findByModel);

        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));

        formLayout->setWidget(2, QFormLayout::LabelRole, AddButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 928, 21));
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
        label->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\270\320\267\320\264\320\265\320\273\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\244\320\270\321\200\320\274\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\320\260", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\273\320\270\321\207\320\270\320\265", nullptr));
        readFile->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\207\320\270\321\202\320\260\321\202\321\214 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        findByModel->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        AddButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
