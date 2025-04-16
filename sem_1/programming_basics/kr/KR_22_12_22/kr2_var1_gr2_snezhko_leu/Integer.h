#pragma once

#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <ostream>
#include <istream>


#include "Number.h"
#include "Double.h"

class Integer : public Number
{
public:
	Integer() : value(0) {}
	Integer(int val) : value(val) {}
	Integer(std::string s);

	int getValue() { return value; }
	/*
	bool operator>(Number&);
	bool operator==(Number&) override;
	bool operator<(Number&) override;
	bool operator!=(Number&) override;
	*/
	double operator+(Number& d) { return doubleValue() + d.doubleValue(); };
	double operator+(double d) { return doubleValue() + d; }

	friend std::ostream& operator<< (std::ostream& os, const Integer& i);
	friend std::istream& operator>> (std::istream& is, Integer& i);

	int intValue() override { return value; }
	long longValue() override { return static_cast<long>(value); }
	double doubleValue() override { return static_cast<double>(value); }
	float floatValue() override { return static_cast<float>(value); }


	~Integer() = default;
private:
	int value;
};

//static const int MAX_VALUE = INT_MAX; //2147483647;
//static const int MIN_VALUE = INT_MIN;
//static const std::string TYPE ("int");
