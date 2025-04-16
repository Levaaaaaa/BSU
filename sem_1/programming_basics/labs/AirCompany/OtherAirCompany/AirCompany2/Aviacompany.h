#pragma once
#include "headers.h"
#include "Aviacompany.h"

class Aviacompany
{
private:
    std::vector<std::shared_ptr<Plane>> aviacompany;
    size_t passengers_capacity = 0; 
    size_t load_capacity = 0; 
public:
    Aviacompany() = default;
    ~Aviacompany() = default;
    double getPassengersCapacity() const { return passengers_capacity; }
    double getLoadCapacity() const { return load_capacity; }
    void createByPassengersCapacity(size_t, Hangar&);
    void createByLoadCapacity(size_t, Hangar&);
    void print(std::ostream&);
    void findPlaneWithConsumption(size_t min, size_t max);
    long getSize() const { return aviacompany.size(); }
    void sortFuelComsumption();
    void sortPassengersCapacity();
    void sortLoadCapacity();
    void sortRange();
    void printOverallPassengersCapacity() { std::cout << "\noverall passengers capacity is " << passengers_capacity << "\n"; }
    void printOverallLoadCapacity() { std::cout << "\noverall load capacity is " <<  load_capacity << "\n"; }
};

void Aviacompany::findPlaneWithConsumption(size_t min, size_t max)
{
    std::sort(aviacompany.begin(), aviacompany.end(), [](std::shared_ptr<Plane> a, std::shared_ptr<Plane> b) { return a->getFuelConsumption() < b->getFuelConsumption(); });
    auto tempBegin = std::find_if(aviacompany.begin(), aviacompany.end(), [min](std::shared_ptr<Plane> a) { return a->getFuelConsumption() >= min; });
    auto tempEnd = std::find_if(aviacompany.begin(), aviacompany.end(), [max](std::shared_ptr<Plane> a) { return a->getFuelConsumption() > max; });

    if (tempBegin == aviacompany.end())
    {
        std::cout << "\nToo much consumption!\n";
        return;
    }
    else
    {
        std::cout << "\nThere are " << tempEnd - tempBegin << " planes suitable for criteria:\n\n\n";
        std::copy(tempBegin, tempEnd, std::ostream_iterator<std::shared_ptr<Plane>>(std::cout, "\n"));
        
    }
}

void Aviacompany::createByPassengersCapacity(size_t capacity_max, Hangar& hangar) //создание подарка по весу
{
    bool flag = true;
    Aviacompany aviacompany;
    hangar.sortPassengersCapacity();

    while (capacity_max > 0 && flag)
    {
        //for each просто пробегает по любому контейнеру, где есть begin() и end()
        //в квадратных скобках лямбда функции передаются объекты, которые находятся вне алгоритма (в нашем случае алгоритм for_each)
        std::for_each(hangar.planes.begin(), hangar.planes.end(), [&capacity_max, &flag, &aviacompany, &hangar](std::shared_ptr<Plane> planes)
            {
                if (planes->getPassengersCapacity() <= capacity_max)
                {
                    capacity_max -= planes->getPassengersCapacity();
                    aviacompany.passengers_capacity += planes->getPassengersCapacity();
                    aviacompany.load_capacity += planes->getLoadCapacity();
                    aviacompany.aviacompany.push_back(planes);
                }
                else if (capacity_max < hangar.planes.back()->getPassengersCapacity())
                {
                    flag = false;
                }
            });
    }

    *this = aviacompany;
}

void Aviacompany::createByLoadCapacity(size_t capacity_max, Hangar& hangar) //создание подарка по весу
{
    bool flag = true;
    Aviacompany aviacompany;
    hangar.sortLoadCapacity();

    while (capacity_max > 0 && flag)
    {
        //for each просто пробегает по любому контейнеру, где есть begin() и end()
        //в квадратных скобках лямбда функции передаются объекты, которые находятся вне алгоритма (в нашем случае алгоритм for_each)
        std::for_each(hangar.planes.begin(), hangar.planes.end(), [&capacity_max, &flag, &aviacompany, &hangar](std::shared_ptr<Plane> planes)
            {
                if (planes->getLoadCapacity() <= capacity_max)
                {
                    capacity_max -= planes->getLoadCapacity();
                    aviacompany.load_capacity += planes->getLoadCapacity();
                    aviacompany.passengers_capacity += planes->getPassengersCapacity();
                    aviacompany.aviacompany.push_back(planes);
                }
                else if (capacity_max < hangar.planes.back()->getLoadCapacity())
                {
                    flag = false;
                }
            });
    }

    *this = aviacompany;
}

void Aviacompany::print(std::ostream& out)
{
    std::copy(aviacompany.begin(), aviacompany.end(), std::ostream_iterator<std::shared_ptr<Plane>>(out, "\n"));
}

void Aviacompany::sortFuelComsumption()
{
    std::sort(aviacompany.begin(), aviacompany.end(), [](std::shared_ptr<Plane> a, std::shared_ptr<Plane> b) { return a->getFuelConsumption() < b->getFuelConsumption(); });
}

void Aviacompany::sortLoadCapacity()
{
    std::sort(aviacompany.begin(), aviacompany.end(), [](std::shared_ptr<Plane> a, std::shared_ptr<Plane> b) { return a->getLoadCapacity() < b->getLoadCapacity(); });
}

void Aviacompany::sortPassengersCapacity()
{
    std::sort(aviacompany.begin(), aviacompany.end(), [](std::shared_ptr<Plane> a, std::shared_ptr<Plane> b) { return a->getPassengersCapacity() < b->getPassengersCapacity(); });
}

void Aviacompany::sortRange()
{
    std::sort(aviacompany.begin(), aviacompany.end(), [](std::shared_ptr<Plane> a, std::shared_ptr<Plane> b) { return a->getRange() < b->getRange(); });
}