#include "diagnosisdialog.h"
#include "ui_diagnosisdialog.h"

DiagnosisDialog::DiagnosisDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DiagnosisDialog)
{
    ui->setupUi(this);
}

DiagnosisDialog::~DiagnosisDialog()
{
    delete ui;
}

void DiagnosisDialog::on_buttonBox_accepted()
{
    if (isChanged) ui->textEdit->clear();
    isChanged = true;
    emit signalDiagnosis(ui->lineEdit->text());
}

void DiagnosisDialog::Diagnosis(QString patient)
{
    ui->textEdit->append(patient);
    this->show();
}

void DiagnosisDialog::on_DiagnosisDialog_accepted()
{

}

