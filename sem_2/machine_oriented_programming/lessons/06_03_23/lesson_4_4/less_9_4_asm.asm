.586
.model flat
public _function4@8

.data
x dd 0
y dd 0
result dd 0
buff dd 0

.code
_function4@8 proc

        mov eax, [esp+4]
        mov x, eax
        mov eax, [esp+8]
        mov y, eax

        finit
        fld x
        fld y
        fdiv
        fstp buff
        fld y
        fld x
        fdiv
        fld buff
        fadd
        fcos
        fstp result

        fld x
        fld y
        fsub
        fabs
        fld result
        fmul
        fstp result

        lea eax, result
        ret 8
_function4@8 endp
end