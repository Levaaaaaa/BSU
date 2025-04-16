#pragma once
#include "headers.h"

class BaseSweet
{
private:
    std::string name;
    double weight;
    double price;
    double sugar;
public:
    BaseSweet() = default;

    //virtual используется бля правильного удаления объектов (если не указать слово virtual, то вывовется только деструктор базового класса)
    //в полиморфных классах деструктор обязательно должен быть виртуальным, чтобы динамически определялся тип объекта, который нужно удалить
    virtual ~BaseSweet() = default;
    std::string getName() const { return name; }
    double getWeight() const { return weight; }
    double getPrice() const { return price; }
    double getSugar() const { return sugar; }
    void setName(std::string _name) { name = _name; }
    void setWeight(double _weight) { weight = _weight; }
    void setPrice(double _price) { price = _price; }
    void setSugar(double _sugar) { sugar = _sugar; }

    //virtual означает что метод будет переопределен в классе наследнике с точно таким же прототипом
    virtual std::istream& read(std::istream& in)
    {
        in >> name >> weight >> price >> sugar;
        return in;
    }

    //virtual означает что метод будет переопределен в классе наследнике с точно таким же прототипом
    virtual std::ostream& print(std::ostream& out) const
    {
        out << std::left << "name " << std::setw(14) << name << "| weight " << std::setw(6) << weight << "| price " << std::setw(6) << price << "| sugar " << std::setw(6) << sugar;
        return out;
    }
};

//перегрузка << нужна для потокового итератора
std::ostream& operator<<(std::ostream& out, std::shared_ptr<BaseSweet> ptr)
{
    ptr->print(out);
    return out;
}