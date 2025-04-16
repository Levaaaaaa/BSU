#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include "computeritem.h"
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    std::list<ComputerItem> getItems() const {return Items;}
    friend ComputerItem findByModel (std::string);

public slots:
    void slotModel(QString QStr);

private slots:

    void on_readFile_clicked();

    void on_findByModel_clicked();

    void on_AddButton_clicked();

signals:
    void signalModel(QString m);
private:
    Ui::MainWindow *ui;
    Dialog* dialogModel;

    std::list<ComputerItem> Items;
    void ShowComputerItems();

};
void AddIntoFile (ComputerItem, std::string);
void AddIntoList(std::list<ComputerItem>&, ComputerItem);
#endif // MAINWINDOW_H
