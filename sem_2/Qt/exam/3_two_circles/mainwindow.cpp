
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
    buildRect();
    painter.drawRect(rectX, rectY, widthRect, heightRect);

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

void MainWindow::buildRect()
{
    bool firstBigger = (r1>=r2);
    int radX;
    int radY;
    int minX;
    int minY;

    if (x1<=x2) {
        minX = x1;
        radX = r1;
    }
    else {
        minX = x2;
        radX = r2;
    }

    if (y1<=y2) {
        minY = y1;
        radY = r1;
    }
    else {
        minY = y2;
        radY = r2;
    }

    rectX = minX-radX;
    rectY = minY - radY;
    widthRect = std::abs(x1-x2) + r1+r2;
    heightRect = std::abs(y1-y2) + r1 + r2;

    if (firstBigger) {
        if (std::abs(y2-y1) <= (r1-r2)) {
            rectY = y1 - r1;
            heightRect = 2*r1;
        }
        if (std::abs(x2-x1) <= (r1-r2)) {
            rectX = x1 - r1;
            widthRect = 2 * r1;
        }
    }
    else {
        if (std::abs(y2-y1) <= (r2-r1)) {
            rectY = y2 - r2;
            heightRect = 2 * r2;
        }
        if (std::abs(x2-x1) <= (r2-r1)) {
            rectX = x2 - r2;
            widthRect = 2*r2;
        }
    }
}

void MainWindow::on_rad1_comboBox_currentIndexChanged(int index)
{
}


void MainWindow::on_rad2_comboBox_currentIndexChanged(int index)
{
}


void MainWindow::on_rad1_comboBox_currentTextChanged(const QString &arg1)
{
    r1 = arg1.toInt();
}


void MainWindow::on_rad2_comboBox_currentTextChanged(const QString &arg1)
{
    r2 = arg1.toInt();
}

