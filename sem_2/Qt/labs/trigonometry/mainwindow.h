
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cmath>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sinButton_clicked();

    void on_radSpinBox_valueChanged(double arg1);

    void on_gradspinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    int curG = 0;
    double coef = M_PI/180;
};

#endif // MAINWINDOW_H
