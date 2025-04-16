
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i<5; i++)
    {
        std::vector<bool> temp = {0,0,0,0,0};
        task.push_back(temp);
        answer.push_back(temp);
    }
    isShowingTask = true;

    QVector<QPushButton*> tmp;
    tmp.push_back(ui->pushButton_11);
    tmp.push_back(ui->pushButton_12);
    tmp.push_back(ui->pushButton_13);
    tmp.push_back(ui->pushButton_14);
    tmp.push_back(ui->pushButton_15);
    buttons.push_back(tmp);

    tmp.clear();
    tmp.push_back(ui->pushButton_21);
    tmp.push_back(ui->pushButton_22);
    tmp.push_back(ui->pushButton_23);
    tmp.push_back(ui->pushButton_24);
    tmp.push_back(ui->pushButton_25);
    buttons.push_back(tmp);

    tmp.clear();
    tmp.push_back(ui->pushButton_31);
    tmp.push_back(ui->pushButton_32);
    tmp.push_back(ui->pushButton_33);
    tmp.push_back(ui->pushButton_34);
    tmp.push_back(ui->pushButton_35);
    buttons.push_back(tmp);

    tmp.clear();
    tmp.push_back(ui->pushButton_41);
    tmp.push_back(ui->pushButton_42);
    tmp.push_back(ui->pushButton_43);
    tmp.push_back(ui->pushButton_44);
    tmp.push_back(ui->pushButton_45);
    buttons.push_back(tmp);

    tmp.clear();
    tmp.push_back(ui->pushButton_51);
    tmp.push_back(ui->pushButton_52);
    tmp.push_back(ui->pushButton_53);
    tmp.push_back(ui->pushButton_54);
    tmp.push_back(ui->pushButton_55);
    buttons.push_back(tmp);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::gameControl()
{
    //level++;
    //ui->label->clear();
    ui->levelLabel->setText(QString::fromStdString("Level: "+ std::to_string(level)));
    clearTask();
    clearField();
    allocBlackRect();
    //showTask();
}

void MainWindow::clearTask()
{
    for (int i = 0; i< 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            task[i][j] = false;
        }
    }
}
void MainWindow::clearField()
{
    for (int i = 0; i< 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            buttons[i][j]->setStyleSheet(QString::fromStdString("background: #e9e9e9"));
            answer[i][j] = false;
        }
    }
    isShowingTask = false;
    isShowingAnswer = false;
    //isWantingAnswer = false;
    ui->label->clear();
}

void MainWindow::allocBlackRect()   //сформировать задание
{
    //task[2][2] = true;
    /*int x = rand()%5;
    int y = rand()%5;
    task[y][x] = true;
    */
/*
    int countBlack = level*2;
    for (int i = 0; i < countBlack; i++)
    {
        int x, y;
        do {
        x = rand()%5;
        y = rand()%5;
        } while (task[y][x]);
        task[y][x] = true;
    }*/
    switch (level){
    case 1: {//(level==1) {
        int x1, y1;
        do {
        x1 = rand()%5;
        y1 = rand()%5;
        } while (x1==2 && y1==2);
        //int x2 = 4-x1;
        //int y2 = 4 - y1;
        task[y1][x1] = true;
        task[4-y1][4-x1] = true;
        break;
    }
    case 2: {//else if (level == 2) {
        int x = 2;
        int y = 2;
        do {
        if (x==2) x = rand()%5;
        if (y==2) y = rand()%5;
        } while (x==2 || y==2);
        task[y][x] = true;
        task[4-y][x] = true;
        task[y][4-x] = true;
        task[4-y][4-x] = true;
        break;
    }
    case 3:{
        generateHardTasks(2);
        break;
    }
    case 4: {

        generateHardTasks(4);
        break;
    }
    case 5: {
        generateHardTasks(6);
        break;
    }
    }
//    task[2][2] = true;
    showTask();
}

void MainWindow::generateHardTasks(int countRand)
{
    int x = 2;
    int y = 2;
    do {
        if (x==2) x= rand()%5;
        if (y==2) y = rand()%5;
    } while (x==2 || y==2);
    task[y][x] = true;
    task[4-y][x] = true;
    task[y][4-x] =true;
    task[4-y][4-x] = true;
    for (int i = 0; i<countRand; i++) {
        do {
            x = rand()%5;
            y = rand()%5;
        } while(task[y][x]);
        task[y][x] = true;
    }
}

void MainWindow::showTask()
{
    for (int i=0; i<5; i++)
    {
        for (int j= 0; j <5; j++)
        {
            if (task[i][j]) buttons[i][j]->setStyleSheet(QString::fromStdString("background: black"));
        }
    }
    isShowingTask = true;

}

void MainWindow::theEnd()
{
    isShowingTask = true;
    isWantingAnswer =false;
    ui->winLabel->setText(QString::fromStdString("YOU WIN"));
    //ui->startButton->setCheckable(false);
    //ui->winLabel->setText(QString::fromStdString("YOU WIN"));
    //ui->winLabel->setStyleSheet(QString::fromStdString("background: green"));
}
void MainWindow::on_pushButton_11_clicked()
{
    if (!isShowingTask){
        ui->pushButton_11->setStyleSheet(QString::fromStdString("background: black"));
        answer[0][0] = true;
    }
}

void MainWindow::on_pushButton_12_clicked()
{
    if (!isShowingTask){
        ui->pushButton_12->setStyleSheet(QString::fromStdString("background: black"));
        answer[0][1] = true;
    }
}

void MainWindow::on_pushButton_13_clicked()
{
    if (!isShowingTask){
        ui->pushButton_13->setStyleSheet(QString::fromStdString("background: black"));
        answer[0][2] = true;
    }
}

void MainWindow::on_pushButton_14_clicked()
{
    if (!isShowingTask){
        ui->pushButton_14->setStyleSheet(QString::fromStdString("background: black"));
        answer[0][3] = true;
    }
}

void MainWindow::on_pushButton_15_clicked()
{
    if (!isShowingTask){
        ui->pushButton_15->setStyleSheet(QString::fromStdString("background: black"));
        answer[0][4] = true;
    }
}



void MainWindow::on_pushButton_21_clicked()
{
    if (!isShowingTask){
        ui->pushButton_21->setStyleSheet(QString::fromStdString("background: black"));
        answer[1][0] = true;
    }
}


void MainWindow::on_pushButton_22_clicked()
{
    if (!isShowingTask){
        ui->pushButton_22->setStyleSheet(QString::fromStdString("background: black"));
        answer[1][1] = true;
    }
}


void MainWindow::on_pushButton_23_clicked()
{
    if (!isShowingTask){
        ui->pushButton_23->setStyleSheet(QString::fromStdString("background: black"));
        answer[1][2] = true;
    }
}


void MainWindow::on_pushButton_24_clicked()
{
    if (!isShowingTask){
        ui->pushButton_24->setStyleSheet(QString::fromStdString("background: black"));
        answer[1][3] = true;
    }
}


void MainWindow::on_pushButton_25_clicked()
{
    if (!isShowingTask){
        ui->pushButton_25->setStyleSheet(QString::fromStdString("background: black"));
        answer[1][4] = true;
    }
}


void MainWindow::on_pushButton_31_clicked()
{
    if (!isShowingTask){
        ui->pushButton_31->setStyleSheet(QString::fromStdString("background: black"));
        answer[2][0] = true;
    }
}


void MainWindow::on_pushButton_32_clicked()
{
    if (!isShowingTask){
        ui->pushButton_32->setStyleSheet(QString::fromStdString("background: black"));
        answer[2][1] = true;
    }
}


void MainWindow::on_pushButton_33_clicked()
{
    if (!isShowingTask){
        ui->pushButton_33->setStyleSheet(QString::fromStdString("background: black"));
        answer[2][2] = true;
    }
}


void MainWindow::on_pushButton_34_clicked()
{
    if (!isShowingTask){
        ui->pushButton_34->setStyleSheet(QString::fromStdString("background: black"));
        answer[2][3] = true;
    }
}


void MainWindow::on_pushButton_35_clicked()
{
    if (!isShowingTask){
        ui->pushButton_35->setStyleSheet(QString::fromStdString("background: black"));
        answer[2][4] = true;
    }
}


void MainWindow::on_pushButton_41_clicked()
{
    if (!isShowingTask){
        ui->pushButton_41->setStyleSheet(QString::fromStdString("background: black"));
        answer[3][0] = true;
    }
}


void MainWindow::on_pushButton_42_clicked()
{
    if (!isShowingTask){
        ui->pushButton_42->setStyleSheet(QString::fromStdString("background: black"));
        answer[3][1] = true;
    }
}


void MainWindow::on_pushButton_43_clicked()
{
    if (!isShowingTask){
        ui->pushButton_43->setStyleSheet(QString::fromStdString("background: black"));
        answer[3][2] = true;
    }
}


void MainWindow::on_pushButton_44_clicked()
{
    if (!isShowingTask){
        ui->pushButton_44->setStyleSheet(QString::fromStdString("background: black"));
        answer[3][3] = true;
    }
}


void MainWindow::on_pushButton_45_clicked()
{
    if (!isShowingTask){
        ui->pushButton_45->setStyleSheet(QString::fromStdString("background: black"));
        answer[3][4] = true;
    }
}


void MainWindow::on_pushButton_51_clicked()
{
    if (!isShowingTask){
        ui->pushButton_51->setStyleSheet(QString::fromStdString("background: black"));
        answer[4][0] = true;
    }
}


void MainWindow::on_pushButton_52_clicked()
{
    if (!isShowingTask){
        ui->pushButton_52->setStyleSheet(QString::fromStdString("background: black"));
        answer[4][1] = true;
    }
}


void MainWindow::on_pushButton_53_clicked()
{
    if (!isShowingTask){
        ui->pushButton_53->setStyleSheet(QString::fromStdString("background: black"));
        answer[4][2] = true;
    }
}


void MainWindow::on_pushButton_54_clicked()
{
    if (!isShowingTask){
        ui->pushButton_54->setStyleSheet(QString::fromStdString("background: black"));
        answer[4][3] = true;
    }
}


void MainWindow::on_pushButton_55_clicked()
{
    if (!isShowingTask){
        ui->pushButton_55->setStyleSheet(QString::fromStdString("background: black"));
        answer[4][4] = true;
    }
}


void MainWindow::on_startButton_clicked()
{
    if(!isWantingAnswer) {//checkWin();
    gameControl();
    ui->startButton->setText(QString::fromStdString("next"));
    }
}


void MainWindow::on_hideButton_clicked()
{
    if (!isWantingAnswer && !isShowingAnswer) {
        for (int i = 0; i<5; i++)
        {
        for (int j = 0; j<5; j++)
        {
                buttons[i][j]->setStyleSheet(QString::fromStdString("background: #e9e9e9"));
        }
        }
        isShowingTask = false;
        isWantingAnswer = true;
    }
}

bool MainWindow::checkWin()
{
    isWantingAnswer = false;
    for (int i = 0; i<5; i++)
    {
    for (int j = 0; j < 5; j++)
    {
        if (task[i][j]!=answer[i][j]) {
                if (level>1) level--;
                return false;
        }
    }
    }

    if (level<=5) level++;
    isWantingAnswer = false;
    isShowingAnswer = true;
    if (level>5) {
        theEnd();
    }
    return true;
}
void MainWindow::on_checkButton_clicked()
{
    if (isWantingAnswer){
        if (!checkWin()) ui->label->setText(QString::fromStdString("Level failed!"));
        else ui->label->setText(QString::fromStdString("Level complied!"));
    }
}


void MainWindow::on_clearButton_clicked()
{
    if (isWantingAnswer) clearField();
}

