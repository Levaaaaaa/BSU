#include "Header.h"
template <class T>
List<T>* get_ptr(char mark)//функция которая определяет по маркеру какой нужно создать объект 
{
	if (mark == 'q')
	{
		return new Queue<T>;
	}
	else
	{
		return new Stack<T>;
	}
}
int main()
{
	const size_t size = 10;
	List<int>* arr[size];
	ifstream in("Text.txt");
	if (!in)
	{
		cout << "Error file open!\n";
		return 1;
	}
	size_t count = 0;
	while (in)
	{
		char mark;
		in >> mark;
		if (in.eof())
		{
			break;
		}
		arr[count] = get_ptr<int>(mark);
		arr[count++]->read(in);
	}
	for (size_t i = 0; i < count; i++)
	{
		arr[i]->print();
	}
	for (size_t i = 0; i < count; i++)
	{
		delete arr[i];
	}
	system("pause");
	return 0;
}

