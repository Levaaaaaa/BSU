// Train.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "TrainClass.h"

int main()
{
    TRAIN main;
    TRAIN train1("Minsk", 1, false);
    TRAIN train2("Brest", 2, true);
    TRAIN train3("Mogilev", 3, true);
    TRAIN train4(train1);
    TRAIN train5("Polotsk", 4, false);

    std::vector<TRAIN> trains = { train1, train2, train3, train4, train5 };

    std::string destination;

    std::cout << "Enter the destination ";
    std::cin >> destination;

    main.printVectorOfTrainsToDestination(trains, destination);
    main.printVectorOfExpress(trains, destination);

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
