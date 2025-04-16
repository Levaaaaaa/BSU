.586 ;copy paste
.model flat ;copy paste
 
public _power ;зависит от названи€ и соглашени€ о вызове
 
.code ;пишем везде, где хотим писать код
 
_power proc ;объ€вление процедуры
 mov  eax, 1 ;тело процедуры
 mov  ecx, [esp+8]
_loop: 
 imul eax, [esp+4] 
 loop _loop 
 ret 
_power endp  ; конец кода процедуры
end; конец кода на ассемблере