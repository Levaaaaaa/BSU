/********************************************************************************
** Form generated from reading UI file 'agedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGEDIALOG_H
#define UI_AGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AgeDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;

    void setupUi(QDialog *AgeDialog)
    {
        if (AgeDialog->objectName().isEmpty())
            AgeDialog->setObjectName(QString::fromUtf8("AgeDialog"));
        AgeDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AgeDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(AgeDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 10, 49, 16));
        lineEdit = new QLineEdit(AgeDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 10, 113, 24));
        textEdit = new QTextEdit(AgeDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(13, 49, 371, 191));

        retranslateUi(AgeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AgeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AgeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AgeDialog);
    } // setupUi

    void retranslateUi(QDialog *AgeDialog)
    {
        AgeDialog->setWindowTitle(QCoreApplication::translate("AgeDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AgeDialog", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AgeDialog: public Ui_AgeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGEDIALOG_H
