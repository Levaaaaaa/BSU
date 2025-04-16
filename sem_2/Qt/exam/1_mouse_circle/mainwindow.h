
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
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

protected:
    void paintEvent(QPaintEvent *event) override;
private slots:
    void on_rad1_lineEdit_textChanged(const QString &arg1);

    void on_rad2_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    void mousePressEvent(QMouseEvent *event) override;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    bool firstCircle = true;

    int r1;
    int r2;

    bool isCross();
};

#endif // MAINWINDOW_H
