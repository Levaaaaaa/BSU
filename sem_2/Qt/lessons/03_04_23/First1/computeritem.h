#ifndef COMPUTERITEM_H
#define COMPUTERITEM_H

#include <string>
#include <list>
#include <fstream>
#include <QString>
class ComputerItem
{
public:
    ComputerItem() = default;
    ComputerItem(std::string _type, std::string _firm, std::string _model, std::string _parametres, double _price,
                 bool _isInStore):type(_type), firm(_firm), model(_model), parametres(_parametres), price(_price),
        isInStore(_isInStore){};
    ~ComputerItem() = default;
    std::string getType()const {return type;};
    std::string getFirm()const {return firm;};
    std::string getModel()const {return model;};
    std::string getParametres()const {return parametres;};
    double getPrice()const {return price;};
    bool getIsInStore()const {return isInStore;};
    std::string to_string() const {return type+" "+firm+" "+model+" "+parametres+" "+std::to_string(price)+" "+std::to_string(isInStore);}

    private:
    std::string type;
    std::string firm;
    std::string model;
    std::string parametres;
    double price;
    bool isInStore;
};

std::istream&operator>>(std::istream& in, ComputerItem& item);
std::ostream&operator<<(std::ostream& in, ComputerItem& item);
void ReadFromFile(std::list<ComputerItem>&, const std::string&);

#endif // COMPUTERITEM_H
