#include <vector>

#include "ListClass.h"

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	std::vector<int>::iterator it = v.begin();

	for (;  it != v.end(); it++)
	{
		std::cout << *it;
	}


	return 0;
}