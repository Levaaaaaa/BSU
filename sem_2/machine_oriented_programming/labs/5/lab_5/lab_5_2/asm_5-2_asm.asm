.586
.model flat
public @my_ln2@4

.data
k dd 1
addend dd 1.0
sum dd 0.0
dev dd 1
four dd 4
one dd 1
two dd 2

.code
@my_ln2@4 proc

finit

loop_:
;fild dev
;fild k
;fmulp st(1), st
;fstp dev

fild k
fild k
fmulp st(1), st
fild four
fmulp st(1), st
fild one
fsubp st(1), st
fild k
fmulp st(1), st
fst dev
;fild dev
;fmulp st(2), st
;fstp dev

;fild dev
fild one
fdivrp st(1), st
fstp addend

inc k
fld sum
fld addend
faddp st(1), st
fstp sum

loop loop_

fld sum
fild one
faddp st(1), st
fstp sum

fild two
fld sum
fdivrp st(1), st
fstp sum

lea eax, sum
ret
@my_ln2@4 endp
end