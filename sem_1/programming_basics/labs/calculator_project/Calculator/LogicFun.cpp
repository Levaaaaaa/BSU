#include "LogicFun.h"

void ne() {
	bool a = checkInputLogFun("a");
	
	std::cout << "Negation of a is " << (!a ? "true" : "false") << "\n\n";
}

void conjunction() {
	bool a = checkInputLogFun("a");

	bool b = checkInputLogFun("b");
	
	std::cout << "Conjunction of a and b is " << ((a && b) ? "true" : "false") << "\n\n";
}

void disjunction() {
	bool a = checkInputLogFun("a");

	bool b = checkInputLogFun("b");

	std::cout << "Disjunction of a and b is " << ((a || b) ? "true" : "false") << "\n\n";
}

std::vector<std::function<void()>> VectorOfBinLogFun()
{
	std::function<void()> ptrCon = conjunction;
	std::function<void()> ptrDis = disjunction;

	std::vector<std::function<void()>> result = { nullptr, ptrCon, ptrDis };

	return result;
}

void requestBinLogOp()
{
	std::vector<std::function<void()>> operations = VectorOfBinLogFun();

	int op = -1;
	bool run = true;
	while (run) {
		do {
			std::cout << "Select the operation:\n\t1. Conjunction\n\t2. Dijuction\n\t0. Back\n\n";
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

std::vector<std::function<void()>> VectorOfUnLogFun()
{
	std::function<void()> ptrNeg = ne;

	std::vector<std::function<void()>> result = { nullptr, ptrNeg };

	return result;
}

void requestUnLogOp()
{
	std::vector<std::function<void()>> operations = VectorOfUnLogFun();

	int op = -1;
	bool run = true;
	while (run) {
		do {
			std::cout << "Select the operation:\n\t1. Negation\n\t0. Back\n\n";
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
bool checkInputLogFun(std::string s)
{
	bool result;
	std::string strResult;
	std::vector<std::string> variableValues = { "0","1","true","false", "טסעטםא", "כמזü" };
	do {
		std::cout << "Enter the logic " << s << ": ";
		std::cin >> strResult;
	} while (!isElementInVector(variableValues, strResult));

	if (strResult == "0" || strResult == "כמזü" || strResult == "false") { result = false; }
	else { result = true; }

	return result;
}