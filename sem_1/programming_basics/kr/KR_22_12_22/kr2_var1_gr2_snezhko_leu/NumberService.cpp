#include "NumberService.h"

Double NumberService::sum(std::vector<Number*> v)
{
	double sum = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		sum = sum + v[i]->doubleValue();
	}
	return Double(sum);
}

size_t NumberService::countLess(std::vector<Number*>& v, Number* n)
{
	size_t result = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i]->doubleValue() < n->doubleValue()) {
			result++;
		}
	}

	return result;
}

std::vector<Number*> NumberService::findEqual(std::vector<Number*>& v, Number& n)
{
	std::vector<Number*> result;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (n.doubleValue() == v[i]->doubleValue()) result.push_back(v[i]);
	}

	return result;
}

std::vector<Number*> NumberService::generateNumber(int count, double minValue, double maxValue)
{
	std::vector<Number*> result;
	for (size_t i = 0; i < count; i++)
	{
		size_t t = rand() % 2;
		srand(minValue);
		int max = maxValue / 1;
		if (t == 0) {
				result.push_back(new Double(rand() % max));
		}
		else {
			result.push_back(new Integer(rand() % max));
		}
	}

	return result;
}

