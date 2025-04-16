.586
.model flat

public _sumNum@12

.data
sumDigit dd 0
countEven dd 0
number dd 0
newnum dd 0

.code

_sumNum@12 proc
mov eax, [esp+4]
mov number, eax
mov ebx, 0
mov ecx, 10

while1:
mov eax, number
mov ecx, 10
cdq
idiv ecx
mov number, eax
add ebx, edx
mov ecx, 2
mov eax, edx
cdq
idiv ecx
cmp edx, 0
jz even1
jmp con
even1:
inc countEven
con:
cmp number,0
jne while1

mov sumDigit, ebx
mov ecx, [esp+8]
mov ebx, countEven
mov [ecx], ebx

mov eax, [esp+4]
mov number, eax
xor ebx, ebx
mov ecx, 10
xor edx, edx

while2:
mov eax, newnum
imul ecx
mov newnum, eax
mov eax, number
cdq 
idiv ecx
mov number, eax
add newnum, edx
cmp number, 0
jnz while2

mov ecx, [esp+12]
mov ebx, [esp+4]
cmp newnum, ebx
jne neq
mov edx, 1
neq:
mov edx, 0
mov ecx, edx
mov eax, sumDigit
ret 12
_sumNum@12 endp
end