.586 
.model flat 
 
 public _swapMax@8

.code 

_swapMax@8 proc
        mov esi, [esp+4]
        mov edx, [esp+8]
        mov eax, [esi]
        mov ecx, [esp+8]

        loop_:
            cmp eax, dword ptr [esi]
            jl great
            jmp con
            great:
                mov eax, [esi]
                mov edx, ecx
            con:
                add esi, 4
        loop loop_

        mov ecx, [esp+8]
        sub ecx, edx
        ;теперь ecx - индекс мин.
        
        mov esi, [esp+4]
        mov eax, [esp+8]
        mov edx, [esi+ecx*4]
        xchg [esi+eax*4], edx
        mov [esi+ecx*4], edx

        mov eax, 0
 ret 8
_swapMax@8 endp
end