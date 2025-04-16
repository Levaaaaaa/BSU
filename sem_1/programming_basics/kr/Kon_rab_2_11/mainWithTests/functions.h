#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <typeinfo>
#include <iostream>
#include <sstream>
/*
template <typename T>
void printData(std::ostream out, const std::string str, const T& data, char endLineDelimeter = '\n');

template <typename T>
void printData1(std::ostream out, const std::vector<T> data, const std::string& delimeter, char endLineDelimeter = '\n');
*/
std::vector<std::string> readFromFile(const std::string& path);

void validateTweliveDigitNumbers(std::vector<std::string>&);

std::string codeNumber(std::string num);
int countDigintsSum(std::string number, bool isOdd);

void DataConversion(std::vector<std::string>& initalData, std::vector<std::string> convertedData);

bool checkNumber(std::string number);

bool validateThirteenDigitNumbers(std::vector<std::string>);
/*
template <typename T>
void printData(std::ostream out, const std::string str, const T& data, char endLineDelimeter = '\n')
{
	out << data << endLineDelimeter;
}

template <typename T>
void printData1(std::ostream out, const std::vector<T> data, const std::string& delimeter, char endLineDelimeter = '\n')
{
	for (int i = 0; i < data.size(); i++)
	{
		out << data[i] << endLineDelimeter;
	}
}
*/
void printVectorInFile(std::vector<std::string> v);

std::vector<std::string> massivZnaiki(std::vector<std::string> v);

void result(bool t);