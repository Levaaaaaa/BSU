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
        finit		;�������������� ���� ������������
        fld x		;������� x � ����
        fabs		; |st(0)|
        fsqrt		; sqrt(st(0))
        fsubr y		;�������� �� y
        fld st(0)	;�������� �������� st(0) � st(1)
        fmul		;�������� � �������, ����������� st(0) � st(1)
        fild two    ;��������� 2
        fdiv        ;����� st(1) �� st(0)
        fstp result	;���������� ��������� � result
    }*/


    ptr = func(&x, &y);
    std::cout << *ptr << std::endl;
    return 0;
}