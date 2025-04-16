#pragma once

#include "Array1.h"

template <class T>
class Stack
{
public:
	Stack();
	Stack(const T&);
	
	~Stack() = default;

	int size();					//+
	bool isEmpty();				//+
	bool isFull();				//+
	T peek();					//+
	void push(const T&);		//+
	T pop();

private:
	Array <T> data;		//массив неупорядоченных элементов
	//Array <size_t> all_index;	//массив индексов на следующий элемент
};

template <class T>
Stack<T>::Stack()
{
	//this->all_index = new Array({ 0 });
	//???
}

template <class T>
Stack<T>::Stack(const T& t)
{

	Stack();
	data[0] = t;
}

template <class T>
int Stack<T>::size()
{
	return data.GetSize();
}

template <class T>
bool Stack<T>::isEmpty()
{
	return this->size() == 0 ? true : false;
}

template <class T>
bool Stack<T>::isFull()
{
	return data.GetSize() == data.GetSize() ? true : false;
}

template <class T>
T Stack<T>::peek()
{
	return this->data.GetAt(data.GetSize() - 1);
}

template <class T>
void Stack<T>::push(const T& t)
{
	if (this->isEmpty()) {
		data.SetAt(0, t);
		return;
	}
	if (this->isFull()) {
		data.SetSize(data.GetSize() + 1, 5);
	}

	data.SetAt(data.GetSize() - 1, t);
}

template <class T>
T Stack<T>::pop()
{
	if (this->isEmpty()) throw "Stack is empty";
	
	T tmp = this->peek();
	data.RemoveAt(data.GetSize() - 1);

	return tmp;
}