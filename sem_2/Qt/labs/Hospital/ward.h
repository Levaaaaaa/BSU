
#ifndef WARD_H
#define WARD_H

#include <patient.h>
#include <vector>

class Ward
{
public:
    Ward() = default;
    Ward (int capacity_) : capacity (capacity_) {};
    ~Ward() = default;

    void addPatient(Patient p) {patientsInWard.push_back(p);}
    bool isEmpty() {return patientsInWard.size()==0;}
    bool isFill() {return patientsInWard.size()==capacity;}
    //bool isMan();
    bool sexOfWard() {return patientsInWard[0].getSexBool();}
    bool isEqDiagosis(Patient p);
    std::vector<Patient> getPatientsInWard() {return patientsInWard;}
    void popPatient() {patientsInWard.pop_back();}

    void removePatient(Patient);
private:
    int capacity;
    std::vector<Patient> patientsInWard;
};

#endif // WARD_H
