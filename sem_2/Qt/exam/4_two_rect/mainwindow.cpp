
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
    /*
    double betweenCenters = std::sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    if ((r1+r2)>betweenCenters && std::abs(r1-r2)<betweenCenters)
        return true;
    else return false;
*/
    /*int vx1 = x1-side1/2;
    int vy1 = y1- side1/2;

    int vx2 = x1+side1/2;
    int vy2 = x2+side1/2;*/

    //if ((std::abs(x2-vx1)<=side2 && std::abs(y2-vy1) <= side2) && (std::abs(x2-vx2)> side2 && std::abs(y2-vy2) > side2))
    deltaX = std::abs(x2-x1);
    deltaY = std::abs(y2-y1);
    if ((deltaX <= (side1+side2)/2) && (deltaY <= (side1+side2)/2) && ((deltaX >= std::abs(side2-side1)/2) || (deltaY >= std::abs(side2-side1)/2)))
        return true;

    return false;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.begin(this);

    //side1 = r1/std::sqrt(2);
    //side2 = r2/std::sqrt(2);
    side1 = r1/std::sqrt(2);
    side2 = r2/std::sqrt(2);
    painter.drawRect(x1-side1/2, y1-side1/2, side1, side1);
    painter.drawRect(x2-side2/2, y2-side2/2, side2, side2);
    ui->isCrossLabel->setText(QString::fromStdString(isCross() ? "cross" : "don't cross"));

    painter.end();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (x2!=0)
        int d = 0;
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

