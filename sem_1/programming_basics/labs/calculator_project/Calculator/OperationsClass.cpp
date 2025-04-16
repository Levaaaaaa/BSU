#include "OperationsClass.h"

std::vector<double> Operations::request()
{
    std::vector<double> result;
    std::cout << "Enter the value for " << name << " ";
    for (size_t i = 0; i < countArg; i++)
    {
        std::string buff;
        do {
            std::cin >> buff;
        } while (!myIsDigit(buff));

        std::stringstream ostr;
        ostr << buff;
        double val;
        ostr >> val;
        result.push_back(val);
    }

    return result;
}

void Operations::startOperation()
{
    double val;
    std::string s = "\nEnter the parameter for " + this->name + "\n";
    //std::cout << s;
    val = request()[0];

    if (countArg == 1 && name!="Exponenta") {
        std::cout << "\n" << name << " of " << val << " is " << this->operation(val) << "\n";
    }
    else if (name == "Exponenta") {
        std::cout << "\n" << name << " of " << val << " is " << this->operation(val, 0) << "\n";
    }
    else if (countArg == 2) {
        double val1 = request()[1];
        std::cout << "\n" << name << " of " << val << " and " << val1 << " is " << this->operation(val, val1) << "\n";
    }
}



bool Operations::myIsDigit(std::string s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

std::vector<int> Operations::createVectorOfVariableValues()
{
    std::vector<int> result;

    for (size_t i = 0; i < variableOperationOfClass.size(); i++)
    {
        result.push_back(i);
    }

    return result;
}
Operations* Operations::selectOperation()
{
    int operation;
    bool run = true;
    std::string request_list = this->request_list;
    //std::string request_list = this->request_list;//"\nSelect the operation";
    /*for (size_t i = 1; i < this->variableOperationOfClass.size(); i++)
    {
        std::string s = "\n\t" + toString(i) + " - ";
        s += this->variableOperationOfClass[i]->name;
        request_list += s;
    }
    request_list += "\n\t0 - Back\n\n";
    */
    std::vector<int> variableValuesOfChoice = createVectorOfVariableValues();
    while (run) {
        std::cout << request_list;
        operation = checkInput(variableValuesOfChoice);
        //double val;
        run = false;
        try {
            if (operation == 0) throw 3;
            else {
                return variableOperationOfClass[operation];
                /*
                //std::string s = "Enter the parameter for " + this->name;
                //val = request()[0];

                if (countArg == 1) {
                    //std::cout << name << " of " << val << " is " << this->operation(val);
                }
                else if (countArg == 2) {
                    double val1 = request()[1];
                    //std::cout << name << " of " << val << " and " << val1 << " is " << variableOperationOfClass[operation]->operation(val, val1);
                }
                */
            }
        }
        catch (int e) {
            if (e == 1) run = true;
        }
        /*
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
        }*/
    }
}