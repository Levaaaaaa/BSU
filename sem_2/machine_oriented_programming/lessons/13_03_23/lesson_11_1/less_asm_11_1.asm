.586
.model flat
public _ChangeRawCalm@12

.code
_ChangeRawCalm@12 proc
xor ecx, ecx		;будем использовать как счётчик 
;mov ebp, [esp+4]	;загрузили массив указателей на строки (матрицу)
mov eax, [esp+8]	; заносим размер матрицы в eax

cycle:
	imul ecx			; получаем доступ к первому элементу нужной строки (eax)
	add eax, [esp+12]	;получаем доступ к НУЖНОМУ элементу нужной строки (eax)
	mov edi, eax		;индекс в столбце
	mov ebx, [esp+12]	;загружаем индекс, будем считать второй нужный элемент
	mov eax, [esp+8]	;заносим размер в eax
	imul ebx			;получаем доступ к первому элементу ВТОРОЙ НУЖНОЙ строки
	add eax, ecx		;получаем доступ ко ВТОРОМУ НУЖНОМУ элементу
	mov esi, eax;		;индекс в строке

	mov ebx, [esp+4]
	mov edx, [ebx][esi*4]	;меняем найденные элементы местами
	mov eax, [ebx][edi*4]
	mov [ebx][esi*4], eax
	mov [ebx][edi*4], edx

	inc ecx
	mov eax, [esp+8]
	cmp ecx, eax
jl cycle

ret 12
_ChangeRawCalm@12 endp
end