.586 ;copy paste
.model flat ;copy paste
 
public _power ;������� �� �������� � ���������� � ������
 
.code ;����� �����, ��� ����� ������ ���
 
_power proc ;���������� ���������
 mov  eax, 1 ;���� ���������
 mov  ecx, [esp+8]
_loop: 
 imul eax, [esp+4] 
 loop _loop 
 ret 
_power endp  ; ����� ���� ���������
end; ����� ���� �� ����������