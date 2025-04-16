/********************************************************************************
** Form generated from reading UI file 'center.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENTER_H
#define UI_CENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Center
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *set_center;
    QLineEdit *x;
    QLineEdit *y;

    void setupUi(QWidget *Center)
    {
        if (Center->objectName().isEmpty())
            Center->setObjectName(QString::fromUtf8("Center"));
        Center->resize(365, 260);
        widget = new QWidget(Center);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 50, 311, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        set_center = new QPushButton(widget);
        set_center->setObjectName(QString::fromUtf8("set_center"));

        horizontalLayout->addWidget(set_center);

        x = new QLineEdit(widget);
        x->setObjectName(QString::fromUtf8("x"));

        horizontalLayout->addWidget(x);

        y = new QLineEdit(widget);
        y->setObjectName(QString::fromUtf8("y"));

        horizontalLayout->addWidget(y);


        retranslateUi(Center);

        QMetaObject::connectSlotsByName(Center);
    } // setupUi

    void retranslateUi(QWidget *Center)
    {
        Center->setWindowTitle(QCoreApplication::translate("Center", "Form", nullptr));
        set_center->setText(QCoreApplication::translate("Center", "set center", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Center: public Ui_Center {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTER_H
