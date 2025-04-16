
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>


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
    void on_redButton_clicked();

    void on_yellowButton_clicked();

    void on_greenButton_clicked();

    void on_startButton_clicked();

    void on_speedBox_valueChanged(int arg1);

protected:
    void timerSlot();
private:
    Ui::MainWindow *ui;

    QTimer* timer;
    int delay = 1000;
    bool isRed = false;
    bool isYellow = false;
    bool isGreen = false;


    void Red();
    void Yellow();
    void Green();
};

#endif // MAINWINDOW_H
