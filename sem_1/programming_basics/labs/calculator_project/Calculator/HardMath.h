#pragma once

#include "OperationsClass.h"

class HardMath : public Operations
{
public:
    HardMath() = default;
    virtual ~HardMath() = default;
};

/*Operations**/ void HardMathUI(/*HardMath*/);
std::vector<Operations*> TrigonometriaUI();
std::vector<Operations*> InverseTrigonometriaUI();
std::vector<Operations*> ExponentaOperationsUI();

class Trigonometria : public Operations//HardMath
{
public:
    Trigonometria() {
        countArg = 1;
        variableOperationOfClass = TrigonometriaUI();
    }

    long double operation(double a, double b) override { return 0; }
    virtual double operation(double a) { return 0; }
    std::string request_list = "\nSelect the operation\n\t1 - Sin\n\t2 - Cos\n\t3 - Tg\n\t4 - Ctg\n\t0 - Back\n\n";

    virtual ~Trigonometria() = default;
    
};


class Sin : public Trigonometria
{
public:
    Sin() {
        this->name = "Sin";
    }

    double operation(double) override;

    ~Sin() = default;
};

class Cos : public Trigonometria
{
public:
    Cos() {
        this->name = "Cos";
    }

    ~Cos() = default;

    double operation(double) override;
};

class Tg : public Trigonometria
{
public:
    Tg() {
        this->name = "Tg";
    }

    ~Tg() = default;

    double operation(double) override;
};

class Ctg : public Trigonometria
{
public:
    Ctg() {
        this->name = "Ctg";
    }

    ~Ctg() = default;

    double operation(double) override;
};

class InverseTrigonometria : public Operations//HardMath
{
public:
    InverseTrigonometria() {
        countArg = 1;
        variableOperationOfClass = InverseTrigonometriaUI();
    }

    long double operation(double a, double b) override { return 0; }
    virtual double operation(double a) { return 0; }
    std::string request_list = "\nSelect the operation\n\t1 - Arcsin\n\t2 - Arccos\n\t3 - Arctg\n\t4 - Arcctg\n\t0 - Back\n\n";

    virtual ~InverseTrigonometria() = default;

};

class Arcsin : public InverseTrigonometria
{
public:
    Arcsin() {
        this->name = "Arcsin";
    }

    ~Arcsin() = default;

    double operation(double) override;
};

class Arccos : public InverseTrigonometria
{
public:
    Arccos() {
        this->name = "Arccos";
    }

    ~Arccos() = default;

    double operation(double) override;
};

class Arctg : public InverseTrigonometria
{
public:
    Arctg() {
        this->name = "Arcctg";
    }

    ~Arctg() = default;

    double operation(double) override;
};

class Arcctg : public InverseTrigonometria
{
public:
    Arcctg() {
        this->name = "Arcctg";
    }

    ~Arcctg() = default;

    double operation(double) override;
};

class ExponOperations : public Operations//HardMath
{
public:
    ExponOperations() { 
        countArg = 2; 
        request_list = "\nSelect the operation\n\t1 - Exponenta\n\t2 - Ln\n\t3 - Log\n\t4 - print E\n\t0 - Back\n\n";
    }


    virtual long double operation(double a, double b = 0) {
        return 0;
    }
    virtual double operation(double a) { return 0; }

    virtual ~ExponOperations() = default;

};

class Exponenta : public ExponOperations
{
public:
    Exponenta() {
        this->name = "Exponenta";
        countArg = 1;
    }
    ~Exponenta() = default;

    long double operation(double, double b) override;
};

class Ln : public ExponOperations
{
public:
    Ln() {
        this->name = "Ln";
        countArg = 1;
    }

    ~Ln() = default;

    long double operation(double, double b = 0) override;
};

class Log : public ExponOperations
{
public:
    Log() {
        this->name = "Log";
    }

    ~Log() = default;

    long double operation(double, double b = 0) override;
};
//long double HardMath::PI = 3.14159265358979323846;