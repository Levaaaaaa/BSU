
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

bool MainWindow::isCross()
{
    double betweenCenters = std::sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    if ((r1+r2)>betweenCenters && std::abs(r1-r2)<betweenCenters)
        return true;
    else return false;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.begin(this);

    painter.drawEllipse(x1-r1, y1-r1, r1*2, r1*2);
    painter.drawEllipse(x2-r2, y2-r2, r2*2, r2*2);
    ui->isCrossLabel->setText(QString::fromStdString(isCross() ? "cross" : "don't cross"));

    painter.end();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (firstCircle) {
        x1 = event->localPos().x();
        y1 = event->localPos().y();
        firstCircle = false;
        this->update();
        return;
        //r1 = 100;
    }
    else if (!firstCircle) {
        x2 = event->localPos().x();
        y2 = event->localPos().y();
        firstCircle = true;
        this->update();
        //r2 = 200;
    }

}

void MainWindow::on_rad1_lineEdit_textChanged(const QString &arg1)
{
    r1 = arg1.toInt();
}


void MainWindow::on_rad2_lineEdit_textChanged(const QString &arg1)
{
    r2 = arg1.toInt();
}

