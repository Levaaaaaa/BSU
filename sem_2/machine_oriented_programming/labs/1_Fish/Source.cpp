#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
	setlocale(0, "");

	std::set<std::string> bottom = { "�����", "�����", "�����" };	//���
	std::set<std::string> bank = { "���", "�������", "�����" };		//�����

	// ��� ���������
	std::set_union(bottom.begin(), bottom.end(), bank.begin(), bank.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << "\n";

	//������� �����
	std::set_intersection(bottom.begin(), bottom.end(), bank.begin(), bank.end(), std::ostream_iterator<std::string>(std::cout, " "));

	std::cout << "\n";
	//������ ��, ��� ����� ������
	std::set_difference(bank.begin(), bank.end(), bottom.begin(), bottom.end(), std::ostream_iterator<std::string>(std::cout, " "));

	std::set<std::string> both;
	std::inserter(both, both.begin());		//�������� ������� (��� ostream_iterator)
}