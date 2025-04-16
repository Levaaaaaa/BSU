
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    QPainter painter(this);
    painter.begin(this);

    QPolygon deck;
    deck << QPoint(200,400) << QPoint(300,500) << QPoint(600,500) << QPoint(700, 400);
    painter.drawPolygon(deck);
    painter.drawLine(450,400,450,100);

    painter.setBrush(brush);
    if (!flag)
    painter.drawRect(450, 360, 100, 30);
    else
    painter.drawRect(450, 100, 100, 30);

    painter.end();
}

void MainWindow::on_pushButton_clicked()
{
    flag = !flag;
    update();
}

