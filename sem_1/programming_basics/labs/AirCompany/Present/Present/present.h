#pragma once
#include "headers.h"
#include "sweet.h"

class Present
{
private:
    std::vector<std::shared_ptr<BaseSweet>> present;
    double weight = 0; //текущий вес подарка
    double cost = 0; //текущая цена подарка
public:
    Present() = default;
    ~Present() = default;
    double getCost() const { return cost; }
    double getWeight() const { return weight; }
    void createByWeight(double, Sweet&);
    void createByCost(double, Sweet&);
    void print(std::ostream&);
    void findSweetSugar(double min, double max);
    long getSize() const { return present.size(); }
    void sortName();
    void sortWeight();
    void sortPrice();
    void sortSugar();
};

void Present::findSweetSugar(double min, double max)
{
    std::sort(present.begin(), present.end(), [](std::shared_ptr<BaseSweet> a, std::shared_ptr<BaseSweet> b) { return a->getSugar() < b->getSugar(); });
    auto tempBegin = std::find_if(present.begin(), present.end(), [min](std::shared_ptr<BaseSweet> a) { return a->getSugar() >= min; });
    auto tempEnd = std::find_if(present.begin(), present.end(), [max](std::shared_ptr<BaseSweet> a) { return a->getSugar() > max; });

    if (tempBegin == present.end())
    {
        std::cout << "\nNot sweet!\n";
        return;
    }
    else
    {
        std::cout << "\nSweets suitable for criteria:\n";
        std::copy(tempBegin, tempEnd, std::ostream_iterator<std::shared_ptr<BaseSweet>>(std::cout, "\n"));
    }
}

void Present::createByWeight(double weightMax, Sweet& sweet) //создание подарка по весу
{
    bool flag = true;
    Present present;
    sweet.sortWeight();

    while (weightMax > 0 && flag)
    {
        //for each просто пробегает по любому контейнеру, где есть begin() и end()
        //в квадратных скобках лямбда функции передаются объекты, которые находятся вне алгоритма (в нашем случае алгоритм for_each)
        std::for_each(sweet.sweets.begin(), sweet.sweets.end(), [&weightMax, &flag, &present, &sweet](std::shared_ptr<BaseSweet> sweets)
            {
                if (sweets->getWeight() <= weightMax)
                {
                    weightMax -= sweets->getWeight();
                    present.cost += sweets->getPrice();
                    present.weight += sweets->getWeight();
                    present.present.push_back(sweets);
                }
                else if (weightMax < sweet.sweets.back()->getWeight())
                {
                    flag = false;
                }
            });
    }

    *this = present;
}

void Present::createByCost(double costMax, Sweet& sweet)
{
    bool flag = true;
    Present present;
    sweet.sortWeight();

    while (costMax > 0 && flag)
    {
        std::for_each(sweet.sweets.begin(), sweet.sweets.end(), [&costMax, &flag, &present, &sweet](std::shared_ptr<BaseSweet> sweets)
            {
                if (sweets->getPrice() <= costMax)
                {
                    costMax -= sweets->getPrice();
                    present.cost += sweets->getPrice();
                    present.weight += sweets->getWeight();
                    present.present.push_back(sweets);
                }
                else if (costMax < sweet.sweets.back()->getPrice())
                {
                    flag = false;
                }
            });
    }

    *this = present;
}

void Present::print(std::ostream& out)
{
    std::copy(present.begin(), present.end(), std::ostream_iterator<std::shared_ptr<BaseSweet>>(out, "\n"));
}

void Present::sortName()
{
    std::sort(present.begin(), present.end(), [](std::shared_ptr<BaseSweet> a, std::shared_ptr<BaseSweet> b) { return a->getName() < b->getName(); });
}

void Present::sortWeight()
{
    std::sort(present.begin(), present.end(), [](std::shared_ptr<BaseSweet> a, std::shared_ptr<BaseSweet> b) { return a->getWeight() < b->getWeight(); });
}

void Present::sortPrice()
{
    std::sort(present.begin(), present.end(), [](std::shared_ptr<BaseSweet> a, std::shared_ptr<BaseSweet> b) { return a->getPrice() < b->getPrice(); });
}

void Present::sortSugar()
{
    std::sort(present.begin(), present.end(), [](std::shared_ptr<BaseSweet> a, std::shared_ptr<BaseSweet> b) { return a->getSugar() < b->getSugar(); });
}