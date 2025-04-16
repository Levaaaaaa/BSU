#pragma once
#include "headers.h"

class Boeing : public Plane
{
private:
    size_t model;
    double max_height;
    double min_height;
public:
    Boeing() = default;
    ~Boeing() override = default; //override пишется так как используется виртуальный деструктор в базовом классе

    std::istream& read(std::istream& in) override
    {
        Plane::read(in);
        in >> model >> max_height >> min_height;
        return in;
    }

    std::ostream& print(std::ostream& out) const override
    {
        Plane::print(out);
        out << " | serie " << model << " | max height " << max_height << " | min height " << min_height;
        return out;
    }
};