#include "headers.h"

int main()
{
    std::cout << "Task Present\n";
    std::ifstream file("Text.txt");

    if (!file)
    {
        std::cout << "Error file!\n";
    }

    Sweet sweets;
    sweets.read(file);
    file.close();
    bool flag1 = true;

    while (flag1)
    {
        Present present;
        int choise;
        std::cout << "\nOperations for present:\n"
            << "(1) create by weight\n"
            << "(2) create by cost\n"
            << "(0) exit program\n"
            << "\nEnter number task: ";
        std::cin >> choise;

        switch (choise)
        {
        case 0:
        {
            flag1 = false;
            continue;
        }
        case 1:
        {
            double weight;
            std::cout << "\nCreate by weight\nEnter weight present: ";
            std::cin >> weight;
            present.createByWeight(weight, sweets);
            break;
        }
        case 2:
        {
            double cost;
            std::cout << "\nÑreate by cost\nEnter cost present: ";
            std::cin >> cost;
            present.createByCost(cost, sweets);
            break;
        }
        default:
        {
            std::cout << "\nError! Not operation!\n";
            continue;
        }
        }

        if (present.getSize() == 0)
        {
            std::cout << "\nError! No such sweets!\n";
            continue;
        }
        else
        {
            std::cout << "\nPresent consists of sweets:\n";
            present.print(std::cout);
        }

        bool flag2 = true;

        while (flag2)
        {
            int choise;
            std::cout << "\nOperations for present:\n"
                << "(1) sort for name\n"
                << "(2) sort for weight\n"
                << "(3) sort for price\n"
                << "(4) sort for sugar\n"
                << "(5) print present\n"
                << "(6) print sweets with specified range content sugar\n"
                << "(0) create new present\n"
                << "\nEnter number task: ";
            std::cin >> choise;

            switch (choise)
            {
            case 0:
            {
                flag2 = false;
                continue;
            }
            case 1:
            {
                present.sortName();
                std::cout << "\nSort done!\n";
                break;
            }
            case 2:
            {
                present.sortWeight();
                std::cout << "\nSort done!\n";
                break;
            }
            case 3:
            {
                present.sortPrice();
                std::cout << "\nSort done!\n";
                break;
            }
            case 4:
            {
                present.sortSugar();
                std::cout << "\nSort done!\n";
                break;
            }
            case 5:
            {
                std::cout << "\n";
                present.print(std::cout);
                break;
            }
            case 6:
            {
                double min, max;
                std::cout << "\nEnter min sugar: ";
                std::cin >> min;
                std::cout << "Enter max sugar: ";
                std::cin >> max;
                present.findSweetSugar(min, max);
                break;
            }
            default:
            {
                std::cout << "\nError! Not operation!\n";
            }
            }
        }
    }

    system("pause");
    return 0;
}