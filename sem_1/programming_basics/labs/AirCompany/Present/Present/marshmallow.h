#pragma once
#include "headers.h"

class Marshmallow : public BaseSweet
{
private:
    bool inChocolate;
    std::string flavor;
public:
    Marshmallow() = default;
    ~Marshmallow() override = default;

    std::istream& read(std::istream& in) override
    {
        BaseSweet::read(in);
        in >> inChocolate >> flavor;
        return in;
    }

    std::ostream& print(std::ostream& out) const override
    {
        BaseSweet::print(out);
        out << " | chocolate " << inChocolate << " | flavor " << flavor;
        return out;
    }
};