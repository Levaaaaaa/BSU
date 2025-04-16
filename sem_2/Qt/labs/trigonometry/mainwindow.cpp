
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



void MainWindow::on_sinButton_clicked()
{
    double u = ui->radSpinBox->value();
    double sin = std::sin(u);
    ui->resultLabel->setText(QString::fromStdString(std::to_string(sin)));
}


void MainWindow::on_radSpinBox_valueChanged(double arg1)
{
//   double coef = 180.0/M_PI;
   /* int g = arg1*coef;
    ui->gradspinBox->setValue(g);*/

    curG = arg1/coef;

}


void MainWindow::on_gradspinBox_valueChanged(int arg1)
{
    //double coef = M_PI/180.0;
    double r = arg1*coef;
    ui->radSpinBox->setValue(r);
    curG += 5;
}

