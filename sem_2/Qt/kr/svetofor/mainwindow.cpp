
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    timer->setInterval(delay);

    ui->redBox->setMaximum(delay-10);
    ui->yellowBox->setMaximum(delay-10);
    ui->greenBox->setMaximum(delay-10);
    connect(timer, &QTimer::timeout, this, &MainWindow::timerSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerSlot()
{
    if (isRed) {
        timer->stop();
        timer->setInterval(delay - ui->yellowBox->value());
        timer->start();
        Yellow();
    }
    else if (isYellow) {
        timer->stop();
        timer->setInterval(delay - ui->greenBox->value());
        timer->start();
        Green();
    }
    else if (isGreen) {
        timer->stop();
        timer->setInterval(delay - ui->redBox->value());
        timer->start();
        Red();
    }
}

void MainWindow::Red()
{
    ui->redButton->setStyleSheet(QString::fromStdString("border-radius: 50%;\nbackground: red"));
    ui->yellowButton->setStyleSheet(QString::fromStdString("border-radius: 50%;\nbackground: white"));
    ui->greenButton->setStyleSheet(QString::fromStdString("border-radius: 50%;\nbackground: white"));
    isRed = true;
    isYellow = false;
    isGreen = false;
}

void MainWindow::Yellow()
{
    ui->redButton->setStyleSheet(QString::fromStdString("border-radius: 50%;\nbackground: white"));
    ui->yellowButton->setStyleSheet(QString::fromStdString("border-radius: 50%;\nbackground: yellow"));
    ui->greenButton->setStyleSheet(QString::fromStdString("border-radius: 50%;\nbackground: white"));
    isRed = false;
    isYellow = true;
    isGreen = false;
}

void MainWindow::Green()
{
    ui->redButton->setStyleSheet(QString::fromStdString("border-radius: 50%;\nbackground: white"));
    ui->yellowButton->setStyleSheet(QString::fromStdString("border-radius: 50%;\nbackground: white"));
    ui->greenButton->setStyleSheet(QString::fromStdString("border-radius: 50%;\nbackground: green"));
    isRed = false;
    isYellow = false;
    isGreen = true;
}

void MainWindow::on_redButton_clicked()
{
    timer->stop();
    Red();
}


void MainWindow::on_yellowButton_clicked()
{
    timer->stop();
    Yellow();
}


void MainWindow::on_greenButton_clicked()
{
    timer->stop();
    Green();
}


void MainWindow::on_startButton_clicked()
{
    Red();
    timer->start();
}


void MainWindow::on_speedBox_valueChanged(int arg1)
{
}

