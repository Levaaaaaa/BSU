#include "HardMath.h"
#define _USE_MATH_DEFINES
//#include <cmath>
/*
long double Trigonometria::operation(double a, double b = 0) { return 0; }
double Trigonometria::operation(double a) { return a; }

long double InverseTrigonometria::operation(double a, double b = 0) { return 0; }
double InverseTrigonometria::operation(double a) { return 0; }
*/
double Sin::operation(double d)
{
        return d - d * d * d / 6 + d * d * d * d * d / 120;
}

double Cos::operation(double d)
{
    return 1 - d * d / 2 + d * d * d * d / 24;
}

double Tg::operation(double d)
{
    Sin sin;
    Cos cos;
    return sin.operation(d) / cos.operation(d);
}

double Ctg::operation(double d)
{
    Tg tg;
    return 1 / tg.operation(d);
}

double Arcsin::operation(double x)
{
    const double eps = 1.0e-5;
    double u = x;
    double sum = u;
    int n = 1;
    do {
        n += 2;
        u *= (2 * n - 1) / (2 * n) * (x * x) / (2 * n + 1);
        sum += u;
    } while (u>eps || -u < -eps);
    return sum;
//    return d/sqrt(1-d*d)+(d*d*d)/(2*(1-d*d)*sqrt(1-d*d))*10;
}

double Arccos::operation(double x)
{
    double eps = 1.0e-5;
    double u = 1;
    double sum = x;
    double n = 1;
    do {
        u *= ((2 * n - 1) * pow(x, 2*n+1)) / (2 * n * (2 * n + 1));
        sum += u;
        n++;
    } while (u > eps || u < -eps);
    return M_PI/2 - sum;
}

double Arctg::operation(double)
{
    double result = 0;
    return result;
}

double Arcctg::operation(double)
{
    double result = 0;
    return result;
}

long double Exponenta::operation(double d, double b = 0)
{
    return 1 + d + d * d / 2 + d * d * d / 6 + d * d * d * d / 24;
}

long double Ln::operation(double x, double b)
{
    const double eps = 1.0e-5;
    if (x == 0.0)   throw "Input error";
    else if (x < 0) x = -x;
    int a = 0;
    const double E = 2.71828182846;
    while (x >= 2.0) {
        a++;
        x /= E;
    }
    double t = x - 1;
    double u = t;
    double result = u;
    double n = 1;
    do {
        n++;
        u *= -((n - 1) * t) / n;
        result += u;
    } while (u > eps || u < -eps);

    return a+result;
    /*
    long double d = d1-1;
    int n = 11;
    long double result = 0;
    for (size_t i = 1; i <= n; i++)
    {
        result += (pow(-1, i+1) * pow(d, i))/i;
    }
    return result;*/
    //return d - (pow(d,2)/ 2) + (pow(d,3)/ 3) - (pow(d,4) / 4) + (pow(d,5) / 5) - (pow(d,6)/6) + (pow(d,7)/7);
}

long double Log::operation(double ground, double value)
{
    Ln ln;
    return (round(ln.operation(value)*10)/10) / (round(ln.operation(ground)*10)/10);
}

/*Operations**/ void HardMathUI(/*HardMath* operation*/)
{
    int mode;
    bool run = true;
    Operations* operation;
    //std::vector<std::function<double(double)>> allOperation{ sin };
    while (run) {
        run = false;
        std::string titleMode = "Select the mode:\n\t1 - Trigonometry\n\t2 - Inverse Triginometry\n\t3 - Exponenta\n\t0 - Back\n";

        std::cout << titleMode;

        mode = checkInput({ 0,1,2,3 });

        try {
            switch (mode) {
            case 0: {
                throw 3;
                break;
            }
            case 1: {
                Trigonometria trigonOperation;
                //Trigonometria* trigPtr = (Trigonometria*)trigonOperation.selectOperation();
                //operation = trigPtr;
                trigonOperation.selectOperation()->startOperation();

                break;
            }
            case 2: {
                InverseTrigonometria invTrigonOperation;
                //InverseTrigonometria* invTrigPtr = (InverseTrigonometria*)invTrigonOperation.selectOperation();
                //operation = invTrigPtr;
                invTrigonOperation.selectOperation()->startOperation();
                break;
            }
            case 3: {
                ExponOperations exponOperation;
                //exponOperation.variableOperationOfClass = ExponentaOperationsUI();
                //ExponOperations* exPtr = (ExponOperations*)exponOperation.selectOperation();
                //operation = exPtr;
                //Exponenta exponenta ();
                Operations* ptr1 = new Exponenta();
                Operations* ptr2 = new Ln();
                Operations* ptr3 = new Log();

                exponOperation.variableOperationOfClass = { nullptr, ptr1, ptr2, ptr3};
                operation = exponOperation.selectOperation();
                operation->startOperation();
                break;
            }
            }
        }
        catch (int i) {
            run = true;
        }
    }

    //return nullptr;
}

std::vector<Operations*> TrigonometriaUI()
{
    Sin sin;
    Cos cos;
    Tg tg;
    Ctg ctg;

    std::vector<Operations*> variableOperationOfClass = { nullptr, &sin, &cos, &tg, &ctg };

    return variableOperationOfClass;
}

std::vector<Operations*> InverseTrigonometriaUI()
{
    Arcsin sin;
    Arccos cos;
    Arctg tg;
    Arcctg ctg;

    std::vector<Operations*> variableOperationOfClass = { nullptr, &sin, &cos, &tg, &ctg };

    return variableOperationOfClass;
}
/*
std::vector<Operations*> ExponentaOperationsUI()
{
    Exponenta exponenta;
    Ln ln;
    Log log;

    std::vector<Operations*> variableOperationOfClass = { nullptr, &exponenta, &ln, &log};

    return variableOperationOfClass;
}*/
long double pow(long double d, int p)
{
    long double r = 1;
    for (size_t i = 0; i < p; i++)
    {
        r *= d;
    }
    return r;
}
/*
void HardMath::SelectInverseTrigonOperation()
{
    int operation;
    bool run = true;
    std::vector<int> variableOperation{ 0,1,2 };
    while (run) {
        std::string Operation = "Select the operation\n\t1 - Arcsin\n\t2 - Arccos\n\t0 - Back\n\n";
        operation = checkInput(Operation, variableOperation);
        double val;
        try {
            switch (operation) {
            case 0:
                throw 3;
                return;
            case 1:
                val = request();
                std::cout << "Arcsin " << val << " is " << arcsin(val) << "\n\n";
                break;
            case 2:
                val = request();
                std::cout << "Arccos " << val << " is " << arccos(val) << "\n\n";
                break;
            }
         }
        catch (int e) {
            if (e == 1) run = true;
        }
    }
}

void HardMath::SelectExponOperation()
{
    int operation;
    bool run = true;
    std::vector<int> variableOperation{ 0,1,2,3 };
    while (run) {
        std::string ExponOperation = "Select the operation\n\t1 - Exponenta\n\t2 - Ln\n\t3 - Log\n\t0 - Back\n\n";
        operation = checkInput(ExponOperation, variableOperation);
        double val;
        switch (operation) {
        case 0:
            throw 3;
            return;
        case 1:
            val = request();
            std::cout << "Exponenta " << val << " is " << expon(val) << "\n\n";
            break;
        case 2:
            val = request();
            std::cout << "Ln " << val << " is " << ln(val) << "\n\n";
            break;
        case 3:
            double v, g;
            v = request();
            g = request();
            std::cout << "Log of " << v << " to base " << g << " is " << log(g, v) << "\n\n";
        }
    }
}

void HardMath::SelectTrigonOperation()
{
    int operation;
    bool run = true;
    std::vector<int> variableOperation{ 0,1,2,3,4 };
    while (run) {
        std::string TrigonOperation = "Select the operation\n\t1 - Sin\n\t2 - Cos\n\t3 - Tg\n\t4 - Ctg\n\t0 - Back\n\n";
        operation = checkInput(TrigonOperation, variableOperation);
        double val;
        switch (operation) {
        case 0:
            throw 3;
            return;
        case 1:
            val = request();
            std::cout << "Sin " << val << " is " << sin(val) << "\n\n";
            break;
        case 2:
            val = request();
            std::cout << "Cos " << val << " is " << cos(val) << "\n\n";
            break;
        case 3:
            val = request();
            std::cout << "Tg " << val << " is " << tg(val) << "\n\n";
            break;
        case 4:
            val = request();
            std::cout << "Ctg " << val << " is " << ctg(val) << "\n\n";
            break;
        }
    }
}
*/
/*
int HardMath::checkInput(std::string title, std::vector<int> variableValues)
{
    int result;
    bool run = true;
    while (run) {
        run = false;
        std::cout << title;
        std::cin >> result;
        if (!isElementInVector(variableValues, result)) {
            run = true;
            std::cout << "\nUncorrect input\n";
        }
    }
    return result;
}*/