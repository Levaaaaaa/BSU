// 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

/*Создать функцию, удаляющую заданную строку двумерного динамического массива.*/

using std::cout;
using std::cin;
using std::vector;

void printVector(vector<vector<int>> v1);
void DeleteRow(vector<vector<int>>&, int pos);

int main()
{
    vector<vector<int>> v = { {1,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4} };
    printVector(v);
    cout << "\n\n";
    int pos = 1;
    DeleteRow(v, pos);
    printVector(v);
}

void DeleteRow(vector<vector<int>>& v, int pos)
{

    for (size_t i = pos; i < v.size()-1;i++)
    {
        v[i] = v[i + 1];
    } 
    v.pop_back();
}

void printVector(vector<vector<int>> v1)
{
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v1[i].size(); j++)
        {
            cout << v1[i][j] << " ";
        }
        cout << "\n";
    }
}

