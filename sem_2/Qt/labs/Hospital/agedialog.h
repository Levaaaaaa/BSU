#ifndef AGEDIALOG_H
#define AGEDIALOG_H

#include <QDialog>

namespace Ui {
class AgeDialog;
}

class AgeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AgeDialog(QWidget *parent = nullptr);
    ~AgeDialog();

private:
    Ui::AgeDialog *ui;
    bool isChanged = false;
public slots:
    void Age(QString);
private slots:
    void on_buttonBox_accepted();

    void on_AgeDialog_accepted();
signals:
    void signalAge(int age);
};

#endif // AGEDIALOG_H
