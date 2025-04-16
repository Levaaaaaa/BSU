#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialogModel = new Dialog;

    connect (this, &MainWindow::signalModel, dialogModel, &Dialog::Model);
    connect(dialogModel, &Dialog::signalModel,this,&MainWindow::slotModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_readFile_clicked()
{
    ui->itemsTextEdit->clear();
    QString line = QFileDialog::getOpenFileName(0, "Open dialog", "", "*.txt");
    ReadFromFile(Items, line.toStdString());
    ShowComputerItems();
}

void MainWindow::slotModel(QString QStr)
{
    std::string str = QStr.toStdString();
    auto it = std::find_if(Items.begin(), Items.end(), [str](ComputerItem &a){return a.getModel()==str;});
    QString qStr((*it).to_string().c_str());
    //ui->itemsTextEdit->append(qStr);
    emit signalModel(qStr);
}
void MainWindow::ShowComputerItems()
{
    ui->itemsTextEdit->clear();
    for (const auto& item :Items ) {
        QString qStr(item.to_string().c_str());//преобразовать в единую строчку QString каждый item
        ui->itemsTextEdit->append(qStr);
    }
}


void MainWindow::on_findByModel_clicked()
{
    dialogModel->show();
    //ComputerItem item = adddialog->;
}


void MainWindow::on_AddButton_clicked()
{
    std::string t, f, m, par;
    double price;
    bool isIn = true;

    t = ui->lineEdit->text().toStdString();
    f = ui->lineEdit_2->text().toStdString();
    m = ui->lineEdit_3->text().toStdString();
    par = ui->lineEdit_4->text().toStdString();
    price = ui->lineEdit_5->text().toDouble();
    isIn = ui->radioButton->isChecked();

    ComputerItem item (t,f,m,par,price,isIn);

    AddIntoList(Items, item);

}
/*
void AddIntoFile (ComputerItem item, std::string filename)
{
    std::ofstream fout;
    fout.open(filename);
    std::string str = item.to_string();
    fout.write(str);
    //fout << str;
}*/
void AddIntoList(std::list<ComputerItem>& itemsList, ComputerItem item)
{
    itemsList.push_back(item);
}
