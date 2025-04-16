#pragma once

#include "Array.h"

template<class T>
class Stack
{
public:
	explicit Stack();
	Stack(const Stack&);
	Stack(Stack&&);
	void pushBack(T);
	T popBack();
	size_t GetSize() { return size; }
	bool IsEmpty() { return size == 0; }
	Stack& operator=(const Stack&);
	Stack& operator=(Stack&&);
private:
	size_t size;
	Array<T> data;
	size_t end;
};
template <class T>
Stack<T>::Stack() : size(0), data(Array<T>())
{
}
template <class T>
Stack<T>::Stack(Stack&& a) : size(a.size), data(a.data)
{
	a.size = 0;
	a.data = nullptr;
}
template <class T>
void Stack<T>::pushBack(T n)
{
	data.Add(n);
	size++;
}
template <class T>
T Stack<T>::popBack()
{
	if (size == 0) abort();
	T n = data[size - 1];
	data.RemoveAt(size - 1);
	size--;
	return n;
}
template <class T>
Stack<T>::Stack(const Stack& a) :size(a.size), data(a.data)
{
}
template <class T>
Stack<T>& Stack<T>::operator=(const Stack& a)
{
	if (a != *this)
	{
		delete data;
		size = a.size;
		data = new T[a.size];
		for (size_t i = 0; i < size; i++)
		{
			data[i] = a.data[i];
		}
	}
	return *this;
}
template <class T>
Stack<T>& Stack<T>::operator=(Stack&& a)
{
	if (a != *this)
	{
		delete data;
		size = a.size;
		data = a.data;
		a.size = 0;
		a.data = Array<T>();
	}
	return *this;
}