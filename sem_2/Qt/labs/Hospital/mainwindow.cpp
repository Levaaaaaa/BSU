
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialogSurname = new surnameDialog;
    dialogAge = new AgeDialog;
    dialogDiagnosis = new DiagnosisDialog;
    dialogWard = new WardDialog;

    wards = {Ward(2), Ward(1), Ward(1)};

    connect(this, &MainWindow::signalSurname, dialogSurname, &surnameDialog::Surname);
    connect(dialogSurname, &surnameDialog::signalSurname, this, &MainWindow::slotSurname);

    connect(this, &MainWindow::signalAge, dialogAge, &AgeDialog::Age);
    connect(dialogAge, &AgeDialog::signalAge, this, &MainWindow::slotAge);

    connect(this, &MainWindow::signalDiagnosis, dialogDiagnosis, &DiagnosisDialog::Diagnosis);
    connect(dialogDiagnosis, &DiagnosisDialog::signalDiagnosis, this, &MainWindow::slotDiagnosis);

    connect(this, &MainWindow::signalWard, dialogWard, &WardDialog::Ward);
    connect(dialogWard, &WardDialog::signalWard, this, &MainWindow::slotWard);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showPatients()
{
    ui->outputEdit->clear();
    int i = 1;
    for (auto p : patients)
    {
        QString qStr = QString((std::to_string(i)+". "+p.to_string()).c_str());
        ui->outputEdit->append(qStr);
        i++;
    }
}

void MainWindow::on_readFromFileButton_clicked()
{
    is_reading = false;
    ui->noReading->clear();
    ui->outputEdit->clear();
    QString path = QFileDialog::getOpenFileName(0, "Open dialog", "", "*.txt");
    file = path.toStdString();
    ReadFromFile(patients, path.toStdString());
    allocPatients();
    is_reading = true;
    showPatients();
    ui->deleteBox->setEditable(true);

    for (int i = 1; i <= patients.size(); i++)
    {
        QString s = QString(std::to_string(i).c_str());
        ui->deleteBox->addItem(s);
        if(ui->deleteBox->count() > 0) ui->deleteBox->setCurrentIndex(ui->deleteBox->count() - 1);

    }

}

void MainWindow::slotSurname(QString QStr)
{
    std::string surn = QStr.toStdString();
    //    auto it = std::find_if(patients.begin(), patients.end(), [surn](Patient& a){return a.getSurname()==surn;});
    for (auto p : patients)
    {
        if (p.getSurname()==surn){
            QString qStr (p.to_string().c_str());
            emit signalSurname(qStr);
        }
    }
    //QString qStr ((*it).to_string().c_str());
}

void MainWindow::slotAge(int age_)  //принимает возраст из диалога
{
    for (auto p : patients)
    {
        if (p.getAge()==age_){
            QString qStr (p.to_string().c_str());
            emit signalAge(qStr);
        }
    }
}

void MainWindow::slotDiagnosis(QString diagnosis_)
{
    std::string d = diagnosis_.toStdString();
    for (auto p : patients)
    {
        if (p.getDiagnosis()==d){
            QString qStr (p.to_string().c_str());
            emit signalDiagnosis(qStr);
        }
    }
}

void MainWindow::slotWard(int ward)
{
    for (auto p : patients) {
        if (p.getWard()==ward) {
            QString qstr (p.to_string().c_str());
            emit signalWard(qstr);
        }
    }
}

void MainWindow::on_findBy_clicked()
{
    if (is_reading) {
        std::string cur = ui->chooseCriteria->currentText().toStdString();
        if (cur=="Фамилия") dialogSurname->show();
        else if (cur=="Возраст") dialogAge->show();
        else if (cur=="Диагноз") dialogDiagnosis->show();
        else if (cur=="Палата") dialogWard->show();
    }
    else ui->noReading->setText("Данные не загружены. Прочитайте файл и повторите попытку.");
}

void MainWindow::allocPatients()
{
    for (auto &p : patients)
    {
        if (p.getWard()!=0) continue;
        for (int i = 0; i<wards.size(); i++)
        {
            if (wards[i].isEmpty() || (wards[i].isEqDiagosis(p) && !wards[i].isFill()))
            {
                wards[i].addPatient(p);
                p.setWard(i+1);
                break;
            }
        }
        if (p.getWard()!=0) continue;
        for (int i = 0; i < wards.size(); i++) {
            if (!wards[i].isFill() && (wards[i].sexOfWard()==p.getSexBool()))
            {
                wards[i].addPatient(p);
                p.setWard(i+1);
                break;
            }
        }
    }
    /*
    std::list<Patient> men;
    std::list<Patient> women;

    for (size_t i = 0; i < patients.size(); i++)
    {
        if (patients[i].getSex()=="мужской") men.push_back(patients[i]);
        else women.push_back(patients[i]);
    }

    for (size_t i = 0; i < wardCount; i++) {

    }*/
}



void MainWindow::on_show_clicked()
{
    ui->outputEdit->clear();
    if (is_reading) {
        if (ui->withoutWard->isChecked())
        {
            for (Patient p : patients) {
                if (p.getWard()==0) {
                    QString qstr = QString(p.to_string().c_str());
                    ui->outputEdit->append(qstr);
                }
            }
        }
        else if (ui->isAllPatients->isChecked()) {
            for (Patient p : patients) {
                QString qstr1 = QString(p.to_string().c_str());
                ui->outputEdit->append(qstr1);
            }
        }
    }
    else ui->noReading->setText("Данные не загружены. Прочитайте файл и повторите попытку.");
}


void MainWindow::on_addButton_clicked()
{
    bool isAllFill = true;
    QString empty = QString("");
    std::vector<QLineEdit*> lines = {ui->surnameEdit, ui->nameEdit, ui->patronymicEdit};
    std::vector<std::string> values;
    std::string d = "";
    if (is_reading)
    {
        for (int i = 0; i < 3; ++i) {
            if (lines[i]->displayText().isEmpty()) isAllFill = false;
            else values.push_back(lines[i]->text().toStdString());
        }
        if (ui->diagnosisEdit->toPlainText()==empty) isAllFill=false;
        else d = ui->diagnosisEdit->toPlainText().toStdString();
        if (isAllFill)
        {
            Patient p = Patient(values[0], values[1], values[2], ui->ageBox->value(), ui->maleRadioButton->isChecked(), d);
            for (int i = 0; i < 3; i++)
            {
                lines[i]->clear();
            }
            ui->maleRadioButton->setChecked(true);
            ui->ageBox->clear();
            ui->diagnosisEdit->clear();
            std::ofstream fout (file, std::ios::app);
            fout << p.forAdd();
            fout.close();
            patients.push_back(p);
            allocPatients();
            showPatients();

            ui->deleteBox->setMaxCount(patients.size());
            QString q = QString(std::to_string(patients.size()).c_str());
            ui->deleteBox->addItem(q);
            ui->deleteBox->setCurrentIndex(patients.size());
            ui->deleteBox->setCurrentText(q);
        }
        else ui->noReading->setText("Заполните ВСЕ поля");
    }
    else ui->noReading->setText("Файл не найден. Прочитайте файл и повторите попытку");
}


void MainWindow::on_deleteButton_clicked()
{
    if (is_reading)
    {
        Patient del;
        int i = 1;
        for (std::list<Patient>::iterator cur = patients.begin(); cur!=patients.end(); cur++)
        {
            if (i==(ui->deleteBox->currentIndex()+1))
            {
                del = *cur;
                patients.erase(cur);
                break;
            }
            i++;
        }
        ui->deleteBox->removeItem(patients.size());
        std::ofstream fout (file);
        for (auto p : patients) {
            fout << p.forAdd() << "\n";
        }

        int wardNum = del.getWard();
        if (wardNum!=0) {
            wards[wardNum-1].removePatient(del);
        }
        allocPatients();
        showPatients();
    }
    else ui->noReading->setText("Файл не найден. Прочитайте файл и повторите попытку");
}

