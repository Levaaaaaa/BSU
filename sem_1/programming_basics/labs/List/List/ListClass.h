#pragma once

#include <ostream>
#include <istream>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <string>

template <class T>
class List
{
public:
    struct Node
    {
        T data;
        Node* prev;
        Node* next;
        Node() = default; //new Node()
        Node(const T& _data, Node* _prev = nullptr, Node* _next = nullptr) :
            data(_data), prev(_prev), next(_next) {};
        
        //new Node(key)
             //new Node(key,tail)
             //new Node(key, nullptr,head)
        ~Node() = default;
    };
    List();									//+
    List(const std::initializer_list<T>&);  //+
    ~List() = default;                            
    size_t get_size()const { return size; } //+
    void pushBack(const T&);                //+    
    T popBack();                            //+
    void pushFront(const T&);               //+
    T popFront();                           //+    
    void insert(const T&, size_t);          //+
    T erase(size_t);                        //+
    void replace(const T&, const T&);       //+
    T& operator[](size_t);                  //+
    const T& operator[](size_t) const;      //+
    template<class T>
    friend std::ostream& operator<<(std::ostream&, List<T>&);
private:
    size_t size;
    Node* head;
    Node* tail;
public:
    

    class ReverseIterator
    {
    public:
        ReverseIterator() = default;
        ReverseIterator(Node* _ptr) :ptr(_ptr) {};
        //префиксна€ форма
        ReverseIterator& operator++()
        {
            ptr = ptr->prev;
            return *this;
        }
        //постфиксна€ форма
        ReverseIterator& operator++(int)
        {
            ReverseIterator temp(*this);
            this->operator++();
            return temp;
        }
        T& operator*() const { return ptr->data; }
        bool operator==(const ReverseIterator& i) const
        {
            return ptr == i.ptr;
        }
        bool operator!=(const ReverseIterator& i) const
        {
            return ptr != i.ptr;
        }
        ~ReverseIterator() = default;
    private:
        Node* ptr;
    };
    ReverseIterator Begin() { return ReverseIterator(tail); }
    ReverseIterator End() { return ReverseIterator(head->prev); }
};



template <class T>
List<T>::List()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
List<T>::List(const std::initializer_list<T>& v)    //возможна ошибка, т.к. v начиает записывать не в голову, а в следующую за ней €чейку
{
    
    List();
    for (T t : v)
    {
        pushBack(t);
    }
}
/*
template <class T>
List<T>::~List()
{
    Node* cur = head;
    if (get_size() == 1) {
        delete cur;
        return;
    }
    else if (get_size() == 0) return;
    else {
        for (size_t i = 0; i < get_size() - 1; i++, cur = cur->next)
        {
            delete cur;
        }
    }
}*/

template <class T>
void List<T>::pushBack(const T& t)
{
    Node* temp = new Node(t, this->tail, nullptr);

    if (this->size == 0) {
        this->head = temp;
    }
    else {
        this->tail->next = temp;
    }

    this->size++;
    this->tail = temp;
}

template <class T>
T List<T>::popBack()
{
    Node* last = this->tail;
    if (get_size() == 0) throw 1;
    else if (get_size() == 1) head = tail = nullptr;
    else {
        tail = last->prev;
        tail->next = nullptr;
    }
    T value = last->data;
    delete last;
    size--;
    return value;
}

template <class T>
T List<T>::popFront()
{
    Node* last = this->head;
    if (get_size() == 0) throw 1;
    else if (get_size() == 1) head = tail = nullptr;
    else {
        head = last->next;
        head->prev = nullptr;
    }
    T value = last->data;
    delete last;
    size--;
    return value;
}

template <class T>
void List<T>::pushFront(const T& t)
{
    Node* temp = new Node(t, nullptr, this->head);

    if (this->size == 0) {
        this->head = temp;
    }
    else {
        this->head->prev = temp;
    }

    this->size++;
    this->head = temp;
}

template <class T>
void List<T>::insert(const T& t, size_t s)
{
    if (s >= get_size()) throw 2;
    Node* cur = head;
    for (size_t i = 0; i < s;i++)
    {
        cur = cur->next;
    }

    if (s==0)
    {
        pushFront(t);
        return;
    }
    else if (s==get_size()-1) {
        pushBack(t);
        return;
    }
    Node node(t, cur->prev, cur);
    cur->prev->next = &node;
    cur->prev = &node;
    size++;
}

template <class T>
T List<T>::erase(size_t index)
{
    if (index >= get_size()) throw 2;
    Node* cur = head;
    if (index == 0) {
        return popFront();
    }
    else if (index == get_size()-1) return popBack();
    else {
        for (size_t i = 0; i < get_size(); cur = cur->next, i++)
        {
            if (i == index) {
                Node* p = cur->prev;
                Node* n = cur->next;
                p->next = n;
                n->prev = p;
                delete cur;
            }
        }
    }
}

template <class T>
void List<T>::replace(const T& t1, const T& t2)
{
    for (Node* cur = head;  cur != tail; cur = cur->prev)
    {
        if (cur->data == t1) {
            cur->data = t2;
        }
    }
}

template <class T>
T& List<T>::operator[](size_t index)
{
    if (index >= get_size()) throw 2;
    Node* cur = head;
    for (size_t i = 0; i < get_size(); cur = cur->next, i++)
    {
        if (i == index) return cur->data;
    }
}

template <class T>
const T& List<T>::operator[](size_t index) const
{
    if (index >= get_size()) throw 2;
    Node* cur = head;
    for (size_t i = 0; i < get_size(); i++, cur = cur->next)
    {
        if (i == index) break;
    }
    const T result = cur->data;
    return result;
}

template <class T>
std::ostream& operator<<(std::ostream& os, List<T>& list)
{
    for (size_t i = 0; i < list.get_size(); i++)
    {
        os << list[i] << " ";
    }
    os << "\n\n";
    return os;
}