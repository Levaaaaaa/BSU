#pragma once

template<class T>
class Array 
{
public:
	Array();
	explicit Array(size_t); //explicit - запрет компилятору на неявное преобразование типа
	Array(const Array<T>&);

	Array<T>& operator=(const Array<T>&);

	~Array();
private:
	size_t size;
	size_t capacity;
	T* data;
};

template <class T>
Array<T>::Array():size(0), capacity(0), data(nullptr) {}

template <class T>
Array<T>::Array(size_t _size) : size(0), capacity(0), data(new T[size]) {}

template <class T>
Array<T>::~Array()
{
	delete[]data;
};

template <class T>
Array<T>::Array(const Array<T>& a) :size(a.size), capacity(a.capacity), data(new T[a.capacity])
{
	for (size_t i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
};

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& a)
{
	if (this == &a)		//проверка на совпадение объектов
	{
		return *this;
	}
	delete[]data;
	size = a.size;
	capacity = a.capacity;
	data = new T[capacity];

	for (size_t i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}

	return *this;
}