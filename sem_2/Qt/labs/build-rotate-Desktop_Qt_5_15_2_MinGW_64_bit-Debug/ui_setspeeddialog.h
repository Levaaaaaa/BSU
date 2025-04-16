/********************************************************************************
** Form generated from reading UI file 'setspeeddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETSPEEDDIALOG_H
#define UI_SETSPEEDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SetSpeedDialog
{
public:
    QPushButton *setSpeedButton;
    QLineEdit *lineEdit;

    void setupUi(QDialog *SetSpeedDialog)
    {
        if (SetSpeedDialog->objectName().isEmpty())
            SetSpeedDialog->setObjectName(QString::fromUtf8("SetSpeedDialog"));
        SetSpeedDialog->resize(400, 300);
        setSpeedButton = new QPushButton(SetSpeedDialog);
        setSpeedButton->setObjectName(QString::fromUtf8("setSpeedButton"));
        setSpeedButton->setGeometry(QRect(290, 30, 80, 24));
        lineEdit = new QLineEdit(SetSpeedDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 30, 181, 24));

        retranslateUi(SetSpeedDialog);

        QMetaObject::connectSlotsByName(SetSpeedDialog);
    } // setupUi

    void retranslateUi(QDialog *SetSpeedDialog)
    {
        SetSpeedDialog->setWindowTitle(QCoreApplication::translate("SetSpeedDialog", "Dialog", nullptr));
        setSpeedButton->setText(QCoreApplication::translate("SetSpeedDialog", "set speed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetSpeedDialog: public Ui_SetSpeedDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETSPEEDDIALOG_H
