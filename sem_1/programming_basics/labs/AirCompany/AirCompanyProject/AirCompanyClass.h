#pragma once

#include "AllIncludes.h"

std::shared_ptr<BasePlane> ptr(char);

class AirCompany
{
public:
    std::vector<std::shared_ptr<BasePlane>> planes;

    AirCompany() = default;
    ~AirCompany() = default;

    void read(std::istream&);
    void print(std::ostream&);
    void sortLongFly();
    double AllCapacity();
    double AllTonnage ();
    void findPetrolConsumption(double, double);
};

void AirCompany::findPetrolConsumption(double min, double max)
{
    std::sort(planes.begin(), planes.end(), [](std::shared_ptr<BasePlane> a, std::shared_ptr<BasePlane> b) { return (a->getPetrolConsumtion() < b->getPetrolConsumtion()); });
    auto tempBegin = std::find_if(planes.begin(), planes.end(), [min](std::shared_ptr<BasePlane> a) { return (a->getPetrolConsumtion() >= min); });
    auto tempEnd = std::find_if(planes.begin(), planes.end(), [max](std::shared_ptr<BasePlane> a) { return (a->getPetrolConsumtion() < max); });

    if (tempBegin == planes.end())
    {
        std::cout << "\nNot planes!\n";
        return;
    }
    else
    {
        std::cout << "\nSweets suitable for criteria:\n";
        std::copy(tempBegin, tempEnd, std::ostream_iterator<std::shared_ptr<BasePlane>>(std::cout, "\n"));
    }
}
std::shared_ptr<BasePlane> ptr(char choise)
{
    switch (choise)
    {
    case 'p':
    {
        return std::make_shared<PassengerPlane>();
        break;
    }
    case 'f':
    {
        return std::make_shared<FreightPlane>();
        break;
    }
    default:
    {
        return nullptr;
    }
    }
}

void AirCompany::read(std::istream& file)
{
    while (!file.eof())
    {
        char symbol;
        file >> symbol;
        planes.push_back(ptr(symbol));
        std::string str;
        getline(file, str);
        std::istringstream ss(str);
        planes.back()->read(ss);
    }
}

void AirCompany::print(std::ostream& out)
{
    std::copy(planes.begin(), planes.end(), std::ostream_iterator<std::shared_ptr<BasePlane>>(out, "\n"));
}

void AirCompany::sortLongFly()
{
    std::sort(planes.begin(), planes.end(), [](std::shared_ptr<BasePlane> a, std::shared_ptr<BasePlane> b) {return a->getLongFly() > b->getLongFly(); });
}

double AirCompany::AllCapacity()
{
    double result = 0;
    for (size_t i = 0; i < planes.size(); i++)
    {
        result += planes[i]->getCapacity();
    }

    return result;
}

double AirCompany::AllTonnage()
{
    double result = 0;
    for (size_t i = 0; i < planes.size(); i++)
    {
        result += planes[i]->getTonnage();
    }

    return result;
}