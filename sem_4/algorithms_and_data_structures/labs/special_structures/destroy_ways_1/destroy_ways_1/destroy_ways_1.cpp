// destroy_ways_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
* »спользуем структуру DSU в виде дерева,
* храним в массиве
* лидеры отмечены отрицательными числами - по модулю размер группы
* —пособ хранени€ by eps
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

__int32 FindSet(vector<__int32>& set, __int32 x) {
    __int32 k = x;
    while (set[k] > 0) {
        k = set[k];
    }

    return k;
}

bool Union(vector<__int32>& set, __int32 x, __int32 y) {
    __int32 lead1 = FindSet(set, x);
    __int32 lead2 = FindSet(set, y);

    if (lead1 == lead2) {
        return false;
    }


    __int32 min_lead = set[lead1] <= set[lead2] ? lead2 : lead1;
    __int32 max_lead = set[lead1] > set[lead2] ? lead2 : lead1;

    set[max_lead] += set[min_lead];
    set[min_lead] = max_lead;

    return true;
}
int main()
{
    __int32 n, m, q;
    ifstream in("input.txt");
    
    std::ios_base::sync_with_stdio(false);
    in.tie(nullptr);
    
    in >> n >> m >> q;
    vector<__int32> cities(n+1, -1);
    vector<pair<__int32, __int32>> ways(m);
    vector<__int32> destroy_order(q);
    vector<bool> is_damaged_way(m, false);

    pair<__int32, __int32> way;
    for (__int32 i = 0; i < m; i++) {
        in >> way.first >> way.second;
        ways[i] = way;
    }

    for (__int32 i = 0; i < q; i++) {
        in >> destroy_order[i];
        is_damaged_way[destroy_order[i]-1] = true;
    }

    in.close();


    __int32 component_count = n;
    pair<__int32, __int32> way_undamaged;
    for (__int32 i = 0; i < m; i++) {
        if (!is_damaged_way[i]) {    //если дорогу не надо разрушать
            way_undamaged = ways[i];
            if (Union(cities, way_undamaged.first, way_undamaged.second)) {
                component_count--;
            }
        }
    }
    vector<bool> result(q, false);
    pair<__int32, __int32> destroy;
    //создаем дороги
    for (__int32 i = q - 1; i >= 0; i--) {
        if (component_count == 1) {
            result[i] = true;
            continue;
        }
        destroy = ways[destroy_order[i]-1];
        if (Union(cities, destroy.first, destroy.second)) {     //соедин€ем две компоненты
            component_count--;
        }
    }

    ofstream out("output.txt");
    for (__int32 i = 0; i < q; i++) {
        out << result[i];
    }

    out.close();

    return 0;
}

/*
    граф не св€зен, если в DSU больше одного лидера.
     ак удал€ть дороги из DSU?
    Ќичего не удал€ем
    Ѕудем читать список удалени€ в обратном пор€дке и создавать дороги в пустом графе
    если кол-во компонент св€зности - 1, то в строку-результат записываем 1 (если нет - 0)
    разворачиваем строку-результат и выводим

    ќшибка. Ќе проход€т 10/49 тестов
    ѕолагаю, что причина в тех дорогах, которые есть в списке дорог, но которые не надо разрушать. 
    ћой алгоритм не учитывает эти дороги, т.к. создает только дороги из списка разрушени€ (надо проверить)
     ак исправить?
    —оздать все неразрушаемые дороги заранее, перед тем, как создавать разрушаемые
*/