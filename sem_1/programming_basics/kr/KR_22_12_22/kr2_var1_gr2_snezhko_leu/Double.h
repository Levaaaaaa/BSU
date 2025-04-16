#pragma once

#include "Number.h"
#include "Integer.h"

#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>

class Double : public Number
{
public:
	Double() : value(0) {}
	Double(double val) : value(val) {}
	Double(std::string s);

	double getValue() { return value; }
	/*
	bool operator>(Number&);
	bool operator<(Number&) override;
	bool operator!=(Number&) override;
	bool operator==(Number&) override;
	double operator+(double d) { return doubleValue() + d; };
	*/
	friend std::ostream& operator<< (std::ostream& os, const Double& i);
	friend std::istream& operator>> (std::istream& is, Double& i);

	int intValue() override { return static_cast<int>(value); }
	double doubleValue() override { return value; }
	long longValue() override { return static_cast<long>(value); }
	float floatValue() override { return static_cast<float>(value); }

	~Double() = default;
private:
	double value;
};

//static const double MAX_VALUE = 9223372036854775808.0;
//static const double MIN_VALUE = -9223372036854775808.0;
//static const std::string TYPE ("double");