#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
    int size1 = 9;
    int arr[] = { 1,2,3,4,5,10,6,7,8,9 };

    _asm
    {
        lea ebx, arr
        mov ecx, size1
        mov eax, [ebx]
        mov edx, 0

        loop_:
        cmp eax, [ebx]
            jg con
            mov eax, [ebx]
            mov edx, ecx
            con :
        add ebx, 4
            loop loop_

            mov ecx, edx
            add ecx, 1
            mov eax, ecx
            mov edx, 4
            mul edx
            mov edx, eax
            lea ebx, arr
            add ebx, edx
            ; neg edx
            ; add edx, ecx
            
            mov eax, 0

            loop2:
        mov[ebx], eax
            add ebx, 4
            loop loop2
    }

    //std::copy(arr, arr + size1-1, std::ostream_iterator<int>(std::cout, " "));
    
    for (size_t i = 0; i < size1; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}