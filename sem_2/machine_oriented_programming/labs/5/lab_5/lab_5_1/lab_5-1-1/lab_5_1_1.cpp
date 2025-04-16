#include <iostream>

extern "C" float* _stdcall func(float* x, float* y);

int main()
{
    float x = -0.5;
    float y = 0.75;
    float result = 0;
    float* ptr = &result;
    float result1 = pow(y-sqrt(abs(x)),2)/2;
    int two = 2;
    std::cout << result1 << std::endl;

    /*_asm
    {
        finit		;инициализируем блок сопроцессора
        fld x		;заносим x в стек
        fabs		; |st(0)|
        fsqrt		; sqrt(st(0))
        fsubr y		;отнимаем от y
        fld st(0)	;копируем значение st(0) в st(1)
        fmul		;возводим в квадрат, перемножаем st(0) и st(1)
        fild two    ;загружаем 2
        fdiv        ;делим st(1) на st(0)
        fstp result	;перемещаем результат в result
    }*/


    ptr = func(&x, &y);
    std::cout << *ptr << std::endl;
    return 0;
}