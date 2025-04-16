#pragma once

#include "AllIncludes.h"

class BasePlane
{

private:
    std::string type;
    double tonnage;
    double capacity;
    double longFly;
    double petrolConsumption;
public:
    BasePlane() = default;

    virtual ~BasePlane() = default;
    std::string getType() const { return type; }
    double getTonnage() const { return tonnage; }
    double getCapacity() const { return capacity; }
    double getLongFly() const { return longFly; }
    double getPetrolConsumtion() const { return petrolConsumption; }
    void setType(std::string _type) { type = _type; }
    void setTonnage(double _tonnage) { tonnage = _tonnage; }
    void setCapacity(double _capacity) { capacity = _capacity; }
    void setLongFly(double _longFly) { longFly = _longFly; }
    void setPetrolConsumption(double _petrolConsumption) { petrolConsumption = _petrolConsumption; }
    //virtual означает что метод будет переопределен в классе наследнике с точно таким же прототипом
    virtual std::istream& read(std::istream & in)
    {
        in >> type >> tonnage >> capacity >> longFly >> petrolConsumption;
        return in;
    }

    virtual std::ostream& print(std::ostream & out) const
    {
        out << std::left << "\ntype: " << std::setw(14) << type << "\n| tonnage " << std::setw(6) << tonnage << "\n| capacity " << std::setw(6) << capacity << "\n| How long fly " << std::setw(6) << longFly << "\n| Petrol consumption " << std::setw(6) << petrolConsumption;
        return out;
    }
};

std::ostream& operator<<(std::ostream& out, std::shared_ptr<BasePlane> ptr)
{
    ptr->print(out);
    return out;
}