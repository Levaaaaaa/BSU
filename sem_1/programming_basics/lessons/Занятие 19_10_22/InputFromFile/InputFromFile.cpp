// Strings.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cin;
using std::cout;

int main()
{
    // чтение из файла
    //std::ifstream fin("Input.txt"); // объявление потока для чтения
                                    // input.txt должен лежать в той же папке, что и .cpp файл
    setlocale(0, "");
    std::ifstream fin("InputFromFile.cpp");

    string str;
    /*int number;

    fin >> number;
    fin.ignore();
    std::getline(fin, str);

    cout << number << "\n";
    cout << str << "\n";
    */
    if (!fin.is_open()) //проверка открытия файла
    {
        std::cout << "File is not open";
        return 1;
    }
    while (!fin.eof())  //"пока не конец файла
    {
        std::getline(fin, str);
        cout << str << "\n";
    }

    return 0;
}