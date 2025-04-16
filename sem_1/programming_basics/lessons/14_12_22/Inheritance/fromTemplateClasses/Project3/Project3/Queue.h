#pragma once
#include "Header.h"
template<class T>
class Queue : public List<T>
{
public:
	Queue();
	~Queue();
	void push_back(T);
	T pop();
	void print()const;
	void read(istream&);
private:
	Node<T>* head;
	Node<T>* tail;
};
template<class T>
void Queue<T>::push_back(T q)
{
	Node<T>* new_node = new Node<T>(q);
	if (List<T>::size == 0)
	{
		head = tail = new_node;
		List<T>::size++;
		return;
	}
	if (tail)
		new_node->Node<T>::prev = tail;
	tail = new_node;
	List<T>::size++;
}
template<class T>
T Queue<T>::pop()
{
	if (!tail)
	{
		cout << "Queue is empty!\n";
		return T();
	}
	Node<T>* cur = tail;
	T item = head->Node<T>::data;
	Node<T>* temp = head;
	if (head == tail && tail != nullptr)
	{
		head = tail = nullptr;
		delete temp;
		List<T>::size--;
		return item;
	}
	while (cur->Node<T>::prev != head)
	{
		cur = cur->Node<T>::prev;
	}
	head = cur;
	delete temp;
	head->Node<T>::prev = nullptr;
	List<T>::size--;
	return item;
}
template<class T>
Queue<T>::Queue() :List<T>(), head(nullptr), tail(nullptr) {};
template<class T>
Queue<T>::~Queue()
{
	while (tail)
	{
		pop();
	}
}
template<class T>
void Queue<T>::print()const
{
	Queue<T> temp;
	//создаём временную очередь temp и помещаем туда данные в обратном порядке
	for (Node<T>* cur = tail; cur; cur = cur->Node<T>::prev)
	{
		temp.push_back(cur->Node<T>::data);
	}
	//извлекаем данные из temp в нужном нам порядке(с конца)
	for (Node<T>* cur = temp.tail; cur; cur = cur->Node<T>::prev)
	{
		cout << cur->Node<T>::data << " ";
	}
	cout << endl;
}
template<class T>
void Queue<T>::read(istream& in)
{
	T value;
	char symbol = ' ';// заводим символ для того чтобы распознать (;) в файле(потоке)
	while (symbol != ';')
	{
		in >> value;
		push_back(value);
		symbol = in.get();//извлечь символ из потока и присвоить переменной symbol
	}
}
