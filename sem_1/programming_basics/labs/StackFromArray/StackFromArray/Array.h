#pragma once
#include<iostream>
template <class T>
class Array {
public:
    Array();
    explicit Array(size_t);//�� ����� �������� ���������� ����� 
    Array(const Array<T>&);
    Array(size_t, size_t);
    //����������� ����������� 
    Array(Array<T>&& a);//&& - rvalue 
    //�������� ����������� 
    Array<T>& operator=(Array<T>&&);
    Array<T>& operator=(const Array<T>&);
    
    T operator[](const int&);
    const T& operator[](const int&)const;
    
    size_t sizeForStack() { return size; }
    size_t GetSize() { return capacity; }	//
    void SetSize(size_t, int grow = 0);		//
    
    T* getData() { return this->data; }

    size_t GetUpperBound() { if (size>0) return (size - 1); }	//
    bool IsEmpty() { return size == 0; }	//
    void Add(T);
    T GetAt(size_t a) { if (a<size) return data[a]; }
    void FreeExtra();		//
    void RemoveAll();		//
    void SetAt(const size_t& i, T a) { if (i<size) data[i] = a; }	//
    void Append(Array<T>);	
    void InsertAt(const size_t&, T);
    void RemoveAt(const size_t&);

    T operator[](int);
    T& operator[](int);

    ~Array();

private:
    size_t size;//��������� 
    size_t capacity;//�������� 
    T* data;
};
template<class T>
Array<T>::Array() :size(0), capacity(0), data(nullptr) {}
template<class T>
Array<T>::Array(size_t _size) : size(0), capacity(_size), data(new T[_size]) {}

template <class T>
Array<T>::Array(size_t a, size_t b) : size(a), capacity(b) {}
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
    if (this->size==this->capacity && this->size==(size_+grow))
    {
        return;
    }
    T* tmp = new T[size_ + grow];
    if (size_ > this->size) {
        for (size_t i = 0; i < this->size; i++)
        {
            tmp[i] = this->data[i];
        }
    }
    else if (size_<=this->size) {
        for (size_t i = 0; i < size_; i++)
        {
            tmp[i] = this->data[i];
        }
    }

    delete[]this->data;
    this->data = tmp;

    this->size = size_;
    this->capacity = size_ + grow;
}

template <typename T>
void Array<T>::Add(T t) 
{
    if (size == capacity) {
        SetSize(capacity, capacity/2);
        data[size] = t;
    }
    else {
        data[size] = t;
    }

    this->size++;
}

template <typename T>
void Array<T>::FreeExtra()
{
    if (this->capacity > this->size) {
        this->SetSize(this->size);
    }
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

template <class T>
const T& Array<T>::operator[](int i) const
{
    return data[i];
}