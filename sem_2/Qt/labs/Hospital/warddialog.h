#ifndef WARDDIALOG_H
#define WARDDIALOG_H

#include <QDialog>

namespace Ui {
class WardDialog;
}

class WardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WardDialog(QWidget *parent = nullptr);
    ~WardDialog();

public slots:
    void Ward(QString patient);
private slots:
    void on_buttonBox_accepted();
signals:
    void signalWard(int ward);
private:
    Ui::WardDialog *ui;
    bool isChanged = false;
};

#endif // WARDDIALOG_H
