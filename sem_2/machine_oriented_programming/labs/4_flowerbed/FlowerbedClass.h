#pragma once

#include <string>
#include <vector>


template <typename T>
bool isElementInVector(std::vector<T> v, T t)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] == t) return true;
	}
	return false;
}

class Flowerbed
{
public :
	Flowerbed() = default;
	Flowerbed(int n, std::string f, std::vector<std::string> flow) : num(n), figure(f), flowers(flow) {}
	~Flowerbed() = default;

	int num;
	std::string figure;
	std::vector<std::string> flowers;
};

std::ostream& operator<< (std::ostream&, Flowerbed);

bool operator< (const Flowerbed& r, const Flowerbed& l)
{
	return r.figure < l.figure;
}