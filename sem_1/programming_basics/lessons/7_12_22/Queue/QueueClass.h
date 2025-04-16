#pragma once

#include <vector>

template <class T>
class Queue
{
public:
	Queue();
	Queue(const T&);

	bool isEmpty();
	T front();
	T back();

	void delFirstEl(std::vector<T>& v);

	void push(const T&);
	T pop();

	~Queue() = default;
private:
	size_t start;
	size_t end;
	std::vector<T> data;
};

template <class T>
Queue<T>::Queue()
{
	start = 0;
	end = 0;
	data = { 0 };
}

template <class T>
Queue<T>::Queue(const T& t)
{
	start = 0;
	end = 0;
	data.push_back(t);
}

template <class T>
void Queue<T>::push(const T& t)
{
	data.push_back(t);
	end++;
	
}

template <class T>
bool Queue<T>::isEmpty()
{
	return data.size() == 0;
}

template <class T>
T Queue<T>::pop()
{
	if (this->isEmpty()) {
		return NULL;
	}
	T first = data[0];
	if (data.size() > 2) {
		delFirstEl(data);
	}
	else {
		data.pop_back();
	}

	return first;
}

template <class T>
T Queue<T>::front()
{
	return data[start];
}

template <class T>
T Queue<T>::back()
{
	return data[end];
}

template <class T>
void Queue<T>::delFirstEl(std::vector<T> &v)
{
		for (size_t i = 1; i < v.size() - 1; i++)
		{
			v[i - 1] = v[i];
		}
}