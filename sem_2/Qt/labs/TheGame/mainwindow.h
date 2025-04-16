
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QPushButton>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_52_clicked();

    void on_pushButton_53_clicked();

    void on_pushButton_54_clicked();

    void on_pushButton_55_clicked();

    void on_startButton_clicked();

    void on_hideButton_clicked();

    void on_checkButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
    int level = 1;
    std::vector<std::vector<bool>> task;
    std::vector<std::vector<bool>> answer;
    QVector<QVector<QPushButton*>> buttons;
    bool isShowingTask;
    bool isWantingAnswer = false;
    bool isShowingAnswer = false;
    //bool isLevelSuссess;

    void gameControl();
    void allocBlackRect();
    void showTask();
    bool checkWin();
    void theEnd();
    void clearField();
    void clearTask();
    void generateHardTasks(int countRand);

};

#endif // MAINWINDOW_H
