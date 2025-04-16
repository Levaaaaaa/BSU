#include "agedialog.h"
#include "ui_agedialog.h"

AgeDialog::AgeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgeDialog)
{
    ui->setupUi(this);
}

AgeDialog::~AgeDialog()
{
    delete ui;
}

void AgeDialog::on_buttonBox_accepted()
{
    //ui->textEdit->clear();
    if (isChanged) ui->textEdit->clear();
    isChanged = true;
    emit signalAge(ui->lineEdit->text().toInt());

}

void AgeDialog::Age(QString patient)
{
    ui->textEdit->append(patient);
    this->show();
}


void AgeDialog::on_AgeDialog_accepted()
{

}

