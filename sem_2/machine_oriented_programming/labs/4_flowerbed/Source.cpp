#include <fstream>
#include <map>
#include <list>
#include <sstream>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>

#include "FlowerbedClass.h"

int stringToInt(std::string);
std::list<Flowerbed> locate();
std::vector<std::string> allFlowers(std::list<Flowerbed>);
void printAllFlowers(std::list<Flowerbed>);
//std::list<Flowerbed> sortByFigure(std::list<Flowerbed>);
std::string vectorToString(const std::vector<std::string>&);
std::multimap<std::string, Flowerbed> locateInMap(const std::list<Flowerbed>&);
std::multimap<std::string, Flowerbed> findInMap(const std::multimap<std::string, Flowerbed>&, std::string);
std::set<std::string> allFigures(const std::multimap<std::string, Flowerbed>&);
void printAllFigures(const std::multimap<std::string, Flowerbed>&);

int main()
{
    std::list<Flowerbed> flowersList = locate();
    printAllFlowers(flowersList);
    flowersList.sort();

    std::multimap<std::string, Flowerbed> flowersMap = locateInMap(flowersList);
    std::cout << "\n";

    printAllFigures(flowersMap);
    
    return 0;
}

void printAllFigures(const std::multimap<std::string, Flowerbed>& map)
{
    std::set<std::string> set = allFigures(map);
    std::copy(set.begin(), set.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << "\n";
}
std::set<std::string> allFigures(const std::multimap<std::string, Flowerbed>& map)
{
    std::set<std::string> res;
    for (const auto& e : map) {
        res.insert(e.first);
    }
    return res;
}

std::multimap<std::string, Flowerbed> findInMap(const std::multimap<std::string, Flowerbed>& map, std::string flower)
{
    //std::find_if(map.begin(), map.end(), [&map, flower](std::map<std::string, Flowerbed>::iterator it) {return isElementInVector(it->second.flowers, flower); });
    std::multimap<std::string, Flowerbed> res;
    for (const auto& entry : map) {
        if (!isElementInVector(entry.second.flowers, flower)) res.insert(entry);
    }
    return res;
}
std::multimap<std::string, Flowerbed> locateInMap(const std::list<Flowerbed>& list)
{
    std::multimap<std::string, Flowerbed> res;
    for (Flowerbed f : list)
    {
        res.insert(make_pair(f.figure, f));
    }
    return res;
}

/*
std::list<Flowerbed> sortByFigure(std::list<Flowerbed> list)
{
    list.sort();
    return list;
}
*/
std::vector<std::string> allFlowers(std::list<Flowerbed> list)   //составить массив всех видов цветов
{
    std::vector<std::string> allFlowers = list.begin()->flowers;
    //std::string allFlowers
    for (std::list<Flowerbed>::iterator it = ++list.begin(); it != list.end(); it++)
    {
        for (int j = 0; j < it->flowers.size(); j++) {
            if (!isElementInVector(allFlowers, it->flowers[j])) allFlowers.push_back(it->flowers[j]);
        }
    }
    return allFlowers;
}

void printAllFlowers(std::list<Flowerbed> list)
{
    std::vector<std::string> flowers = allFlowers(list);
    std::cout << "All flowers: ";
    for (size_t i = 0; i < flowers.size(); i++) {
        std::cout << flowers[i] << ", ";
    }
    std::cout << "\n";
}

std::list<Flowerbed> locate() 
{
    std::list<Flowerbed> bed_list;
    std::ifstream fin("Text.txt");

    while (!fin.eof()) {
        std::string line = "";
        std::getline(fin, line);

        std::string n = "";
        std::string fig = "";
        std::vector<std::string> flowers = {};

        std::vector<std::string> all = {};

        std::string tmp = "";
        int i = 0;

        do {
            if (line[i] != ' ') tmp += line[i];
            else {
                all.push_back(tmp);
                tmp = "";
            }
            i++;
        } while (i < line.size());

        for (size_t i = 2; i < all.size(); i++)
        {
            flowers.push_back(all[i]);
        }
        bed_list.push_back(*(new Flowerbed(stringToInt(all[0]), all[1], flowers)));

    }

    return bed_list;
}
int stringToInt(std::string s)
{
    std::stringstream str;
    str << s;
    int n;
    str >> n;

    return n;
}

std::string vectorToString(const std::vector<std::string>& v)
{
    std::string result = "";
    //    std::for_each(v.begin(), v.end(), [&result, &v](int i = 0) {result += v[i];});
    for (size_t i = 0; i < v.size(); i++)
    {
        result += v[i] + " ";
    }

    return result;
}

std::ostream& operator<< (std::ostream& os, Flowerbed f)
{
    return os << f.num << " || " << f.figure << " || " << vectorToString(f.flowers) << "\n";
}