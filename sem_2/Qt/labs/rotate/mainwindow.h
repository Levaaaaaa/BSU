
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <cmath>
#include <QDialog>
#include "setspeeddialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *) override;

protected slots:
    void timerSlot();
    void setSpeed(int);
private slots:
    void on_actionsetSpeed_triggered();

private:
    Ui::MainWindow *ui;
    SetSpeedDialog* setSpeedDialog;
    QTimer* timer;
    int x0 = 200;
    int y0 = 200;
    int len = 100;
    int delay = 50;
    bool directionX = false;
    int stepX = len/delay;

    int x = x0 + len;
    int y = y0;



};

#endif // MAINWINDOW_H
