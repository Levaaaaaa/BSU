.586
.model flat
public @calculateCos@8

.data
all_sum dd 1.0
addend dd 1.0		;текущее слагаемое
x dd 1.0
four dd 4
counter dd 1
counter1 dd 2
neone dd -1
;one dd 1
rubbish dd 0

.code
@calculateCos@8 proc

finit

fldpi	;x=pi/4
fild four
fdiv
fst x
fld x
fstp x

loop_:
fld addend
fld x
fmul
fld neone
fmul
fld counter
fdiv
fstp addend
fld addend
fld counter1
fdiv
fstp addend

fld addend
fld all_sum
fadd
fstp all_sum

fld counter
;fild one
fld1
fadd
fstp counter

fld counter1
;fild one
fld1
fadd
fstp counter1

loop loop_

lea eax, all_sum

ret
@calculateCos@8 endp
end