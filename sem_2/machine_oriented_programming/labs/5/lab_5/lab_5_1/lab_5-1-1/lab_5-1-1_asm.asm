.586
.model flat

public _func@8

.data

two dd 2
result dd 0

_func@8 proc
        finit		;�������������� ���� ������������
        fld dword ptr [esp+4]		;������� x � ����
        fabs		; |st(0)|
        fsqrt		; sqrt(st(0))
        fsubr dword ptr [esp+8]	;�������� �� y
        fld st(0)	;�������� �������� st(0) � st(1)
        fmul		;�������� � �������, ����������� st(0) � st(1)
        fild two    ;��������� 2
        fdiv        ;����� st(1) �� st(0)
        fstp result;���������� ��������� � result

        lea eax, result
ret 8
_func@8 endp
end