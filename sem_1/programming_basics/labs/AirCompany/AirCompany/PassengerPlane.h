#pragma once

#include "BaseAir.h"

class PassengerPlane : public BasePlane
{

private:
    int countPassenges;
    double maxVolumeBaggage;
    bool isVIP;
public:
    PassengerPlane() = default;
    ~PassengerPlane() override = default; //override пишется так как используется виртуальный деструктор в базовом классе

    std::istream& read(std::istream & in) override
    {
        BasePlane::read(in);
        in >> countPassenges >> maxVolumeBaggage >> isVIP;
        return in;
    }

    std::ostream& print(std::ostream & out) const override
    {
        BasePlane::print(out);
        out << "\n| count of passenges " << countPassenges << "\n| volum of Baggage " << maxVolumeBaggage << "\n| is VIP " << isVIP << std::endl;
        return out;
    }
};