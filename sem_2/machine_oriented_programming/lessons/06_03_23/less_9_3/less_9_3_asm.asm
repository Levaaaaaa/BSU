.586
.model flat
public _function3@8

.data
x dd 0
y dd 0
result dd 0

.code
_function3@8 proc
		mov eax, [esp+4]
		mov x, eax
		mov eax, [esp+8]
		mov y, eax
		
		finit
		fld1
		fld x
		fyl2x
		; fstp log

		fld x
		fadd
		fld y
		fmul
		fstp result

		fld x
		fld y
		fpatan
		fld result
		fdivr
		fstp result

		lea eax, result

		ret 8
_function3@8 endp
end