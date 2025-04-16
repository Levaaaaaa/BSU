#pragma once

#include <iostream>

template <class T>
class List 
{
public :
    struct Node
    {
        T data;
        Node* prev;
        Node* next;
        Node() = default;
        Node(const T& _data, Node* _prev = nullptr, Node* _next = nullptr) : data{ _data }, prev{ _prev }, next{ _next } {}

        ~Node() = default;
    };

    List() : head(nullptr), tail(nullptr), size(0) {}
    
    void push_back(const T&);
    T pop_back();
    
    ~List();
private:
    size_t size;
    Node* head;
    Node* tail;
};

template <class T>
void List<T>::push_back(const T& t)
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
T List<T>::pop_back()
{
    Node* temp = this->tail;
    T val;

    if (this->size == 0) {
        throw "List is Empty\n";
    }
    else if (this->size == 1) {
        this->head = this->tail = nullptr;
    }
    else {
        this->tail = temp->prev;
        temp->prev->next = nullptr;
    }
    val = temp->data;
    delete temp;
    this->size--;
    return val;
}
template <class T>
List<T>::~List()
{
    while (this->size!=0)
    {
        this->pop_back();
    }
}