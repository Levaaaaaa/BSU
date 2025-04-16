/********************************************************************************
** Form generated from reading UI file 'warddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARDDIALOG_H
#define UI_WARDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WardDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QTextEdit *textEdit;

    void setupUi(QDialog *WardDialog)
    {
        if (WardDialog->objectName().isEmpty())
            WardDialog->setObjectName(QString::fromUtf8("WardDialog"));
        WardDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(WardDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(WardDialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(110, 10, 160, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(horizontalLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(3);

        horizontalLayout->addWidget(spinBox);

        textEdit = new QTextEdit(WardDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(13, 59, 371, 181));

        retranslateUi(WardDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), WardDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WardDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(WardDialog);
    } // setupUi

    void retranslateUi(QDialog *WardDialog)
    {
        WardDialog->setWindowTitle(QCoreApplication::translate("WardDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("WardDialog", "\320\235\320\276\320\274\320\265\321\200 \320\277\320\260\320\273\320\260\321\202\321\213:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WardDialog: public Ui_WardDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARDDIALOG_H
