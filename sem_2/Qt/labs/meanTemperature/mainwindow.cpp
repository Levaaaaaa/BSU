
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



void MainWindow::on_readButton_clicked()
{
    //QString path = QFileDialog::getOpenFileName(0, "Open dialog ", "*.txt");
    readFromFile();//path.toStdString());
    //printData();
    getMean();
}

void MainWindow::readFromFile()//std::string path)
{
    std::ifstream fin;
    fin.open("D:\\Leva\\BSU\\OiMP\\Tasks\\2_sem\\Ot\\Labs\\meanTemperature\\input.txt");
    double p;
    std::string s;
    while (fin >> s)
    {
        p = atof(s.c_str());

        data.push_back(p);
    }
    isReaded = true;
    this->update();
}

void MainWindow::getMean()
{
    double sum;
    for (int i = 0; i < data.size(); i++)
    {
        sum += data[i];
    }
    double result = sum/data.size();
    ui->label->setText(QString::fromStdString("Mean temperature: " + std::to_string(result)));
}

void MainWindow::paintEvent(QPaintEvent *)
{

    if (isReaded) {
        QPainter painter(this);
        QBrush backBrush;
        backBrush.setColor(Qt::gray);
        backBrush.setStyle(Qt::SolidPattern);
        painter.setBrush(backBrush);
        QPen pen;
        pen.setColor(Qt::red);
        painter.setPen(pen);

        painter.begin(this);

        int height = 500;
        int width = 500;

        int indentX = 10;
        int indentY = 10;

        painter.drawRect(indentX, indentY, width, height);
        double max = data[0];
        double min = data[0];
        for (int i = 0; i< data.size(); i++)
        {
            if (data[i] >= max) max = data[i];
            if (data[i] < min) min = data[i];
        }

        max = std::abs(max - min);
        double coefY = height/max;
        int coefX = width/(data.size()-1);
        int x = indentX;
        int y = height - indentY - data[0]*coefY;
        int x0;
        int y0;
        for (int i = 1; i <data.size(); i++)
        {
            x0 = x;
            y0 = y;
            x += coefX;
            y = height/2 - indentY - data[i]*coefY;
            painter.drawLine(x0, y0, x, y);
        }
        painter.end();
    }
}
void MainWindow::printData()
{
    std::string s = "";
    for (int i = 0; i < data.size(); ++i) {
        s += std::to_string(data[i]) + " ";
    }
    ui->label->setText(QString::fromStdString(s));
}

