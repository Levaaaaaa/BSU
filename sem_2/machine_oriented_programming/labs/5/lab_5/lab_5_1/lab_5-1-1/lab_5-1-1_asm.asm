.586
.model flat

public _func@8

.data

two dd 2
result dd 0

_func@8 proc
        finit		;инициализируем блок сопроцессора
        fld dword ptr [esp+4]		;заносим x в стек
        fabs		; |st(0)|
        fsqrt		; sqrt(st(0))
        fsubr dword ptr [esp+8]	;отнимаем от y
        fld st(0)	;копируем значение st(0) в st(1)
        fmul		;возводим в квадрат, перемножаем st(0) и st(1)
        fild two    ;загружаем 2
        fdiv        ;делим st(1) на st(0)
        fstp result;перемещаем результат в result

        lea eax, result
ret 8
_func@8 endp
end