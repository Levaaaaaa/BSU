#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

class Rational
{
public:
	Rational(size_t numer_= 0, size_t denom_ = 1);	//констреуктор с параметрами, которые заданы значениями по умолчанию
													// будет работать и в качестве конструктора без параметров

	Rational(const Rational&);

	~Rational();
	
	const Rational operator+(Rational r);

 	size_t getNumer() const { return numer; }
	void setNumer(size_t n) { numer = n; }

	size_t getDenom() const { return denom; }
	void setDenom(size_t n) { denom = n; }

	void print();


	const Rational add(const Rational&) const;

	friend std::istream& operator>>(std::istream&, Rational& r);

private:
	size_t numer, denom;
	void reduce();
};

size_t GCD(size_t a, size_t b);

std::ostream& operator<<(std::ostream&, const Rational& r);