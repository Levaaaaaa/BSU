#include "ArithmFun.h"

void Add()
{
	double a = checkInputArithmFun("a");

	double b = checkInputArithmFun("b");

	std::cout << "Sum a and b is " << a + b << "\n\n";
}

void multiply()
{
	double a = checkInputArithmFun("a");

	double b = checkInputArithmFun("b");

	std::cout << "Multiply a and b is " << a * b << "\n\n";
}

void factorial() {
	int result = 1;
	int num = checkInputArithmFun("the number");

	if (num != 0) {
		for (size_t i = 1; i <= num; i++)
		{
			result *= i;
		}
	}

	std::cout << "Factorial of this number is " << result << "\n\n";
}

std::vector<std::function<void()>> VectorOfBinArithmFun()
{
	std::function<void()> ptrAdd = Add;
	std::function<void()> ptrMultiply = multiply;

	std::vector<std::function<void()>> result = { nullptr, ptrAdd, ptrMultiply };

	return result;
}

void requestBinArithmOp()
{
	std::vector<std::function<void()>> operations = VectorOfBinArithmFun();
	
	int op = -1;
	bool run = true;
	while (run) {
		do {
			std::cout << "Select the operation\n\t1. Add\n\t2. Multiply\n\t0. Back\n\n";
			std::cin >> op;
		} while (op > operations.size());

		if (op == 0) {
			run = false;
			continue;
		}
		else {
			operations[op]();
		}
	}
}

std::vector<std::function<void()>> VectorOfUnArithmFun()
{
	std::function<void()> ptrFactorial = factorial;

	std::vector<std::function<void()>> result = { nullptr, ptrFactorial };

	return result;
}

void requestUnArithmOp()
{
	std::vector<std::function<void()>> operations = VectorOfUnArithmFun();

	int op = -1;
	bool run = true;
	while (run) {
		do {
			std::cout << "Select the operation\n\t1. Factorial\n\t0. Back\n\n";
			std::cin >> op;
		} while (op > operations.size());

		if (op == 0) {
			run = false;
			continue;
		}
		else {
			operations[op]();
		}
	}
}

double checkInputArithmFun(std::string s)
{
	double a;
	
	std::cout << "Enter " << s << " ";
	std::cin >> a;

	return a;
}

/*
bool checkNumberInString(std::istream &stream)
{
	if (stream.fail()) {
		stream.clear();
		stream.ignore();
		return true;
	}

	return false;
}*/