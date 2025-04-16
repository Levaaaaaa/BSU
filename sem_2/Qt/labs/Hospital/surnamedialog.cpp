#include "surnamedialog.h"
#include "ui_surnamedialog.h"

surnameDialog::surnameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::surnameDialog)
{
    ui->setupUi(this);
}

surnameDialog::~surnameDialog()
{
    delete ui;
}

void surnameDialog::on_surnameDialog_accepted()
{

}


void surnameDialog::on_buttonBox_accepted()
{
    //ui->textEdit->clear();
    if (isChanged) ui->textEdit->clear();
    isChanged = true;
    emit signalSurname(ui->lineEdit->text());
}

void surnameDialog::Surname(QString sur)
{
    ui->textEdit->append(sur);
    this->show();
}
