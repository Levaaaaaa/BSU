/********************************************************************************
** Form generated from reading UI file 'allocinwardsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLOCINWARDSDIALOG_H
#define UI_ALLOCINWARDSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AllocInWardsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QDialog *AllocInWardsDialog)
    {
        if (AllocInWardsDialog->objectName().isEmpty())
            AllocInWardsDialog->setObjectName(QString::fromUtf8("AllocInWardsDialog"));
        AllocInWardsDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AllocInWardsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textEdit = new QTextEdit(AllocInWardsDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(13, 40, 361, 191));
        label = new QLabel(AllocInWardsDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 20, 121, 16));

        retranslateUi(AllocInWardsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AllocInWardsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AllocInWardsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AllocInWardsDialog);
    } // setupUi

    void retranslateUi(QDialog *AllocInWardsDialog)
    {
        AllocInWardsDialog->setWindowTitle(QCoreApplication::translate("AllocInWardsDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AllocInWardsDialog", "\320\221\320\265\320\267 \320\277\320\260\320\273\320\260\321\202 \320\276\321\201\321\202\320\260\320\273\320\270\321\201\321\214:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AllocInWardsDialog: public Ui_AllocInWardsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLOCINWARDSDIALOG_H
