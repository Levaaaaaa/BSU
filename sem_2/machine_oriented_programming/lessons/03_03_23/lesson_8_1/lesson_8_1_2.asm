.586 
.model flat 
 
 public _MaxSeq@12

 .data
maxseq dd 0


.code 

_MaxSeq@12 proc
mov ecx, [esp+8];     array size
mov esi, [esp+4];     adress of array
xor edi, edi;         max sum of seq
xor edx, edx;         sum of cur seq
xor ebx, ebx;         cur seq size
xor eax, eax;         start of seq

cycle:

cmp dword ptr[esi], 0
jle _negative
add edx, [esi]
inc ebx
jmp _end

_negative:
cmp edx, edi;         compare cur sum, max sum
jl less

mov edi, edx
mov maxseq, ebx
less:
xor edx, edx
xor ebx, ebx

_end:
add esi, 4
loop cycle

cmp edx, edi;        
jl lesss
mov edi, edx
mov maxseq, ebx
 
 lesss:
 mov eax, edi
 mov ecx, [esp+12]
 mov ecx, ebx

 ret 12
_MaxSeq@12 endp
end