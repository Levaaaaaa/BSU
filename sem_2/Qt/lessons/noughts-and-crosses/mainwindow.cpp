
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

int MainWindow::deque = 0;
char MainWindow::board[3][3] = {0};
bool MainWindow::win = 0;

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkVictory()
{
    if (deque<5)
        return false;
    else {
    for(size_t i=0; i<3; i++)
    {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][2]!='\0')
            return true;
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[2][i]!='\0')
            return true;
    }
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[2][2]!='\0')
        return true;
    if (board[2][0]==board[1][1] && board[1][1]==board[0][2] && board[0][2]!='\0')
        return true;
    }
    /*
    if (deque==9) {
        ui->label->setText("Draw");
        return true;
    }*/
    return false;
}

void MainWindow::on_pushButton_00_clicked()
{
    if (ui->pushButton_00->text()=="" && !win)
    {
        if (deque%2==0)
            ui->pushButton_00->setText("X");
        else
            ui->pushButton_00->setText("0");
        deque++;
        board[0][0] = ui->pushButton_00->text().toStdString()[0];
        if (checkVictory())
        {
            ui->label->setText(ui->pushButton_00->text() + " won");
            win = true;
        }
            if (deque==9 && !win){
                ui->label->setText("Draw");
                win = true;
            }
    }
}


void MainWindow::on_pushButton_01_clicked()
{
    if (ui->pushButton_01->text()=="" && !win)
    {
        if (deque%2==0)
            ui->pushButton_01->setText("X");
        else
            ui->pushButton_01->setText("0");
        deque++;
        board[0][1] = ui->pushButton_01->text().toStdString()[0];
        if (checkVictory())
        {
            ui->label->setText(ui->pushButton_01->text() + " won");
            win = true;
        }
        else {
            if (deque==9 && !win){
                ui->label->setText("Draw");
                win = true;
            }
        }
    }
}


void MainWindow::on_pushButton_02_clicked()
{
    if (ui->pushButton_02->text()=="" && !win)
    {
        if (deque%2==0)
            ui->pushButton_02->setText("X");
        else
            ui->pushButton_02->setText("0");
        deque++;
        board[0][2] = ui->pushButton_02->text().toStdString()[0];
        if (checkVictory())
        {
            ui->label->setText(ui->pushButton_02->text() + " won");
            win = true;
        }
        else {
            if (deque==9 && !win){
                ui->label->setText("Draw");
                win = true;
            }
        }
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    if (ui->pushButton_10->text()=="" && !win)
    {
        if (deque%2==0)
            ui->pushButton_10->setText("X");
        else
            ui->pushButton_10->setText("0");
        deque++;
        board[1][0] = ui->pushButton_10->text().toStdString()[0];
        if (checkVictory())
        {
            ui->label->setText(ui->pushButton_10->text() + " won");
            win = true;
        }
        else {
            if (deque==9 && !win){
                ui->label->setText("Draw");
                win = true;
            }
        }
    }
}


void MainWindow::on_pushButton_11_clicked()
{
    if (ui->pushButton_11->text()=="" && !win)
    {
        if (deque%2==0)
            ui->pushButton_11->setText("X");
        else
            ui->pushButton_11->setText("0");
        deque++;
        board[1][1] = ui->pushButton_11->text().toStdString()[0];
        if (checkVictory())
        {
            ui->label->setText(ui->pushButton_11->text() + " won");
            win = true;
        }
        else {
            if (deque==9 && !win){
                ui->label->setText("Draw");
                win = true;
            }
        }
    }
}


void MainWindow::on_pushButton_12_clicked()
{
    if (ui->pushButton_12->text()=="" && !win)
    {
        if (deque%2==0)
            ui->pushButton_12->setText("X");
        else
            ui->pushButton_12->setText("0");
        deque++;
        board[1][2] = ui->pushButton_12->text().toStdString()[0];
        if (checkVictory())
        {
            ui->label->setText(ui->pushButton_12->text() + " won");
            win = true;
        }
        else {
            if (deque==9 && !win){
                ui->label->setText("Draw");
                win = true;
            }
        }
    }
}


void MainWindow::on_pushButton_20_clicked()
{
    if (ui->pushButton_20->text()=="" && !win)
    {
        if (deque%2==0)
            ui->pushButton_20->setText("X");
        else
            ui->pushButton_20->setText("0");
        deque++;
        board[2][0] = ui->pushButton_20->text().toStdString()[0];
        if (checkVictory())
        {
            ui->label->setText(ui->pushButton_20->text() + " won");
            win = true;
        }
        else {
            if (deque==9 && !win){
                ui->label->setText("Draw");
                win = true;
            }
        }
    }
}


void MainWindow::on_pushButton_21_clicked()
{
    if (ui->pushButton_21->text()=="" && !win)
    {
        if (deque%2==0)
            ui->pushButton_21->setText("X");
        else
            ui->pushButton_21->setText("0");
        deque++;
        board[2][1] = ui->pushButton_21->text().toStdString()[0];
        if (checkVictory())
        {
            ui->label->setText(ui->pushButton_21->text() + " won");
            win = true;
        }
        else {
            if (deque==9 && !win){
                ui->label->setText("Draw");
                win = true;
            }
        }
    }

}


void MainWindow::on_pushButton_22_clicked()
{
    if (ui->pushButton_22->text()=="" && !win)
    {
        if (deque%2==0)
            ui->pushButton_22->setText("X");
        else
            ui->pushButton_22->setText("0");
        deque++;
        board[2][2] = ui->pushButton_22->text().toStdString()[0];
        if (checkVictory())
        {
            ui->label->setText(ui->pushButton_22->text() + " won");
            win = true;
        }
        else {
            if (deque==9 && !win){
                ui->label->setText("Draw");
                win = true;
            }
        }
    }
}

