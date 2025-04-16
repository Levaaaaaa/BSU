#pragma once
#include "headers.h"

class Tupolev : public Plane
{
private:
    std::string pilot;
    std::string color;
    size_t yearOfProduction;
public:
    Tupolev() = default;
    ~Tupolev() override = default; //override пишется так как используется виртуальный деструктор в базовом классе

    std::istream& read(std::istream& in) override
    {
        Plane::read(in);
        in >> pilot >> color >> yearOfProduction;
        return in;
    }

    std::ostream& print(std::ostream& out) const override
    {
        Plane::print(out);
        out << " | pilot " << pilot << " | color " << color << " | max weight " << yearOfProduction;
        return out;
    }
};