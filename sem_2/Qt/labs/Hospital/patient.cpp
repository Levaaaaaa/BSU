
#include "patient.h"

std::istream& operator>> (std::istream& in, Patient& patient)
{
    std::string sur, n, p, s, d;

    int a;
    bool sex;
    in >> sur >> n >> p >> a >> s >> d; // >> w;
    if (s=="М") sex = true;
    else if (s=="Ж") sex = false;
    patient = Patient (sur, n, p, a, sex, d); //w);
    return in;
}

void ReadFromFile (std::list<Patient>& patientList, std::string path)
{
    std::ifstream fin;
    fin.open (path);
    Patient p;
    while (fin >> p) {
        patientList.push_back(p);
    }
}

bool Patient::operator==(Patient& p)
{
    bool result = true;
    if (this->getFIO()!=p.getFIO()) result = false;
    else if (this->getAge()!=p.getAge()) result = false;
    else if (this->getSex()!=p.getSex()) result = false;
    //else if (this->getWard()!=p.getWard()) result = false;
    else if (this->getDiagnosis()!=p.getDiagnosis()) result = false;

    return result;
}

std::string Patient::to_string()
{ //<< ward;
    std::string result;

    std::string sWard = ward==0 ? "-" : myToStdString(ward);
    result = getFIO() + ", Возраст: " + myToStdString(age) + ", Пол: " + getSex() + ", Диагноз: " + diagnosis + ", Палата: " + sWard;
    return result;
}

std::string Patient::forAdd()
{
    std::string result;
    result = getFIO()+" "+std::to_string(getAge())+" "+getSexForAdd()+" "+getDiagnosis();
    return result;
}
/*
bool operator< (const Patient & r,const Patient & l)
{
    return (!r.getSexBool() && l.getSexBool());
}*/
