#include <iostream>

int main()
{
	int x;
	std::cout << "Enter x ";
	std::cin >> x;
	int result;
	int stat = 0;	
	//stat==0 - �� � �������
	//stat==1 - ����� �����������

	_asm {
		mov eax, x
		
		mov ebx, 10
		idiv ebx	;������ � dl �������� �������
		
		cmp eax, 0
		mov result, edx
		jz the_end1

		mov ebx,eax

		my_while:
		cmp ebx, 0	;� eax, ebx �������� ���������� x
		jz the_end	;� ecx �������� ������� result
		
		mov eax, dl
		mov dh, 10
		imul dh
		mov ecx, 	;�������� ��������������� ������, ���. �� 10
		mov eax, ebx	;���������� ���������� x � eax
		idiv 10 
		add ecx, eax
		jmp my_while

		the_end1:
		mov stat, 1
		the_end:
		mov result, ecx
	}

	std::cout << result;
	return 0;
}