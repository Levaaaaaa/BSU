#include "warddialog.h"
#include "ui_warddialog.h"

WardDialog::WardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WardDialog)
{
    ui->setupUi(this);
}

WardDialog::~WardDialog()
{
    delete ui;
}

void WardDialog::on_buttonBox_accepted()
{
    if (isChanged) ui->textEdit->clear();
    isChanged = true;
    emit signalWard(ui->spinBox->value());
}

void WardDialog::Ward(QString patient)
{
    ui->textEdit->append(patient);
    this->show();
}
