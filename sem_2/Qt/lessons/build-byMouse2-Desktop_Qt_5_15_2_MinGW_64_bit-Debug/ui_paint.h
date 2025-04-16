/********************************************************************************
** Form generated from reading UI file 'paint.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINT_H
#define UI_PAINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Paint
{
public:
    QGraphicsView *graphicsView;
    QPushButton *pushButton;

    void setupUi(QWidget *Paint)
    {
        if (Paint->objectName().isEmpty())
            Paint->setObjectName(QString::fromUtf8("Paint"));
        Paint->resize(800, 600);
        graphicsView = new QGraphicsView(Paint);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(170, 70, 541, 351));
        pushButton = new QPushButton(Paint);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 180, 80, 24));

        retranslateUi(Paint);

        QMetaObject::connectSlotsByName(Paint);
    } // setupUi

    void retranslateUi(QWidget *Paint)
    {
        Paint->setWindowTitle(QCoreApplication::translate("Paint", "Paint", nullptr));
        pushButton->setText(QCoreApplication::translate("Paint", "clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Paint: public Ui_Paint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINT_H
