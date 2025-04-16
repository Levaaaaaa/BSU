
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString line = QFileDialog::getOpenFileName(0, "Open dialog", "", "*.txt");
    std::ifstream fin (line.toStdString());
   // std::string str;
    int n;
    while(!fin.eof())
    {
        fin >> n;
        data.push_back(n);
    }
    data.pop_back();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter (this);
    painter.begin(this);

    int max = *(std::max_element(data.begin(), data.end()));
    double dx = this->width()/data.size();
    int dy = this->height()/max;

    for (int i = 0; i < data.size(); ++i) {
        double y1 = this->height()-data[i]*dy;
        int y2 = this->height();
        painter.drawRect(i*dx, y1, dx, y2);
    }

    painter.end();
}


