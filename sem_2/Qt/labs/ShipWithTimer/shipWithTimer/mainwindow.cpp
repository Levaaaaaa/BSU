
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerSlot()
{
    if (flag) {
        if (delta==5) flag = false;
        delta++;
    }
    else {
        if (delta==-5) flag = true;
        delta--;
    }

    this->update();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    int centerX = 250;
    int centerY = 200;

    QPainter painter (this);
    QPen pen;
    pen.setColor(Qt::yellow);       //палуба
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkYellow);

    QPen mastPen;                   //мачта
    mastPen.setColor(Qt::black);
    mastPen.setWidth(5);
    mastPen.setStyle(Qt::SolidLine);

    QPen wavePen;                   //волны
    wavePen.setColor(Qt::blue);
    wavePen.setWidth(10);

    QBrush waveBrush;
    waveBrush.setColor(Qt::blue);
    waveBrush.setStyle(Qt::SolidPattern);

    QBrush flagBrush;               //флаг
    flagBrush.setColor(Qt::red);
    flagBrush.setStyle(Qt::SolidPattern);

    QBrush sailBrush;
    sailBrush.setColor(Qt::gray);
    sailBrush.setStyle(Qt::SolidPattern);

    painter.begin(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    QPolygon deck;

    deck << QPoint(centerX-100,centerY) << QPoint(centerX+100, centerY) << QPoint(centerX+50, centerY+100) << QPoint(centerX-50, centerY+100);
    painter.drawPolygon(deck);      //рисуем палубу

    painter.setPen(mastPen);        //рисуем мачту
    painter.drawLine(centerX, centerY, centerX,100-flagHeight);


    painter.setPen(wavePen);
    painter.setBrush(waveBrush);
    int x1 = 0;
    int y1 = 300;
    int lengthWave = 50;
    int heightWave = delta*coefWave;
    int x2 = x1+lengthWave;
    int y2 = y1-heightWave;
    while(x1 <= 700) {              //рисуем волны
        painter.drawLine(x1, y1, x2, y2);
        x1 = x2;
        y1 = y2;
        x2 = x1+lengthWave;
        y2 = y1+2*heightWave;
        painter.drawLine(x1, y1, x2, y2);
        x1 = x2;
        y1 = y2;
        x2 = x1+lengthWave;
        y2 = y1-2*heightWave;
    }


    painter.setPen(Qt::NoPen);

    painter.setBrush(flagBrush);
    int flagWidth = 40;
    /*int startY = 100;
    if (delta > 0) startY = 150;
    else if (delta < 0) startY = 50;*/
    int LeftBottomAngleY = 150-(delta*coefFlag);
    painter.drawRect(250, 150-(delta*coefFlag)-flagHeight, flagWidth, flagHeight);      //рисуем флаг

    int sailWidth = 150;
    QPoint sailAngle (centerX+sailWidth, LeftBottomAngleY+(centerY-LeftBottomAngleY)/2);

    painter.setBrush(sailBrush);
    QPolygon sail;
    sail << QPoint(centerX, centerY) << QPoint(centerX, LeftBottomAngleY) << sailAngle;
    painter.drawPolygon(sail);

    painter.end();
}
