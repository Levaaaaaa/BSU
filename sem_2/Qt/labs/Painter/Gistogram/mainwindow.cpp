
#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/*    std::ifstream fin("input.txt");

    int n;
    while (fin.eof())
    {
        fin >> n;
        data.push_back(n);
    }*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.begin(this);

    int max = *(std::max_element(data.begin(), data.end()));
    int dx = this->width()/data.size();
    int dy = this->height()/max;

    for (int i = 0; i < data.size(); i++) {
        painter.drawRect(dx*i, this->height() - data[i]*i*dy, dx, this->height());
    }

    painter.end();
}

