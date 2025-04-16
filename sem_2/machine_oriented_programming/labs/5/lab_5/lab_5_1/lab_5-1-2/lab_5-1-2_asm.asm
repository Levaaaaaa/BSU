.586
.model flat
public _function@8

.data
t dd 0
x dd 0.0
y dd 0.0
result dd 0.0

.code
_function@8 proc

        mov ebx, [esp+4]
        mov x, ebx
        mov ebx, [esp+8]
        mov y, ebx

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

        lea eax, result
ret 8
_function@8 endp
end