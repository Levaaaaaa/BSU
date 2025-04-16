
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer();
    timer->setInterval(delay);

    connect(timer, &QTimer::timeout, this, &MainWindow::timerSlot);
    timer->start();

    setSpeedDialog = new SetSpeedDialog();

    connect(setSpeedDialog, &SetSpeedDialog::setSpeed, this, &MainWindow::setSpeed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSpeed(int speed)
{
    delay = speed;
    timer->stop();
    timer->setInterval(delay);
    timer->start();
}

void MainWindow::timerSlot()
{
    if (x == x0+len) directionX = false;
    else if (x == x0-len) directionX = true;
    if (directionX) {
        x += stepX;
        y = y0 - std::round(std::sqrt(len*len - (x-x0)*(x-x0))*100)/100;
    }
    else {
        x-=stepX;
        y = y0 + std::round(std::sqrt(len*len - (x-x0)*(x-x0))*100)/100;
    }

    this->update();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::red);
    painter.setPen(pen);

    painter.begin(this);

    painter.drawLine(x0, y0, x, y);

    painter.end();
}


void MainWindow::on_actionsetSpeed_triggered()
{
    setSpeedDialog->show();
}

