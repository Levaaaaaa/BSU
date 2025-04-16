#pragma once

#include "AllInclude.h"

class Expressions {
public:
    void IOExpr();
private:
    std::map <std::string, int> priority = { {"+", 1 },
                                             {"-", 1 },
                                             {"*", 2 },
                                             {"/", 2 },
                                             {"^", 3 },
                                             {"(", 0}
                                           };
    std::vector<std::string> AllOperation = { "+","-","*","/","^", "(", ")"};
    std::vector<std::string> AllNumbers = { "1","2","3","4","5","6","7","8","9","0" };
    std::stack <double> numbers;
    std::stack <std::string> operations;
    

   // std::string expression;

    double power(double a, double b);
    double StringToDouble(std::string s);
    std::string charToString(char c);

    double execution(std::string, double, double);
    std::vector<std::string> createTokens(std::string);
    double computation();

    double account(std::string);
};