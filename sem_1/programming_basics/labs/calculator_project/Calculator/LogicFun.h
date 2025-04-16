#pragma once
#ifndef ALLINCLUDE_H
#include "AllInclude.h"
#endif // !ALLINCLUDE_H

void ne();

void conjunction();

void disjunction();

bool checkInputLogFun(std::string);

std::vector<std::function<void()>> VectorOfBinLogFun();

std::vector<std::function<void()>> VectorOfUnLogFun();

void requestUnLogOp();

void requestBinLogOp();