#include "setspeeddialog.h"
#include "ui_setspeeddialog.h"

SetSpeedDialog::SetSpeedDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetSpeedDialog)
{
    ui->setupUi(this);
}

SetSpeedDialog::~SetSpeedDialog()
{
    delete ui;
}

void SetSpeedDialog::on_setSpeedButton_clicked()
{
    newSpeed = ui->lineEdit->text().toInt();
    emit setSpeed(newSpeed);
}

