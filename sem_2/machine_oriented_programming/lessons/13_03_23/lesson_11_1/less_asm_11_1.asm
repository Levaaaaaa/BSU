.586
.model flat
public _ChangeRawCalm@12

.code
_ChangeRawCalm@12 proc
xor ecx, ecx		;����� ������������ ��� ������� 
;mov ebp, [esp+4]	;��������� ������ ���������� �� ������ (�������)
mov eax, [esp+8]	; ������� ������ ������� � eax

cycle:
	imul ecx			; �������� ������ � ������� �������� ������ ������ (eax)
	add eax, [esp+12]	;�������� ������ � ������� �������� ������ ������ (eax)
	mov edi, eax		;������ � �������
	mov ebx, [esp+12]	;��������� ������, ����� ������� ������ ������ �������
	mov eax, [esp+8]	;������� ������ � eax
	imul ebx			;�������� ������ � ������� �������� ������ ������ ������
	add eax, ecx		;�������� ������ �� ������� ������� ��������
	mov esi, eax;		;������ � ������

	mov ebx, [esp+4]
	mov edx, [ebx][esi*4]	;������ ��������� �������� �������
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