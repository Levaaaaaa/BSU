
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

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

protected:
    void paintEvent(QPaintEvent *);
    void timerSlot();
private:
    Ui::MainWindow *ui;
    int delay = 300;
    QPainter* painter;
    QTimer* timer;
    int delta = 1;  //волны в стартовом положении/флаг опущен/парус опущен
    int coefWave = 5;  //смещение волн
    int coefFlag = 10;    //смещение флага
    bool flag = true;
    int flagHeight = 20;
};

#endif // MAINWINDOW_H
