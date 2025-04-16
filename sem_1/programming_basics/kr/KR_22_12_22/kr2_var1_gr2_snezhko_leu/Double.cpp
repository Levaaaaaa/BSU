#include "Double.h"

Double::Double(std::string val)
{
	std::stringstream os;
	os << val;
	try {
		os >> val;
	}
	catch (std::exception) {
		std::invalid_argument;

	}
}
/*
bool Double::operator>(Number& n)
{
	return doubleValue() > n.doubleValue();
}
bool Double::operator==(Number& b)
{
	return doubleValue() == b.doubleValue();
}

bool Double::operator<(Number& n)
{
	return doubleValue() < n.doubleValue();
}
bool Double::operator!=(Number& n)
{
	return doubleValue() != n.doubleValue();
}
*/

std::ostream& operator<< (std::ostream& os, const Double& i)
{
	os << i.value;
	return os;
}

std::istream& operator>> (std::istream& is, Double& i)
{
	is >> i.value;
	return is;
}