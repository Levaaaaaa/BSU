#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
    const int size1 = 10;
    int arr[size1] = { 1,2,3,4,5,10,6,7,8,9 };

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
            con:
                add ebx,4
        loop loop_
        
        mov ecx, edx
        add ecx, 1
        mov eax, ecx
        mov ecx,4 
        mul ecx
        mov ecx, eax
        lea ebx, arr
        add ebx, ecx
        ;neg edx
        ;add edx, ecx
        mov eax, 0
        loop2:
            mov [ebx], eax
            add ebx, 4
        loop loop2
    }

    std::copy(arr, arr + (size1-1), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}