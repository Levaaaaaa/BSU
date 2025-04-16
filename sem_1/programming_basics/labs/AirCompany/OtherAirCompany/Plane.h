
#pragma once
#include "headers.h"

class Plane
{
private:
    std::string firm;
    size_t passengers_capacity;
    size_t load_capacity;
    size_t range;
    double fuel_consumption;
public:
    Plane() = default;

    //virtual ������������ ��� ����������� �������� �������� (���� �� ������� ����� virtual, �� ��������� ������ ���������� �������� ������)
    //� ����������� ������� ���������� ����������� ������ ���� �����������, ����� ����������� ����������� ��� �������, ������� ����� �������
    virtual ~Plane() = default;
    std::string getModel() const { return firm; }
    size_t getPassengersCapacity() const { return passengers_capacity; }
    size_t getLoadCapacity() const { return load_capacity; }
    size_t getRange() const { return range; }
    double getFuelConsumption() const { return fuel_consumption; }
    void setModel(std::string _model) { firm = _model; }
    void setPassengersCapacity(size_t _passengers_capacity) { passengers_capacity = _passengers_capacity; }
    void setLoadCapacity(size_t _load_capacity) { load_capacity = _load_capacity; }
    void setRange(size_t _range) { range = _range; }
    void setFuelConsumption(double _fuel_consumption) { fuel_consumption = _fuel_consumption; }

    //virtual �������� ��� ����� ����� ������������� � ������ ���������� � ����� ����� �� ����������
    virtual std::istream& read(std::istream& in)
    {
        in >> firm >> passengers_capacity >> load_capacity >> range >> fuel_consumption;
        return in;
    }

    //virtual �������� ��� ����� ����� ������������� � ������ ���������� � ����� ����� �� ����������
    virtual std::ostream& print(std::ostream& out) const
    {
        out << std::left << "model " << std::setw(14) << firm << "| passengers capacity " << std::setw(6) << passengers_capacity << "| load capacity " << std::setw(6) << load_capacity << "| range " << std::setw(6) << range << "| fuel comsumption " << std::setw(6) << fuel_consumption;
        return out;
    }
};

//���������� << ����� ��� ���������� ���������
std::ostream& operator<<(std::ostream& out, std::shared_ptr<Plane> ptr)
{
    ptr->print(out);
    return out;
}