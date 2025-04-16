#include "ExpressionsClass.h"

double Expressions::account(std::string expression)
{
    double tmp;
    std::vector<std::string> tokens = createTokens(expression);
    if (tokens.size() == 0) {
        throw 1;
        return 1;
    }

    for (size_t i = 0; i < tokens.size(); i++)
    {
        //if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "^" || tokens[i] == "(" || tokens[i] == ")") {

        if (isElementInVector(AllOperation, tokens[i])) {
            if (operations.empty()) {
                operations.push(tokens[i]);
            }
            else {
                if (tokens[i] == ")") {
                    while (operations.top() != "(") {
                        double tmp = computation();
                        numbers.push(tmp);
                    }
                    operations.pop();
                }
                else {
                    if (priority[operations.top()] > priority[tokens[i]]) {
                        operations.push(tokens[i]);
                    }
                    else {
                        while (priority[tokens[i]] <= priority[operations.top()]) {
                            tmp = computation();
                            numbers.push(tmp);
                        }
                        operations.push(tokens[i]);
                    }
                }
            }
        }
        else {
            numbers.push(StringToDouble(tokens[i]));
        }
    }

    while (!operations.empty()) {
        tmp = computation();
        numbers.push(tmp);
    }



    return numbers.top();
}

std::vector<std::string> Expressions::createTokens(std::string s)
{
    std::vector<std::string> result;
    std::string tmp = "";

    for (size_t i = 0; i < s.size(); i++)
    {
        if (isElementInVector(AllNumbers, charToString(s[i]))) {
            tmp += s[i];
        }
        else if (isElementInVector(AllOperation, charToString(s[i]))) {
            if (tmp != "") {
                result.push_back(tmp);
                tmp = "";
            }
            result.push_back(charToString(s[i]));
        }
    }
    if (tmp!="") result.push_back(tmp);

    return result;
}

double Expressions::StringToDouble(std::string s)
{
    double result;
    std::stringstream str;

    str << s;
    str >> result;
    return result;
}

std::string Expressions::charToString(char c)
{
    std::string result;
    std::stringstream str;

    str << c;
    str >> result;
    return result;
}

double Expressions::execution(std::string s, double a, double b)
{
    if (s == "+") return a + b;
    else if (s == "-") return b - a;
    else if (s == "*") return a * b;
    else if (s == "/") return b/a;
    else if (s == "^") return power(a, b);
}

double Expressions::power(double b, double a)
{
    double result = 1;
    for (size_t i = 0; i < (b / 1); i++)
    {
        result *= a;
    }

    return result;
}

template <typename T>
T returnLastElementFromStack(std::stack<T>& stack)
{
    T a = stack.top();
    stack.pop();
    return a;
}

double Expressions::computation()
{
    double tmpA = returnLastElementFromStack(numbers);
    double tmpB = returnLastElementFromStack(numbers);
    double tmp = execution(operations.top(), tmpA, tmpB);
    operations.pop();
    return tmp;
}

void Expressions::IOExpr()
{
    bool run = true;
    std::string s;
    double result;
    while (run) {
        s = "";
        std::cout << "Enter th string: ";
        std::cin >> s;
        run = false;

        try {
            result = account(s);
        }
        catch (int ex) {
            if (ex == 1) {
                std::cout << "\n" << "Uncorrect input" << "\n";
                run = true;
            }
        }
    }
    std::cout << s << " = " << result << "\n\n";
}