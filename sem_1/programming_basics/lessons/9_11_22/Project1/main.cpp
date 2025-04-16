#include "Rational.h"
							//конструктор вызывается при создании объекта
							// деструктор - при выхождении переменной из области видимости
int main() {

	setlocale(0, "");
	/*
	//Rational r;
	//Rational r1[5]; // пятикратное создание объекта, используется конструктор без параметров

	Rational r(1, 3);
	Rational r2;

//	r.print();

	r2 = r.add(r);
//	r2.print();
	
	r2 = r + r2;

	//std::cout << r2;
	*/
	std::vector<Rational> arr;

	std::ifstream fin("text.txt");

	Rational ra;

	/*while (!fin.eof())
	{
		fin >> ra;
		arr.push_back(ra);
	}*/

	std::istream_iterator<Rational> it_in(fin), it_cur;	//потоковый итератор
	std::copy(it_in, it_cur, std::back_inserter(arr));
	/*
	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i];
	}*/

	std::copy(arr.begin(), arr.end(), std::ostream_iterator<Rational>(std::cout, "\n"));

	return 0;
}