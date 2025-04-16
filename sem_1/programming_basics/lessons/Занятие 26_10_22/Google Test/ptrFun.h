#pragma once

#include <vector>
#include <string>

bool isEven(int);
bool isOdd(int);
bool isNeg(int);
void findElem(const std::vector<int>&, bool(*)(int));
void readFile(const std::string&, std::vector<int>&);