#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    center = new QPoint(this->width() / 2, this->height() / 2);
    timer = new QTimer();
    timer->setInterval(delay);
    pen = new QPen();

    connect(timer, &QTimer::timeout, this, &MainWindow::timerSlot);
    timer->start();

    centerDialog = new Center();

    connect(centerDialog, &Center::setCenter, this, &MainWindow::setCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.begin(this);
    (*pen).setColor(color);
    (*pen).setWidth(3);
    painter.setPen((*pen));
    painter.drawEllipse(*center, radius, radius);
    painter.end();
}

void MainWindow::timerSlot()
{
    if (flag) {
        radius -= 10;
        if (radius <= 20) {
            flag = false;
        }
    }
    else {
        radius += 10;
        if (radius >= 250) {
            flag = true;
        }
    }


    this ->update();
}





void MainWindow::on_speed_up_clicked()
{
    timer->stop();

    if (delay == 20) {
        delay = 20;
    }
    else {
       delay -= 20;
    }
    timer->setInterval(delay);
    timer->start();
}


void MainWindow::on_speed_down_clicked()
{
    timer->stop();

    if (delay == 200) {
        delay = 200;
    }
    else {
       delay += 20;
    }
    timer->setInterval(delay);
    timer->start();
}


void MainWindow::on_set_radius_clicked()
{
    int temp;
    temp = ui->lineEdit->text().toInt();
    if (temp >= 250) {
        QMessageBox *message = new QMessageBox();
        message->setText("введите меньший радиус");
        message->exec();
        return;
    }
    else if (temp <= 20) {
        QMessageBox *message = new QMessageBox();
        message->setText("введите больший радиус");
        message->exec();
        return;
    }
    else if (temp < 100) {
        flag = false;
    }
    else {
        flag = true;
    }
    //timer->stop();
    radius = temp;
    this->update();
}


void MainWindow::on_color_activated()
{
    QString qstr;
    qstr = ui->color->currentText();

    if (qstr == "red") {
        color = Qt::red;
    }
    else if (qstr == "green"){
       color= Qt::green;
    }
    else if (qstr == "blue"){
       color= Qt::blue;
    }
    else if (qstr == "yellow"){
       color= Qt::yellow;
    }
    else if (qstr == "black"){
       color= Qt::black;
    }
    else {
        color = Qt::green;
    }
    this->update();
}


void MainWindow::on_colorDialog_clicked()
{
    color = QColorDialog::getColor();
    this->update();
}



void MainWindow::on_actionset_center_triggered()
{
    centerDialog->show();
}

void MainWindow::setCenter(int x, int y)
{
    center->setX(x);
    center->setY(y);
    if (x == 0) {
       center->setX(std::rand() % 200);
    }
    if (y == 0) {
       center->setY(std::rand() % 200);
    }

}

