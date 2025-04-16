#include "ListClass.h"

void printList(List<int>);

int main()
{
	List<int> list;
	List<int> list1 = { 1,2,3,4,5 };

	list.pushBack(8);
	list.pushBack(5);
	list.pushBack(12);
	list.pushBack(7);
	printList(list);

	try {

		std::cout << list1;
		/*
		std::cout << list.popBack() << "\n";
		std::cout << list;
		std::cout << list.popFront() << "\n";
		printList(list);
		list.insert(10, 1);
		printList(list);
		list.erase(list.get_size()-1);
		printList(list);*/
	} catch (int i) {}
	list.pushFront(9);
	printList(list);
	
	return 0;
}

void printList(List<int> l)
{
	for (size_t i = 0; i < l.get_size(); i++)
	{
		std::cout << l[i] << " ";
	}
	std::cout << "\n\n";
}