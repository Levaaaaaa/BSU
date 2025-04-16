#pragma once
#include<iostream>
template <class T>
class Array {
public:
    Array();
    explicit Array(size_t);//не будет неявного приведения типов 
    Array(const Array<T>&);
    //конструктор перемещения 
    Array(Array<T>&& a);//&& - rvalue 
    //оператор перемещения 
    Array<T>& operator=(Array<T>&&);
    Array<T>& operator=(const Array<T>&);
    
    T& operator[](const int&);
    const T& operator[](const int&)const;
    
    size_t GetSize() { return capacity; }	//
    void SetSize(size_t, int grow = 0);		//
    
    size_t GetUpperBound() { return (size - 1); }	//
    bool IsEmpty() { return size == 0; }	//
    void Add(T);
    T GetAt(size_t a) { return data[a]; }
    void FreeExtra();		//
    void RemoveAll();		//
    void SetAt(const size_t& i, T a) { if (i<size) data[i] = a; }	//
    void Append(Array<T>);	
    void InsertAt(const size_t&, T);
    void RemoveAt(const size_t&);

    T operator[](int);
    //T& operator[](int);

    ~Array();
private:
    size_t size;//заполнено 
    size_t capacity;//выделено 
    T* data;
};
template<class T>
Array<T>::Array() :size(0), capacity(0), data(nullptr) {}
template<class T>
Array<T>::Array(size_t _size) : size(0), capacity(_size), data(new T[_size]) {}
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
template<class T>
Array<T>::Array(Array<T>&& a) :size(a.size), capacity(a.capacity), data(a.data)
{
    a.size = 0;
    a.capacity = 0;
    a.data = nullptr;
}
template<class T>
Array<T>& Array<T>::operator=(Array<T>&& a)
{
    if (this != &a) {
        delete[]data;
        size = a.size;
        capacity = a.capacity;
        data = a.data;
        a.size = 0;
        a.capacity = 0;
        a.data = nullptr;
    }
    return *this;
}

template <typename T>
void Array<T>::SetSize(size_t size_, int grow)
{
    if (size_ > size) {
        new T[grow];
        capacity += grow;
    }
    else {
        for (size_t i = size_; i < size; i++)
        {
            delete(data[i]);
            capacity--;
        }
    }

    size = size_;
}

template <typename T>
void Array<T>::Add(T t) 
{
    if (size == capacity) {
        setSize(t);
    }
    else {
        data[size + 1] = t;
    }
}

template <typename T>
void Array<T>::FreeExtra()
{
    for (size_t i = GetUpperBound(); i > size; i++)
    {
        delete (data[i]);
        capacity--;
    }

    size = GetUpperBound();
}

template <typename T>
void Array<T>::RemoveAll()
{
    delete[]data;
    size = 0;
    capacity = 0;
}

template <typename T>
void Array<T>::Append(Array<T> a)
{
    for (size_t i = 0; i < a.size(); i++)
    {
        Add(a[i]);
    }
}

template <typename T>
T Array<T>::operator[](int n)
{
    return data[n];
}

template <typename T>
void Array<T>::InsertAt(const size_t& index, T t)
{
    if (index <= size) {
        if (capacity == size) {
            SetSize(size + 1);
        }

        for (size_t  i = size; i >= index; i--)
        {
            data[i + 1] = data[i];
        }
        data[index] = t;
    }
}

template <typename T>
void Array<T>::RemoveAt(const size_t& index)
{
    for (size_t i = size; i > index; i--)
    {
        data[i - 1] = data[i];
    }
    size--;
}
/*
template <typename T>
T& Array<T>::operator[](int index)
{
    return data[index];
}*/