
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

int MainWindow::matrix[3][3] = {{0,1,-1}, {1,1,0}, {0,-1,1}};

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPen pen;
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    QPainter painter (this);
    painter.begin(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    for (int i = 0; i < 3; ++i) {
        int y = 300+(i+1)*50;
        for (int j = 0; j < 3; ++j) {
            int x = 300+(j+1)*50;
            if (matrix[i][j]==1) painter.drawText(x,y,QString('X'));
            else if (matrix[i][j]==0) painter.drawText(x,y,QString('O'));
            else painter.drawText(x,y,QString(' '));

        }
    }

    painter.end();
}
