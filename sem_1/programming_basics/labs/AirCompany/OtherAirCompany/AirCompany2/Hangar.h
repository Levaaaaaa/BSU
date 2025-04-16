#pragma once
#include "headers.h"

std::shared_ptr<Plane> ptr(char);

class Hangar
{
public:
    std::vector<std::shared_ptr<Plane>> planes;

    Hangar() = default;
    ~Hangar() = default;

    void read(std::istream&);
    void print(std::ostream&);
    void sortPassengersCapacity();
    void sortLoadCapacity();
    void sortRange();
    void sortFuelConsumption();
};

std::shared_ptr<Plane> ptr(char choise)
{
    switch (choise)
    {
    case 'b':
    {
        return std::make_shared<Boeing>();
        break;
    }
    case 'a':
    {
        return std::make_shared<Airbus>();
        break;
    }
    case 't':
    {
        return std::make_shared<Tupolev>();
        break;
    }
    default:
    {
        return nullptr;
    }
    }
}

void Hangar::read(std::istream& file)
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

void Hangar::print(std::ostream& out)
{
    std::copy(planes.begin(), planes.end(), std::ostream_iterator<std::shared_ptr<Plane>>(out, "\n"));
}

void Hangar::sortPassengersCapacity()
{
    std::sort(planes.begin(), planes.end(), [](std::shared_ptr<Plane> a, std::shared_ptr<Plane> b) {return a->getPassengersCapacity() > b->getPassengersCapacity(); });
}

void Hangar::sortLoadCapacity()
{
    std::sort(planes.begin(), planes.end(), [](std::shared_ptr<Plane> a, std::shared_ptr<Plane> b) { return a->getLoadCapacity() > b->getLoadCapacity(); });
}

void Hangar::sortRange()
{
    std::sort(planes.begin(), planes.end(), [](std::shared_ptr<Plane> a, std::shared_ptr<Plane> b) { return a->getRange() > b->getRange(); });
}

void Hangar::sortFuelConsumption()
{
    std::sort(planes.begin(), planes.end(), [](std::shared_ptr<Plane> a, std::shared_ptr<Plane> b) { return a->getFuelConsumption() > b->getFuelConsumption(); });
}