#ifndef SETSPEEDDIALOG_H
#define SETSPEEDDIALOG_H

#include <QDialog>

namespace Ui {
class SetSpeedDialog;
}

class SetSpeedDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetSpeedDialog(QWidget *parent = nullptr);
    ~SetSpeedDialog();

private slots:
    void on_setSpeedButton_clicked();
signals:
    void setSpeed(int);
private:
    Ui::SetSpeedDialog *ui;
    int newSpeed = 50;
};

#endif // SETSPEEDDIALOG_H
