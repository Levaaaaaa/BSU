#pragma once
#include "headers.h"

class Chocolate : public BaseSweet
{
private:
    double cacao;
    std::string type;
    bool filling;
public:
    Chocolate() = default;
    ~Chocolate() override = default; //override пишется так как используется виртуальный деструктор в базовом классе

    std::istream& read(std::istream& in) override
    {
        BaseSweet::read(in);
        in >> cacao >> type >> filling;
        return in;
    }

    std::ostream& print(std::ostream& out) const override
    {
        BaseSweet::print(out);
        out << " | cacao " << cacao << " | type " << type << " | filling " << filling;
        return out;
    }
};