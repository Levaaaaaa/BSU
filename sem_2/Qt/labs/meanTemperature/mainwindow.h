
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <vector>
#include <string>
#include <fstream>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *) override;
private slots:
    void on_readButton_clicked();
private:
    Ui::MainWindow *ui;
    std::vector<double> data;
    bool isReaded = false;

    void readFromFile();//std::string);
    void getMean();
    void printData();
};

#endif // MAINWINDOW_H
