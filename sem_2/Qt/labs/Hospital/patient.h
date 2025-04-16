
#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <istream>
#include <list>
#include <fstream>
#include <sstream>

class Patient
{
public:
    Patient() = default;
    Patient(std::string surname_, std::string name_, std::string patronymic_, int age_, bool sex_,
            std::string diagnosis_/*, int ward_*/) : surname (surname_), name (name_), patronymic (patronymic_), age (age_),
        sex(sex_), diagnosis (diagnosis_), ward(0) {};// ward(ward_){};
    ~Patient() = default;

    std::string getSurname() {return surname;}
    std::string getName() {return name;}
    std::string getPatronymic () {return patronymic;}
    std::string getFIO() {return surname + " " + name + " " + patronymic;}
    int getAge() {return age;}
    std::string getSex() {return sex ? "мужской" : "женский";}
    std::string getSexForAdd() {return sex ? "М" : "Ж";}
    bool getSexBool() const {return sex;}
    std::string getDiagnosis() {return diagnosis;}
    int getWard() {return ward;}
    void setWard(int ward_) {this->ward = ward_;}

    std::string to_string();
    std::string forAdd();
    friend bool operator< (const Patient& r,const Patient& l);
    bool operator==(Patient&);

private:
    std::string surname;
    std::string name;
    std::string patronymic;
    int age;
    bool sex;
    std::string diagnosis;
    int ward;

};

std::istream& operator>> (std::istream&, Patient&);
void ReadFromFile (std::list<Patient>&, std::string);

template <typename T>
std::string myToStdString(T t)
{
    std::stringstream str;
    str << t;
    std::string result;
    str >> result;
    return result;
}


#endif // PATIENT_H

