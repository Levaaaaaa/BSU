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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *outputEdit;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_2;
    QLabel *surnameLabel;
    QLineEdit *surnameEdit;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *patronymicLabel;
    QLineEdit *patronymicEdit;
    QLabel *ageLabel;
    QSpinBox *ageBox;
    QLabel *sexLabel;
    QRadioButton *maleRadioButton;
    QLabel *label_6;
    QRadioButton *femaleRadioButton;
    QLabel *diagnosiLabel;
    QTextEdit *diagnosisEdit;
    QPushButton *readFromFileButton;
    QPushButton *findBy;
    QLabel *noReading;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout;
    QPushButton *show;
    QRadioButton *isAllPatients;
    QRadioButton *withoutWard;
    QComboBox *chooseCriteria;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QComboBox *deleteBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(634, 444);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        outputEdit = new QTextEdit(centralwidget);
        outputEdit->setObjectName(QString::fromUtf8("outputEdit"));
        outputEdit->setGeometry(QRect(240, 40, 371, 291));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 211, 279));
        formLayout_2 = new QFormLayout(formLayoutWidget);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        surnameLabel = new QLabel(formLayoutWidget);
        surnameLabel->setObjectName(QString::fromUtf8("surnameLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, surnameLabel);

        surnameEdit = new QLineEdit(formLayoutWidget);
        surnameEdit->setObjectName(QString::fromUtf8("surnameEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, surnameEdit);

        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, nameLabel);

        nameEdit = new QLineEdit(formLayoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, nameEdit);

        patronymicLabel = new QLabel(formLayoutWidget);
        patronymicLabel->setObjectName(QString::fromUtf8("patronymicLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, patronymicLabel);

        patronymicEdit = new QLineEdit(formLayoutWidget);
        patronymicEdit->setObjectName(QString::fromUtf8("patronymicEdit"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, patronymicEdit);

        ageLabel = new QLabel(formLayoutWidget);
        ageLabel->setObjectName(QString::fromUtf8("ageLabel"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, ageLabel);

        ageBox = new QSpinBox(formLayoutWidget);
        ageBox->setObjectName(QString::fromUtf8("ageBox"));
        ageBox->setMaximum(110);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, ageBox);

        sexLabel = new QLabel(formLayoutWidget);
        sexLabel->setObjectName(QString::fromUtf8("sexLabel"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, sexLabel);

        maleRadioButton = new QRadioButton(formLayoutWidget);
        maleRadioButton->setObjectName(QString::fromUtf8("maleRadioButton"));
        maleRadioButton->setChecked(true);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, maleRadioButton);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_6);

        femaleRadioButton = new QRadioButton(formLayoutWidget);
        femaleRadioButton->setObjectName(QString::fromUtf8("femaleRadioButton"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, femaleRadioButton);

        diagnosiLabel = new QLabel(formLayoutWidget);
        diagnosiLabel->setObjectName(QString::fromUtf8("diagnosiLabel"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, diagnosiLabel);

        diagnosisEdit = new QTextEdit(formLayoutWidget);
        diagnosisEdit->setObjectName(QString::fromUtf8("diagnosisEdit"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, diagnosisEdit);

        readFromFileButton = new QPushButton(centralwidget);
        readFromFileButton->setObjectName(QString::fromUtf8("readFromFileButton"));
        readFromFileButton->setGeometry(QRect(240, 10, 371, 24));
        findBy = new QPushButton(centralwidget);
        findBy->setObjectName(QString::fromUtf8("findBy"));
        findBy->setGeometry(QRect(370, 340, 80, 24));
        noReading = new QLabel(centralwidget);
        noReading->setObjectName(QString::fromUtf8("noReading"));
        noReading->setGeometry(QRect(250, 370, 371, 20));
        noReading->setStyleSheet(QString::fromUtf8("color: rgb(255,0,0)"));
        formLayoutWidget_2 = new QWidget(centralwidget);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 350, 220, 80));
        formLayout = new QFormLayout(formLayoutWidget_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        show = new QPushButton(formLayoutWidget_2);
        show->setObjectName(QString::fromUtf8("show"));

        formLayout->setWidget(0, QFormLayout::LabelRole, show);

        isAllPatients = new QRadioButton(formLayoutWidget_2);
        isAllPatients->setObjectName(QString::fromUtf8("isAllPatients"));
        isAllPatients->setChecked(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, isAllPatients);

        withoutWard = new QRadioButton(formLayoutWidget_2);
        withoutWard->setObjectName(QString::fromUtf8("withoutWard"));

        formLayout->setWidget(1, QFormLayout::FieldRole, withoutWard);

        chooseCriteria = new QComboBox(centralwidget);
        chooseCriteria->addItem(QString());
        chooseCriteria->addItem(QString());
        chooseCriteria->addItem(QString());
        chooseCriteria->addItem(QString());
        chooseCriteria->setObjectName(QString::fromUtf8("chooseCriteria"));
        chooseCriteria->setGeometry(QRect(470, 340, 111, 24));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(10, 290, 211, 24));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(10, 320, 141, 24));
        deleteBox = new QComboBox(centralwidget);
        deleteBox->setObjectName(QString::fromUtf8("deleteBox"));
        deleteBox->setGeometry(QRect(170, 320, 51, 24));
        deleteBox->setEditable(false);
        deleteBox->setMaxCount(8);
        deleteBox->setMinimumContentsLength(1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 634, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        deleteBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        surnameLabel->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        patronymicLabel->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        ageLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202", nullptr));
        sexLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273", nullptr));
        maleRadioButton->setText(QCoreApplication::translate("MainWindow", "\320\234\321\203\320\266\321\201\320\272\320\276\320\271", nullptr));
        label_6->setText(QString());
        femaleRadioButton->setText(QCoreApplication::translate("MainWindow", "\320\226\320\265\320\275\321\201\320\272\320\270\320\271", nullptr));
        diagnosiLabel->setText(QCoreApplication::translate("MainWindow", "\320\224\320\270\320\260\320\263\320\275\320\276\320\267", nullptr));
        readFromFileButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\207\320\270\321\202\320\260\321\202\321\214 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        findBy->setText(QCoreApplication::translate("MainWindow", " \320\235\320\260\320\271\321\202\320\270 \320\277\320\276:", nullptr));
        noReading->setText(QString());
        show->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214:", nullptr));
        isAllPatients->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\320\265\321\205 \320\277\320\260\321\206\320\270\320\265\320\275\321\202\320\276\320\262", nullptr));
        withoutWard->setText(QCoreApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\273\320\270\321\201\321\214 \320\261\320\265\320\267 \320\277\320\260\320\273\320\260\321\202", nullptr));
        chooseCriteria->setItemText(0, QCoreApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        chooseCriteria->setItemText(1, QCoreApplication::translate("MainWindow", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202", nullptr));
        chooseCriteria->setItemText(2, QCoreApplication::translate("MainWindow", "\320\224\320\270\320\260\320\263\320\275\320\276\320\267", nullptr));
        chooseCriteria->setItemText(3, QCoreApplication::translate("MainWindow", "\320\237\320\260\320\273\320\260\321\202\320\260", nullptr));

        addButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        deleteBox->setCurrentText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
