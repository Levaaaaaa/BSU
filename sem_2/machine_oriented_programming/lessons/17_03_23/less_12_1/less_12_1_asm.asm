.586
.model flat
public _CreateVectorB

.data
sumNeg dd 0
sumPos dd 0
n dd 0
m dd 0
arr dd 0
b dd 0
i dd 0		;текущий столбец
j dd 0		;текущая строка
cur dd 0
four dd 4
cur_res dd 0


.code
_CreateVectorB proc
mov eax, [esp+4]
mov arr, eax
mov eax, [esp+8]
mov n, eax			;кол-во строк
mov eax, [esp+12]
mov m, eax			;количество столбцов
mov eax, [esp+16]
mov b, eax

for_each_column:
	mov j, 0
	mov sumNeg, 0
	mov sumPos, 0

	for_each_element_in_column:

		mov eax, i		;получить доступ к текущему
		imul four
		mov ebx, eax
		mov eax, j
		imul four
		imul m
		add eax, ebx	;теперь в eax адрес текущего

		mov ebx, arr
		;add eax, ebx
		mov ecx, [ebx+eax]

		cmp ecx, 0
		jge pos
		add sumNeg, ecx
		jmp con
		pos:
			add sumPos, ecx
		con:
	mov ecx, j
	inc ecx
	mov j, ecx
	cmp ecx, n
	jl for_each_element_in_column
	
	;mov eax, sumNeg
	neg sumNeg
	mov ecx, sumNeg
	cmp ecx, sumPos
	je eq1
	mov ecx, -1
	jmp con1
	eq1:
	mov ecx, 1
con1:
mov eax, i
imul four
add eax, b	;теперь eax - адрес для записи результата
mov [eax], ecx
mov ecx, i
inc ecx
mov i, ecx
cmp ecx, m
jl for_each_column

ret
_CreateVectorB endp
end