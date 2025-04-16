.586
.model flat
public _FindSaddlePoints@16

.data
arr dd 0	;массив
n dd 0		
m dd 0
result dd 0
i dd 0				;текущий элемент строки
j dd 0				;текущий элемент столбца
min_i dd 0			;минимальный элемент строки (индекс)
max_j dd 0			;максимальный элемент столбца (индекс)
cur_str dd 0		;текущая строка (номер)
count_sedl dd 0		;количество седловых точек
four dd 4			
buff dd 0			; буфер
cur_sedl dd 0		;текущая седловая точка (для загрузки в result)

.code
_FindSaddlePoints@16 proc
mov eax, [esp+4]
mov arr, eax
mov eax, [esp+8]
mov n, eax
mov eax, [esp+12]
mov m, eax
mov eax, [esp+16]
mov result, eax


;mov min_i, 0
;mov cur_i, 1

for_each_str:
    mov min_i, 0
    mov max_j, 0
    mov i, 0
    mov j, 0

    find_min:				;здесь находим минимум в текущей строке
        mov eax, cur_str	;\
        imul n				;-	получить начало строки (адрес)
        imul four			;/
        ;add eax, min_i

        ;mov edx, i
        ;mov ebx, arr
        mov ebx, eax		;сохранить адрес начала строки
        mov eax, min_i		;\
        imul four			;-  получить промежуточный минимальный элемент в строке
        add eax, ebx        ; получить полный адрес этого элемента
        mov ebx, arr        
        mov ecx, [ebx+eax]	;промежуточный минимальный

        mov eax, cur_str    ;аналогично получить текущий элемент
        imul n
        imul four
        mov ebx, eax

        mov eax, i
        imul four
        add eax, ebx
        mov ebx, arr
        cmp ecx, [ebx+eax]      ;сравнить текущий и промежуточный минимальный
        jg swap_min             ; если минимальный больше, то текущий становится минимальным
        jmp no_swap             ; иначе переходим к след. текущему элементу

        swap_min:       
        mov ebx, i
        mov min_i, ebx

        ;mov ecx, cur_i
        ;inc ecx
        ;mov cur_i, ecx
    no_swap:
    mov ecx, i              ;увеличим номер текущего элемента в строке
    inc ecx
    mov i, ecx
    ;mov edx, n
    cmp ecx, n	;
    jl find_min

    mov i, 0

    for_each_min:           ;этот блок обработает элементы, равные минимальному, сравнит их с максимальными в своих строках
        mov ebx, arr        ;идём сначала строки, сравниваем с минимальным
        mov eax, cur_str
        imul n
        imul four
        mov ecx, eax
        mov eax, i;min_i
        imul four
        add eax, ecx        ;получить полный адрес текущего элемента
        mov ecx, [ebx+eax]	;текущий, проверить на минимум
        mov eax, min_i      
        imul four
        mov ebx, eax
        mov eax, cur_str
        imul n
        imul four
        add eax, ebx
        mov ebx, arr 
        ;mov edx, [ebx+eax]  ;получаем полный адрес минимального в строке (отладочное значение)  
        cmp ecx, [ebx+eax]      ;сравним текущий с минимальным
        je equal1               ;если равны - найти максимальный элемент в столбце текущего
        jmp con

    equal1:
        mov j, 0                
        find_max:               ;этот блок ищет максимальный элемент в i-том столбце

            mov eax, max_j      
            imul n          
            imul four           
            mov buff, eax       ;получим начало нужной строки
            mov eax, i
            imul four           ; получим номер промежуточного максимального в строке
            add eax, buff       ;получим полный адрес промежуточного максимального
            mov ebx, arr
            mov ecx, [ebx+eax]  ;найдем промежуточный максимальный
    
            mov eax, j		;номер строки текущего
            imul n
            imul four
            mov ebx, eax
            mov eax, i
            imul four
            add eax, ebx        ;аналогично получим полный адрес текущего

            ;add eax, edx
            mov ebx, arr
            cmp ecx, [ebx+eax]      ;сравним промежуточный максимальный с текущим
            jl swap_max             ;если максимальный меньше, меняем его
            jmp no_swap_max

            swap_max:
            mov ebx, j
            mov max_j, ebx

            no_swap_max:            ;если нет - меняем текущий
            mov ecx, j  
            inc ecx
            mov j, ecx
            cmp ecx, m	;
        jl find_max

        ;mov ecx, max_j             ;теперь номер максимального в столбце хранится в max_j
        mov eax, cur_str            
        imul n
        imul four
        mov ebx, eax
        mov eax, i                  
        imul four
        add eax, ebx                ;получим полный адрес одного из минимальных элементов в строке
        
        mov ebx, arr
        mov ecx, [ebx+eax]	;минимальный в строке, стравнить с макс в столбце

        mov eax, max_j
        imul n
        imul four
        ;add eax, i
        mov ebx, eax
        mov eax, i
        imul four
        add eax, ebx        ;получим макс элемент в столбце

        mov ebx, arr
        cmp [ebx+eax], ecx      ;сравним
        je is_sedl              ;если совпадают - значит это седловая точка
        jmp con                 ;если нет - проверим другой минимальный в строке

        is_sedl:
        
        ;mov ebx, arr
        ;mov eax, result
        mov cur_sedl, ecx       ;сохраним текущий седловой элемент
        mov eax, count_sedl
        imul four
        add eax, result     ; получим адрес для записи в result
        mov ecx, eax		;записывать результат по адресу в ecx
        ;mov eax, max_j
        ;imul n
        ;mov ebx, eax
        ;mov eax, i
        ;imul four
        ;add eax, ebx
        ;mov ebx, arr
        ;mov edx, [ebx+eax]
        mov edx, cur_sedl       
        mov [ecx], edx          ;запишем текущий седловой
        mov edx, count_sedl     
        inc edx
        mov count_sedl, edx     ;увеличим количество седловых элементов

        ;mov eax, max_j
        ;imul n
        ;mov edx, [ebx+eax+i]
        
    con:
    mov ecx, i
    inc ecx
    mov i, ecx      ;перейдём к следующему элементу текущей строки
    cmp ecx, n
    jl for_each_min

mov ecx, cur_str
inc ecx
mov cur_str, ecx        ;перейдём к следующей строке
cmp ecx, m
jl for_each_str

mov eax, count_sedl
ret 16
_FindSaddlePoints@16 endp
end