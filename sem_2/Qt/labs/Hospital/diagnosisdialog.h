#ifndef DIAGNOSISDIALOG_H
#define DIAGNOSISDIALOG_H

#include <QDialog>

namespace Ui {
class DiagnosisDialog;
}

class DiagnosisDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DiagnosisDialog(QWidget *parent = nullptr);
    ~DiagnosisDialog();

private slots:
    void on_buttonBox_accepted();

    void on_DiagnosisDialog_accepted();

public slots:
    void Diagnosis(QString patient);
signals:
    void signalDiagnosis(QString diagnosis);
private:
    Ui::DiagnosisDialog *ui;
    bool isChanged = false;
};

#endif // DIAGNOSISDIALOG_H
