#pragma once
#include "Header.h"
template<class T>
struct Node
{
	T data;
	Node* prev;
	Node(T _data, Node* _prev = nullptr) : data(_data), prev(_prev) {}
};
template<class T>//������� ����������� ������(�������� ������ ����������� �������,
//����� ��������� ������ ��������� �� ���� �����)
class List
{
public:
	List();
	virtual ~List();
	virtual void push_back(T item) = 0;
	virtual T pop() = 0;
	virtual void read(istream&) = 0;
	size_t get_size()const
	{
		return size;
	}
	virtual void print()const = 0;//��� ����������, ��� ���� ����� � ������� ������
	//��������������� �� �����, �� ����������� ����� � �����������
protected:
	size_t size;
};
template<class T>
List<T>::List() : size(0)
{}
template<class T>
List<T>::~List()
{}