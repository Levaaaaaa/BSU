/********************************************************************************
** Form generated from reading UI file 'surnamedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURNAMEDIALOG_H
#define UI_SURNAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_surnameDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QDialog *surnameDialog)
    {
        if (surnameDialog->objectName().isEmpty())
            surnameDialog->setObjectName(QString::fromUtf8("surnameDialog"));
        surnameDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(surnameDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(surnameDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 20, 251, 24));
        label = new QLabel(surnameDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 61, 21));
        textEdit = new QTextEdit(surnameDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(33, 60, 351, 171));

        retranslateUi(surnameDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), surnameDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), surnameDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(surnameDialog);
    } // setupUi

    void retranslateUi(QDialog *surnameDialog)
    {
        surnameDialog->setWindowTitle(QCoreApplication::translate("surnameDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("surnameDialog", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class surnameDialog: public Ui_surnameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURNAMEDIALOG_H
