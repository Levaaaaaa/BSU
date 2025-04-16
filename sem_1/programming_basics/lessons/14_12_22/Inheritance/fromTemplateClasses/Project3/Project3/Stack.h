#pragma once
#include "Header.h"
template<class T>
class Stack : public List<T>
{
public:
	Stack() :List<T>(), tail(nullptr) {}
	~Stack();
	void push_back(T item);
	T pop();
	void print()const;
	void read(istream&);
private:
	Node<T>* tail;
};
template<class T>
Stack<T>::~Stack()
{
	while (tail)
	{
		pop();
	}
}
template<class T>
void Stack<T>::print()const
{
	for (Node<T>* cur = tail; cur; cur = cur->Node<T>::prev)
		cout << cur->Node<T>::data << " ";
	cout << endl;
}
template<class T>
T Stack<T>::pop()
{
	if (!tail)
	{
		cout << "Stack is empty!\n";
		return T();
	}
	else
	{
		T item = tail->Node<T>::data;
		Node<T>* temp = tail;
		tail = temp->Node<T>::prev;
		delete temp;
		List<T>::size--;
		return item;
	}
}
template<class T>
void Stack<T>::push_back(T item)
{
	Node<T>* new_node = new Node<T>(item);
	if (tail)
		new_node->Node<T>::prev = tail;
	tail = new_node;
	List<T>::size++;
}
template<class T>
void Stack<T>::read(istream& in)
{
	T value;
	char symbol = ' ';
	while (symbol != ';')
	{
		in >> value;
		push_back(value);
		symbol = in.get();
	}
}