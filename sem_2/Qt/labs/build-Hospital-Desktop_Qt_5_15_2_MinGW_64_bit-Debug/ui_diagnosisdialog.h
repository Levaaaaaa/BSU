/********************************************************************************
** Form generated from reading UI file 'diagnosisdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGNOSISDIALOG_H
#define UI_DIAGNOSISDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DiagnosisDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;

    void setupUi(QDialog *DiagnosisDialog)
    {
        if (DiagnosisDialog->objectName().isEmpty())
            DiagnosisDialog->setObjectName(QString::fromUtf8("DiagnosisDialog"));
        DiagnosisDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(DiagnosisDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DiagnosisDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 20, 49, 16));
        lineEdit = new QLineEdit(DiagnosisDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 20, 261, 24));
        textEdit = new QTextEdit(DiagnosisDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(13, 49, 371, 191));

        retranslateUi(DiagnosisDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DiagnosisDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DiagnosisDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DiagnosisDialog);
    } // setupUi

    void retranslateUi(QDialog *DiagnosisDialog)
    {
        DiagnosisDialog->setWindowTitle(QCoreApplication::translate("DiagnosisDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DiagnosisDialog", "\320\224\320\270\320\260\320\263\320\275\320\276\320\267:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DiagnosisDialog: public Ui_DiagnosisDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGNOSISDIALOG_H
