#pragma once

#include "Array.h"

template<class T>
class Queue
{
public:
	explicit Queue();
	Queue(const Queue&);
	Queue(Queue&&);
	void enqueue(T);
	T dequeue();
	size_t GetSize() { return size; }
	bool IsEmpty() { return size == 0; }
	Queue& operator=(const Queue&);
	Queue& operator=(Queue&&);
private:
	size_t size;
	Array<T> data;
	size_t end;
};
template <class T>
Queue<T>::Queue() : size(0), data(Array<T>())
{
}
template <class T>
Queue<T>::Queue(Queue&& a) : size(a.size), data(a.data)
{
	a.size = 0;
	a.data = nullptr;
}
template <class T>
void Queue<T>::enqueue(T n)
{
	data.Add(n);
	size++;
}
template <class T>
T Queue<T>::dequeue()
{
	if (size == 0) abort();
	T n = data[0];
	data.RemoveAt(0);
	size--;
	return n;
}
template <class T>
Queue<T>::Queue(const Queue& a) :size(a.size), data(a.data)
{
}
template <class T>
Queue<T>& Queue<T>::operator=(const Queue& a)
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
Queue<T>& Queue<T>::operator=(Queue&& a)
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