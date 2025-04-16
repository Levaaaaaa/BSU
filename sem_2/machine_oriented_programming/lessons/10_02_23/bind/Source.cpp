#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>
#include <ctime>

int main()
{
	std::vector<int> nums(10);
	srand(time(0));		// обновляем рандом, связываем его с текущим временем
	std::for_each(nums.begin(), nums.end(), [&nums](int& i) {i = rand() % 1000; });		// заполняем массив случайными значениями
	std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "));

	std::cout << "\n";
	std::copy_if(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "),  
		std::bind(std::greater<int>(), std::placeholders::_1, 500)	//в greater первый аргумент (_1) поменяли на 500
		);

	return 0;
}