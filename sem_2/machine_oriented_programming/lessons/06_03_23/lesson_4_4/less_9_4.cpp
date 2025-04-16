#include <iostream>
#include <cmath>

extern "C" float* _stdcall function4(float x, float y);

int main()
{
    float x = 0.5;
    float y = 0.75;
    float result;
    float result1 = abs(x-y)*cos(x/y+y/x);
    std::cout << result1 << "\n";
    //float buff;
    _asm
    {
        //finit
        //fld x
        //fld y
        //fdiv
        //fstp buff
        //fld y
        //fld x
        //fdiv
        //fld buff
        //fadd
        //fcos
        //fstp result

        //fld x
        //fld y
        //fsub
        //fabs
        //fld result
        //fmul
        //fstp result
    }

    result = *function4(x, y);
    std::cout << result << "\n";
    return 0;
}