.586
.model flat
public _integrate@4

.data

	x1 dd 0
	x2 dd 0
	n dd 0
	n2 dd 0
	n1 dd 1
	my_width dd 0
	result dd 0
	two dd 2
	half dd 0.5
	;fx1 dd 0
	;fx2 dd 0
	;buff dd 0

.code

_integrate@4 proc

mov ecx, [esp+4]
mov n, ecx

finit
fldpi
fild two
fmulp st(1), st(0)
fild n
fdivp st(1), st(0)
fstp my_width



for1:

fild n2
fld my_width
fmulp st(1), st
fst x1
fld x1
fmulp st(1), st
;fst fx1
fld x1
fsin
faddp st(1), st
;fstp fx1

fild n1
fld my_width
fmulp st(1), st
fst x2
;fld x2
fld x2
fmulp st(1), st
;fst fx2
fld x2
fsin
faddp st(1), st
;fstp fx2

;fld fx1
;fld fx2
faddp st(1), st
;fstp buff

fld x2
fld x1
fsubp st(1), st

;fld buff
fmulp st(1), st

fld half
fmulp st(1), st

fld result
faddp st(1), st
fstp result

;mov eax, n1
inc n1
;mov n1, eax

;mov eax, n2
inc n2
;mov n2, eax

mov eax, n2
cmp eax, n
jl for1

lea eax, result

ret 4
_integrate@4 endp
end