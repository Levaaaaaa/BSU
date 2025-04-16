#ifndef SURNAMEDIALOG_H
#define SURNAMEDIALOG_H

#include <QDialog>

namespace Ui {
class surnameDialog;
}

class surnameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit surnameDialog(QWidget *parent = nullptr);
    ~surnameDialog();

private slots:
    void on_surnameDialog_accepted();

    void on_buttonBox_accepted();

signals:
    void signalSurname(QString);
private:
    Ui::surnameDialog *ui;
    bool isChanged = false;
public slots:
    void Surname(QString sur);
};

#endif // SURNAMEDIALOG_H
