#pragma once
#ifndef ALLINCLUDE_H
#include "AllInclude.h"
#endif // !ALLINCLUDE_H

void Add();

void multiply();

void factorial();

bool checkNumberInString(std::istream&);

double checkInputArithmFun(std::string);

std::vector<std::function<void()>> VectorOfBinArithmFun();

std::vector<std::function<void()>> VectorOfUnArithmFun();

void requestBinArithmOp();

void requestUnArithmOp();
