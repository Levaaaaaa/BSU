#pragma once

#include "Double.h"
#include <vector>
#include <cstdlib>

class NumberService
{
public:
	Double sum(std::vector<Number*>);
	size_t countLess(std::vector<Number*>&, Number*);
	std::vector<Number*> findEqual(std::vector<Number*>&, Number&);
	std::vector<Number*> generateNumber(int count, double minValue, double maxValue);

	std::vector<Number*> readNumberFromFile(const std::string &path);
	void writeNumbersToFile(const std::string&, std::vector<Number*>&);

};