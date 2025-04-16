#pragma once

#include <vector>

template <class T>
class Stack 
{
public:
	Stack() = default;

	Stack(const T&);

	T getTop();
	bool isEmpty();
	void push_back(const T&);
	T pop_back();

	~Stack() = default;
private:
	std::vector<T> data;
	size_t size;
	T* top;
};

template <class T>
Stack<T>::Stack(const T& t)
{
	this->data.push_back(t);
	size++;
}

template <class T>
void Stack<T>::push_back(const T& t)
{
	this->data.push_back(t);
	size++;
	this->top = &data[size-1];
}

template <class T>
T Stack<T>::pop_back()
{
	if (!this->isEmpty()) {
		T last = this->data[this->size - 1];
		data.pop_back();
		size--;
		this->top = &data[size - 1];
		return last;
	}
	else {
		return 0;
	}
}

template <class T>
T Stack<T>::getTop()
{
	return *(this->top);
}

template <class T>
bool Stack<T>::isEmpty()
{
	return this->size == 0;
}