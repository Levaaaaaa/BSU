
#include "ward.h"

bool Ward::isEqDiagosis(Patient p)
{
    for (size_t i = 0; i < patientsInWard.size(); i++)
    {
        if (patientsInWard[i].getSex()==p.getSex() && patientsInWard[i].getDiagnosis()==p.getDiagnosis()) return true;
    }
    return false;
}

void Ward::removePatient(Patient p)
{
    int index;
    for (int i = 0; i < patientsInWard.size(); i++)
    {
        if (patientsInWard[i]==p) {
            index = i;
            break;
        }
    }
    for (int j = index; j < patientsInWard.size()-1; j++)
    {
        patientsInWard[j] = patientsInWard[j+1];
    }
    patientsInWard.pop_back();
}
/*
bool isMan()
{
    for (int i = 0; i < patientsInWard.size(); i++)
    {
        if (patientsInWard[i].getSex() == "мужской") return true;
    }
    return false;
}
*/
