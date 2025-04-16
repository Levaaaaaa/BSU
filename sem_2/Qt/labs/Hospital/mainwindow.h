
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <patient.h>
#include "ward.h"
#include <list>
#include <vector>
#include <string>
#include <QFileDialog>
#include "surnamedialog.h"
#include "agedialog.h"
#include "diagnosisdialog.h"
#include "warddialog.h"
#include <iterator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT
public slots:
    void slotSurname(QString qStr);
    void slotAge(int);
    void slotDiagnosis(QString diagnosis_);
    void slotWard(int ward);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    std::list<Patient> getPatients() {return patients;}
    void allocPatients();

    //friend Patient findBySurname(std::string);
signals:
    void signalSurname(QString sur);
    void signalAge(QString);
    void signalDiagnosis (QString patient);
    void signalWard (QString patient);

private slots:
    void on_readFromFileButton_clicked();

    void on_findBy_clicked();

    void on_show_clicked();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;
    std::list<Patient> patients;
    //const int wardCount = 3;
    std::vector<Ward> wards;
    surnameDialog* dialogSurname;
    AgeDialog* dialogAge;
    DiagnosisDialog* dialogDiagnosis;
    WardDialog* dialogWard;

    std::string file;
    bool is_reading = false;
    void showPatients();
};
#endif // MAINWINDOW_H
