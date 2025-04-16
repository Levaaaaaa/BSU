#pragma once
#include <iostream>
template<class T>
class Array
{
public:
	Array();
	explicit Array(size_t);
	Array(const Array<T>&);
	Array(Array<T>&&); //rvalue, move конструктор
	Array<T>& operator=(const Array<T>&);
	Array<T>& operator=(Array<T>&&); //move оператор
	~Array();
	T& operator[](const size_t& s) { return data[s]; }
	const T& operator[](const size_t& s)const { return data[s]; }
	size_t GetSize() { return size; }
	size_t GetUpperBound() { return size - 1; }
	bool IsEmpty() { return size == 0; }
	void SetAt(const size_t& pos, T s) {
		if (pos < size) data[pos] = s;
		else abort();
	}
	T GetAt(const size_t& pos) {
		if (pos < size) return data[pos];
		else abort();
	}
	void RemoveAt(const size_t&);
	void SetSize(int, int grow = 0);
	void Add(const T&);
	void FreeExtra();
	void RemoveAll();
	void InsertAt(const size_t& pos, T s);
	Array<T> Append(Array<T>);
private:
	size_t size;
	size_t capacity;
	T* data;
};
template<class T>
Array<T>::Array() :size(0), capacity(0), data(nullptr) {}
template<class T>
Array<T>::Array(size_t _size) : size(_size), capacity(_size), data(new T[_size]) {}
template<class T>
Array<T>::~Array() { delete[]data; };
template<class T>
Array<T>::Array(const Array<T>& a) :size(a.size), capacity(a.capacity), data(new T[a.capacity])
{
	for (size_t i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
}
template<class T>
Array<T>& Array<T>::operator=(const Array<T>& a)
{
	if (this != &a) {
		delete[]data;
		size = a.size;
		capacity = a.capacity;
		data = new T[capacity];
		for (size_t i = 0; i < size; i++)
		{
			data[i] = a.data[i];
		}
	}
	return *this;
}
template <class T>
Array<T>::Array(Array<T>&& a) :size(a.size), capacity(a.capacity), data(a.data)
{
	a.size = 0; a.capacity = 0; a.data = nullptr;
}
template <class T>
Array<T>& Array<T>::operator=(Array<T>&& a)
{
	if (this != &a) {
		delete[]data;
		size = a.size; capacity = a.capacity; data = a.data;
		a.size = 0; a.capacity = 0; a.data = nullptr;
	}
	return *this;
}
template <class T>
void Array<T>::SetSize(int _size, int grow) {
	if (_size < 0) abort();
	T* newData = new T[_size + grow];
	if (_size <= size) {
		for (size_t i = 0; i < _size; i++)
		{
			newData[i] = data[i];
		}
	}
	else {
		for (size_t i = 0; i < size; i++)
		{
			newData[i] = data[i];
		}
	}
	capacity = _size + grow;
	size = _size;
	delete[]data;
	data = newData;
}
template <class T>
void Array<T>::Add(const T& element) {
	SetSize(size + 1);
	data[size - 1] = element;
}
template <class T>
void Array<T>::RemoveAt(const size_t& pos) {
	if (pos >= size) abort();
	int jos = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (i == pos) { jos++; continue; }
		data[i - jos] = data[i];
	}
	SetSize(size - 1);
}
template<class T>
void Array<T>::FreeExtra() {
	SetSize(size, 0);
}
template<class T>
void Array<T>::RemoveAll() {
	SetSize(0, 0);
}
template <class T>
void Array<T>::InsertAt(const size_t& pos, T s) {
	if (pos >= size) abort();
	SetSize(size + 1);
	size_t jos;
	for (size_t i = size - 1; i > pos; i--)
	{
		data[i] = data[i - 1];
	}
	data[pos] = s;
}
template <class T>
Array<T> Array<T>::Append(Array<T> add) {
	for (size_t i = 0; i < add.size; i++)
	{
		Add(add.GetAt(i));
	}
	return this;
}