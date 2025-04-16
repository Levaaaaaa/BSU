#ifndef CENTER_H
#define CENTER_H

#include <QWidget>

namespace Ui {
class Center;
}

class Center : public QWidget
{
    Q_OBJECT

public:
    explicit Center(QWidget *parent = nullptr);
    ~Center();

private:
    Ui::Center *ui;
signals:
    void setCenter(int x, int y);
private slots:
    void on_set_center_clicked();

};

#endif // CENTER_H
