#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
	setlocale(0, "");

	std::set<std::string> bottom = { "бычок", "окунь", "мидия" };	//дно
	std::set<std::string> bank = { "рак", "пескарь", "мидия" };		//берег

	// все обитатели
	std::set_union(bottom.begin(), bottom.end(), bank.begin(), bank.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << "\n";

	//водятся везде
	std::set_intersection(bottom.begin(), bottom.end(), bank.begin(), bank.end(), std::ostream_iterator<std::string>(std::cout, " "));

	std::cout << "\n";
	//только те, кто возле берега
	std::set_difference(bank.begin(), bank.end(), bottom.begin(), bottom.end(), std::ostream_iterator<std::string>(std::cout, " "));

	std::set<std::string> both;
	std::inserter(both, both.begin());		//итератор вставки (как ostream_iterator)
}