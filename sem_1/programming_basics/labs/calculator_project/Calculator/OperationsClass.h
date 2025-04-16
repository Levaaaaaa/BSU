#pragma once

#ifndef ALLINCLUDE_H
#include "AllInclude.h"
#endif // !ALLINCLUDE_H

class Operations
{
public:
    Operations() {
        for (size_t i = 0; i < 5; i++)
        {
            Operations* tmp;
            variableOperationOfClass.push_back(tmp);
        }
    }

    int countArg;
    std::string request_list;
    std::string name;
    std::vector<Operations*> variableOperationOfClass;

    std::string getName() { return name; }
    virtual std::vector<double> request();
    Operations* selectOperation();
    void startOperation();

    virtual double operation(double a) = 0;
    virtual long double operation(double a, double b) = 0;

    //int checkInput(std::vector<int> variableValues);
    std::vector<int> createVectorOfVariableValues();

    virtual ~Operations() {
        std::vector<Operations*>().swap(variableOperationOfClass);
    }

private:
    static bool myIsDigit(std::string);
};