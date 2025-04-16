#pragma once

#include "BaseAir.h"

class FreightPlane : public BasePlane
{
private:
    std::string gruz;
    std::string typeOfGruz;
public:
    FreightPlane() = default;
    ~FreightPlane() override = default;

    std::istream& read(std::istream& in) override
    {
        BasePlane::read(in);
        in >> gruz >> typeOfGruz;
        return in;
    }

    std::ostream& print(std::ostream& out) const override
    {
        BasePlane::print(out);
        out << "\n| gruz: " << gruz << "\n| to " << typeOfGruz << std::endl;
        return out;
    }
};