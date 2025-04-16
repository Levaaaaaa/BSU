#pragma once

#include <iostream> 

class Number
{
public:
	char charValue() { return static_cast<char>(intValue()); };
	short shortValue() { return static_cast<short>(intValue()); }
	virtual int intValue() = 0;
	virtual long longValue() = 0;
	virtual double doubleValue() = 0;
	virtual float floatValue() = 0;
	/*
	virtual bool operator<(Number&);
	virtual bool operator!=(Number&);
	virtual bool operator==(Number&);
	*/
};