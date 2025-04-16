
#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (size_t i = 0; i<10; i++) {
        data.push_back(rand()%50+1);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.begin(this);


    QPen pen;
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(5);
    QBrush brush;
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::SolidPattern);

    painter.setPen(pen);
    painter.setBrush(brush);

    int max = *(std::max_element(data.begin(), data.end()));
    int dx = this->width()/max;
    int dy = this->height()/data.size();

    for (size_t i = 0; i < data.size(); i++)
    {
        painter.drawRect(0, i*dy, data[i]*dx, dy);
        QString str = QString::number(data[i]);
        painter.drawText(20, i*dy+dy/2, str);
    }
//    painter.drawRect(50,50,500,200);
   /* QPolygon polygon;
    polygon << QPoint(50, 50) << QPoint(100, 300) << QPoint (500, 200);
    polygon << QPoint(500, 150);
    painter.drawPolygon(polygon);*/


    painter.end();
}


