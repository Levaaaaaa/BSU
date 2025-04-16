#include "AllInclude.h"

int checkInput(std::vector<int> variableValues)
{
    int result;
    bool run = true;
    while (run) {
        run = false;
        std::cin >> result;
        if (!isElementInVector(variableValues, result)) {
            run = true;
            std::cout << "\nUncorrect input\n";
        }
    }
    return result;
}