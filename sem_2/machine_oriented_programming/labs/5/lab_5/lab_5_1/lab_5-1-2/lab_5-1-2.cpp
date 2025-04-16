#include <iostream>
#include <cmath>

extern "C" float* _stdcall function(float x, float y);

int main()
{
    float x = 0.5;
    float y = 0.75;
    float result;
    float result1 = x * x * tan(x / y) + y * y * (1 / tan(x / y));
    //float t;
    std::cout << result1 << "\n";
    /*_asm
    {
        finit
        fld x
        fld y
        fdiv
        fptan
        fstp t
        fstp t
        fld x
        fmul x
        fmul t

        fstp result

        fld1
        fld t
        fdiv
        fstp t
        fld y
        fmul y
        fmul t

        fld result
        fadd
        fstp result
    }*/
    
    //result = *function(&x, &y);

    std::cout << *function(x, y) << "\n";
    
    return 0;
}