#include <iostream>
#include <algorithm>
#include <iterator>

//посчитать кол-во уникальных эл-тов в динамическом массиве
//посчитать частоту появления различных эл-тов в массиве

int main()
{
    int size1 = 10;
    int* arr = new int[size1] {2, 5, 7, 4, 4, 2, 1, 4, 9, 8};
    //std::copy(arr, arr + (size1 * 4), std::ostream_iterator(&std::cout, " "));
    int frequence[100]{ 0 };
    int countDifferentElements;
    int count = 0;
    int mostFreequent = 0;
    int index = 0;

    _asm
    {
        mov ecx, size1
        mov esi, arr; динамический массив
        lea edi, frequence; статический массив
        mov edx, 0; второй счётчик

        loop_:
            mov eax, [esi][edx*4];  <=> *(arr+i)
            inc [edi][eax*4];инкрементируем eax-позицию, заполнили массив частот
            inc edx
        loop loop_

        mov ecx, 100
        mov edx, 0; индекс для пробега по массиву
        mov eax, 0;кол-во уникальных эл-тов
        mov ebx, [edx];наиболее часто встречающийся эл-т (максимальый эл-т в статич. массиве)

        cycle_:
            cmp [edi][edx*4], 0
            jle con
                inc eax
            cmp [edi][edx*4], ebx
            jle con
                mov ebx, [edi][edx*4]
                mov index, edx
            con:
                inc edx
        loop cycle_

        mov count, eax
        mov mostFreequent, ebx
    }

    std::cout << "number of unique elements " << count << "\nmax element is" << index << "\n" << mostFreequent;

    return 0;
}