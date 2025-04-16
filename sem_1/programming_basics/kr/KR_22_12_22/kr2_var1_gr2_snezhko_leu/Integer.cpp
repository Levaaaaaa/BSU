#include "Integer.h"
#include "Double.h"

Integer::Integer(std::string val)
{
	std::stringstream os;
	os << val;
	try {
		os >> val;
	}
	catch (std::exception) {
		//throw std::invalid_argument;
	}
}
/*
bool Integer::operator>(Number& n)
{
	return doubleValue() > n.doubleValue();
}
bool Integer::operator==(Number &b)
{
	return doubleValue() == b.doubleValue();
}

bool Integer::operator<(Number& n)
{
	return doubleValue() < n.doubleValue();
}
bool Integer::operator!=(Number &n)
{
	return doubleValue() != n.doubleValue();
}
*/
std::ostream& operator<< (std::ostream& os, const Integer& i)
{
	os << i.value;
	return os;
}

std::istream& operator>> (std::istream& is, Integer& i)
{
	is >> i.value;
	return is;
}