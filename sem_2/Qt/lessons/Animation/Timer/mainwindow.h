#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QMessageBox>
#include <QColorDialog>
#include "center.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int radius = 200;
    QPoint * center;
    int delay = 100;
    int new_radius;
    QTimer *timer;
    QPen *pen;
    QColor color = Qt::red;
    bool flag = true;
    Center *centerDialog;
protected:
    void paintEvent(QPaintEvent *);
    void timerSlot();
private slots:

    void on_speed_up_clicked();
    void on_speed_down_clicked();
    void on_set_radius_clicked();
    void on_color_activated();
    void on_colorDialog_clicked();

    //void on_set_center_clicked();
    void on_actionset_center_triggered();
public slots:
    void setCenter(int x, int y);
};
#endif // MAINWINDOW_H
