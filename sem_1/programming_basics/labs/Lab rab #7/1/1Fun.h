#pragma once
#include <vector>
#include <functional>
#include <iostream>
#include <typeinfo>
#include <string>

void printVector(std::vector<int>);
bool isSimple(int n);
bool isMultipleThree(int n);
bool isEven(int n);
std::vector<int> search(std::vector<int> v, std::function<bool(int)> ptrFun);
void UI();

void UI()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	std::cout << "\n";
	printVector(v);
	std::cout << "\n\n";
	std::vector<int> result;
	std::string q;
	std::function<bool(int)> arrayFun[] = { nullptr,isSimple, isMultipleThree, isEven };

	while (true) {
		std::cout << "Select the mode:\n1 - Only Simple\n2 - Only Multiple of 3\n3 - Only even\n0 - Exit\n\n";
		std::cin >> q;
		std::cout << "\n";
		while (q.compare("0")&&q.compare("1")&&q.compare("2")&& q.compare("3"))
		{ 
			std::cout << "Select the mode:\n1 - Only Simple\n2 - Only Multiple of 3\n3 - Only even\n0 - Exit\n\n";
			std::cin >> q;
			std::cout << "\n";
		}


		if (q == "0")
		{
			break;
		}
		else
		{
			if (stoi(q) > 0 && stoi(q) <= 3)
			{
				result = search(v, arrayFun[stoi(q)]);
			}
			else
			{
				continue;
			}
		}

		printVector(result);
		std::cout << "\n\n";
	}
}

bool isSimple(int n)
{
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

bool isMultipleThree(int n)
{
	if (n % 3 == 0)
	{
		return true;
	}

	return false;
}

bool isEven(int n)
{
	if (n % 2 == 0)
	{
		return true;
	}

	return false;
}

std::vector<int> search(std::vector<int> v, std::function<bool(int)> ptrFun)
{
	std::vector<int> result;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (ptrFun(v[i]))
		{
			result.push_back(v[i]);
		}
	}

	return result;
}

void printVector(std::vector<int> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
}