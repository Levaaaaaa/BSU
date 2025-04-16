.586
.model flat
public @CreateVectorB@16

.data
n dd 0
m dd 0
;n1 dd 0
;m1 dd 0
arr dd 0
count dd 0
b dd 0
;i1 dd 0
;i2 dd 0
four dd 4
buff dd 0
i dd 0
cur dd 0
j dd 0

.code
@CreateVectorB@16 proc
mov eax, [esp+8]
mov b, eax
mov ebx, ecx
mov arr, ebx
mov eax, edx
mov n, edx
mov eax, [esp+4]
mov m, eax

for1:
mov j, 0
mov count, 0

for2:
mov eax, i
imul four
mov buff, eax

mov eax, j
imul four
imul n
add eax, buff

mov ecx, [ebx+eax]
mov cur, ecx
cmp ecx, 0
jz zero
jmp con

zero:
mov ecx, count
inc ecx
mov count, ecx

con:
mov ecx, j
inc ecx
mov j, ecx
cmp ecx, m
jl for2

mov eax, i
imul four
add eax, b
mov ecx, count
mov [eax], ecx

mov ecx, i
inc ecx
mov i, ecx
cmp ecx, n
jl for1

ret
@CreateVectorB@16 endp
end