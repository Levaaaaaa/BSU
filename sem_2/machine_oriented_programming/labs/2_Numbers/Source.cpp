#include <string>
#include <map>
#include <iostream>

void lower_bound(std::multimap<int, std::string>, int);

int main() 
{
    setlocale(LC_ALL, "");
    std::multimap <int, std::string> numbers = { { 1, "����" },
                                            { 1, "����" },
                                            { 1, "one" },
                                            { 2, "���" },
                                            { 2, "two" },
                                            { 3, "���" },
                                            { 3, "���" },
                                            { 3, "three" },
                                            { 4, "������" },
                                            { 4, "������" },
                                            { 4, "four" } };

    std::cout << "Enter the number ";
    int n;
    std::cin >> n;
    lower_bound(numbers, n);
    return 0;
}

void lower_bound(std::multimap<int, std::string> map, int n)
{
    std::string result;
    std::map<int, std::string>::iterator it = map.begin();

    while (it != map.end()) {
        if (it->first == n) result += it->second + "\n";
        it++;
    }
    if (result.empty()) std::cout << "This number isn't in map";
    else std::cout << result << "\n";
}