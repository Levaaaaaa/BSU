#include "Rational.h"

Rational::Rational(size_t numer_, size_t denom_)
{
	numer = numer_;
	denom = denom_;
	std::cout << "Constructor with parametrs\n";
}

Rational::Rational(const Rational& r)	//конструктор копирования
{
	numer = r.numer;
	denom = r.denom;

	std::cout << "Copy constructor\n";
}

const Rational Rational::add(const Rational &r) const
{
	Rational sum;

	sum.numer = numer * r.denom + r.numer * denom;
	sum.denom = denom * r.denom;

	sum.reduce();

	return sum;
}

const Rational Rational::operator+(Rational r)
{
	Rational sum;

	sum.numer = numer * r.denom + r.numer * denom;
	sum.denom = denom * r.denom;

	sum.reduce();

	return sum;
}

Rational::~Rational()
{
	std::cout << "Destructor\n";
}

/*
void Rational::print()
{
	std::cout << numer << "/" << denom << "\n";
}
*/
void Rational::reduce()
{
	size_t gcd = GCD(numer, denom);

	if (gcd != 0) {
		numer /= gcd;
		denom /= gcd;
	}
}

size_t GCD(size_t a, size_t b)
{
	if (a == 0 || b == 0)
	{
		return 0;
	}

	while (a != b)
	{
		if (a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}

	return a;
}

std::ostream& operator<<(std::ostream& out, const Rational& r)
{
	out << r.getNumer() << "/" << r.getDenom();

	return out;
}

std::istream& operator>>(std::istream& in, Rational& r)
{
	in >> r.numer >> r.denom;
	return in;
}