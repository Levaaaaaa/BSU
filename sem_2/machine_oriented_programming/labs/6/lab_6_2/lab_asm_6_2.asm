.586
.model flat
public _FindSaddlePoints@16

.data
arr dd 0	;������
n dd 0		
m dd 0
result dd 0
i dd 0				;������� ������� ������
j dd 0				;������� ������� �������
min_i dd 0			;����������� ������� ������ (������)
max_j dd 0			;������������ ������� ������� (������)
cur_str dd 0		;������� ������ (�����)
count_sedl dd 0		;���������� �������� �����
four dd 4			
buff dd 0			; �����
cur_sedl dd 0		;������� �������� ����� (��� �������� � result)

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

    find_min:				;����� ������� ������� � ������� ������
        mov eax, cur_str	;\
        imul n				;-	�������� ������ ������ (�����)
        imul four			;/
        ;add eax, min_i

        ;mov edx, i
        ;mov ebx, arr
        mov ebx, eax		;��������� ����� ������ ������
        mov eax, min_i		;\
        imul four			;-  �������� ������������� ����������� ������� � ������
        add eax, ebx        ; �������� ������ ����� ����� ��������
        mov ebx, arr        
        mov ecx, [ebx+eax]	;������������� �����������

        mov eax, cur_str    ;���������� �������� ������� �������
        imul n
        imul four
        mov ebx, eax

        mov eax, i
        imul four
        add eax, ebx
        mov ebx, arr
        cmp ecx, [ebx+eax]      ;�������� ������� � ������������� �����������
        jg swap_min             ; ���� ����������� ������, �� ������� ���������� �����������
        jmp no_swap             ; ����� ��������� � ����. �������� ��������

        swap_min:       
        mov ebx, i
        mov min_i, ebx

        ;mov ecx, cur_i
        ;inc ecx
        ;mov cur_i, ecx
    no_swap:
    mov ecx, i              ;�������� ����� �������� �������� � ������
    inc ecx
    mov i, ecx
    ;mov edx, n
    cmp ecx, n	;
    jl find_min

    mov i, 0

    for_each_min:           ;���� ���� ���������� ��������, ������ ������������, ������� �� � ������������� � ����� �������
        mov ebx, arr        ;��� ������� ������, ���������� � �����������
        mov eax, cur_str
        imul n
        imul four
        mov ecx, eax
        mov eax, i;min_i
        imul four
        add eax, ecx        ;�������� ������ ����� �������� ��������
        mov ecx, [ebx+eax]	;�������, ��������� �� �������
        mov eax, min_i      
        imul four
        mov ebx, eax
        mov eax, cur_str
        imul n
        imul four
        add eax, ebx
        mov ebx, arr 
        ;mov edx, [ebx+eax]  ;�������� ������ ����� ������������ � ������ (���������� ��������)  
        cmp ecx, [ebx+eax]      ;������� ������� � �����������
        je equal1               ;���� ����� - ����� ������������ ������� � ������� ��������
        jmp con

    equal1:
        mov j, 0                
        find_max:               ;���� ���� ���� ������������ ������� � i-��� �������

            mov eax, max_j      
            imul n          
            imul four           
            mov buff, eax       ;������� ������ ������ ������
            mov eax, i
            imul four           ; ������� ����� �������������� ������������� � ������
            add eax, buff       ;������� ������ ����� �������������� �������������
            mov ebx, arr
            mov ecx, [ebx+eax]  ;������ ������������� ������������
    
            mov eax, j		;����� ������ ��������
            imul n
            imul four
            mov ebx, eax
            mov eax, i
            imul four
            add eax, ebx        ;���������� ������� ������ ����� ��������

            ;add eax, edx
            mov ebx, arr
            cmp ecx, [ebx+eax]      ;������� ������������� ������������ � �������
            jl swap_max             ;���� ������������ ������, ������ ���
            jmp no_swap_max

            swap_max:
            mov ebx, j
            mov max_j, ebx

            no_swap_max:            ;���� ��� - ������ �������
            mov ecx, j  
            inc ecx
            mov j, ecx
            cmp ecx, m	;
        jl find_max

        ;mov ecx, max_j             ;������ ����� ������������� � ������� �������� � max_j
        mov eax, cur_str            
        imul n
        imul four
        mov ebx, eax
        mov eax, i                  
        imul four
        add eax, ebx                ;������� ������ ����� ������ �� ����������� ��������� � ������
        
        mov ebx, arr
        mov ecx, [ebx+eax]	;����������� � ������, ��������� � ���� � �������

        mov eax, max_j
        imul n
        imul four
        ;add eax, i
        mov ebx, eax
        mov eax, i
        imul four
        add eax, ebx        ;������� ���� ������� � �������

        mov ebx, arr
        cmp [ebx+eax], ecx      ;�������
        je is_sedl              ;���� ��������� - ������ ��� �������� �����
        jmp con                 ;���� ��� - �������� ������ ����������� � ������

        is_sedl:
        
        ;mov ebx, arr
        ;mov eax, result
        mov cur_sedl, ecx       ;�������� ������� �������� �������
        mov eax, count_sedl
        imul four
        add eax, result     ; ������� ����� ��� ������ � result
        mov ecx, eax		;���������� ��������� �� ������ � ecx
        ;mov eax, max_j
        ;imul n
        ;mov ebx, eax
        ;mov eax, i
        ;imul four
        ;add eax, ebx
        ;mov ebx, arr
        ;mov edx, [ebx+eax]
        mov edx, cur_sedl       
        mov [ecx], edx          ;������� ������� ��������
        mov edx, count_sedl     
        inc edx
        mov count_sedl, edx     ;�������� ���������� �������� ���������

        ;mov eax, max_j
        ;imul n
        ;mov edx, [ebx+eax+i]
        
    con:
    mov ecx, i
    inc ecx
    mov i, ecx      ;������� � ���������� �������� ������� ������
    cmp ecx, n
    jl for_each_min

mov ecx, cur_str
inc ecx
mov cur_str, ecx        ;������� � ��������� ������
cmp ecx, m
jl for_each_str

mov eax, count_sedl
ret 16
_FindSaddlePoints@16 endp
end