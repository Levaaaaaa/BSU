#include "computeritem.h"

std::istream&operator>>(std::istream& in, ComputerItem& item)
{
    std::string t, f, m, par;
    double price;
    bool isIn;
    in >> t >> f >> m >> par >> price >> isIn;
    item=ComputerItem(t, f, m, par, price, isIn);
    return in;
};

/*std::ostream& operator<< (std::ostream& out, ComputerItem& item)
{

}*/

void ReadFromFile(std::list<ComputerItem>& itemsList, const std::string& filename)
{
    std::ifstream fin;
    fin.open(filename);
    ComputerItem item;
    while(fin>>item) {
        itemsList.push_back(item);
    }
};


