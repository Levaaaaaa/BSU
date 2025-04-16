#include "center.h"
#include "ui_center.h"

Center::Center(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Center)
{
    ui->setupUi(this);
}

Center::~Center()
{
    delete ui;
}

void Center::on_set_center_clicked()
{
    int x = ui->x->text().toInt();
    int y = ui->y->text().toInt();
    emit setCenter(x, y);
}




