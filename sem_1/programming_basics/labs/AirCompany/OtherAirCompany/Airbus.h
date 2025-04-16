#pragma once
#include "headers.h"

class Airbus : public Plane
{
private:
    std::string airport;
    size_t max_speed;
    size_t fuel_capacity;
public:
    Airbus() = default;
    ~Airbus() override = default; //override пишется так как используется виртуальный деструктор в базовом классе

    std::istream& read(std::istream& in) override
    {
        Plane::read(in);
        in >> airport >> max_speed >> fuel_capacity;
        return in;
    }

    std::ostream& print(std::ostream& out) const override
    {
        Plane::print(out);
        out << " | company " << airport << " | max max_speed " << max_speed << " | fuel_capacity " << fuel_capacity;
        return out;
    }
};