#pragma once
#include <iostream>

using std::cout;
using std::cin;

template<typename T>  
void Allocate(T*&, size_t);

template<typename T> 
void Diallocate(T*&);

template<typename T>
void printArray(T*, size_t);

template<typename T>
void ReadArray(T*, size_t);