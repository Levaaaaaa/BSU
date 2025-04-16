#pragma once

#define ALLINCLUDE_H

#define M_PI 3.14159265358979323846
#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <stack>
#include <sstream>
#include <ctype.h>
#include <stdio.h>

template <typename T>
bool isElementInVector(std::vector<T> v, T e)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (e == v[i]) {
			return true;
		}
	}

	return false;
}

int checkInput(std::vector<int>);
template <typename T>
std::string toString(T t) {
	std::stringstream str;
	str << t;
	std::string s;
	str >> s;
	return s;
}