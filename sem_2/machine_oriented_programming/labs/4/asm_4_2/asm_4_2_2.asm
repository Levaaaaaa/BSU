.586
.model flat

public _countEvenDigit@4

.data
x1 dd 0

.code
_countEvenDigit@4 proc
mov eax, [esp+4]
mov ebx, 0;count-result
;mov el, 0;текущая цифра

while1:
mov eax, x1
mov ecx, 10;текущий делитель
cdq
idiv ecx
mov x1, eax
mov eax, edx
;mov el, edx
mov ecx, 2
cdq
idiv ecx
cmp edx, 0
jz even1
jmp con

even1:
inc ebx

con:
cmp x1, 0
jnz while1

mov eax, ebx

_countEvenDigit@4 endp
end