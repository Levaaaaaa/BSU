#pragma once
#include "headers.h"

std::shared_ptr<BaseSweet> ptr(char);

class Sweet
{
public:
    std::vector<std::shared_ptr<BaseSweet>> sweets;

    Sweet() = default;
    ~Sweet() = default;

    void read(std::istream&);
    void print(std::ostream&);
    void sortWeight();
    void sortPrice();
    void sortSugar();
};

std::shared_ptr<BaseSweet> ptr(char choise)
{
    switch (choise)
    {
    case 'c':
    {
        return std::make_shared<Chocolate>();
        break;
    }
    case 'm':
    {
        return std::make_shared<Marshmallow>();
        break;
    }
    case 'l':
    {
        return std::make_shared<Lollypop>();
        break;
    }
    default:
    {
        return nullptr;
    }
    }
}

void Sweet::read(std::istream& file)
{
    while (!file.eof())
    {
        char symbol;
        file >> symbol;
        sweets.push_back(ptr(symbol));
        std::string str;
        getline(file, str);
        std::istringstream ss(str);
        sweets.back()->read(ss);
    }
}

void Sweet::print(std::ostream& out)
{
    std::copy(sweets.begin(), sweets.end(), std::ostream_iterator<std::shared_ptr<BaseSweet>>(out, "\n"));
}

void Sweet::sortWeight()
{
    std::sort(sweets.begin(), sweets.end(), [](std::shared_ptr<BaseSweet> a, std::shared_ptr<BaseSweet> b) {return a->getWeight() > b->getWeight(); });
}

void Sweet::sortPrice()
{
    std::sort(sweets.begin(), sweets.end(), [](std::shared_ptr<BaseSweet> a, std::shared_ptr<BaseSweet> b) { return a->getPrice() > b->getPrice(); });
}

void Sweet::sortSugar()
{
    std::sort(sweets.begin(), sweets.end(), [](std::shared_ptr<BaseSweet> a, std::shared_ptr<BaseSweet> b) { return a->getSugar() > b->getSugar(); });
}