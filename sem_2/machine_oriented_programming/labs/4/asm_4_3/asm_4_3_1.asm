.586
.model flat

public _GCD@4

.data
a dd 0
b dd 0

.code

_GCD@4 proc
		lea eax, [esp+4]
		mov ebx, [eax+4]
		mov edx, ebx

		while1:
		mov ebx, edx
		cdq
		idiv ebx
		cmp edx, 0
		jnz while1

		mov ecx, ebx

		cmp ecx, 1
		je the_end
		cmp ecx, [esp+4]
		je the_end
		mov eax, [esp+4]
		cdq 
		idiv ecx
		;mov edx, [esp+4]
		mov [a], eax
		mov eax, [b]
		cdq
		idiv ecx
		mov [b], eax

		mov eax, 0
		the_end:
ret 4
_GCD@4 endp
end