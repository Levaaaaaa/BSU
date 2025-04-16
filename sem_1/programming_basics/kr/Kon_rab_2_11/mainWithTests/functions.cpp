#include "functions.h"

std::vector<std::string> readFromFile(const std::string& path)
{
	std::ifstream fin(path);
	std::vector<std::string> v;
	std::string str;
	while (fin >> str)
	{
		v.push_back(str);
	}

	//std::cout << "readFromFile" << "\n";
	return v;
}

void validateTweliveDigitNumbers(std::vector<std::string>& v) //  3  6 7
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].size() != 12) {
			v.erase(v.begin() + i, v.begin() + i + 1);
			i--;
		}
	}
}
/*
void validateTweliveDigitNumbers(std::vector<std::string> &v)
{
	for (int i = 0; i<v.size(); i++)
	{
		if (v[i].size() != 12)
		{
			v.erase(v.begin() + i, v.begin() + i + 1);
			i--;
		}
	}
}
*/
std::string codeNumber(std::string num)
{
	int sum1 = countDigintsSum(num, 0) * 3;
	int sum2 = countDigintsSum(num, 1);

	int sum = (sum1 + sum2) % 10;

	std::ostringstream ostr;
	ostr << sum;
	std::string sCode = ostr.str();

	return sCode;
}

int countDigintsSum(std::string number, bool isOdd)
{
	int sum = 0;
	//int j = (isOdd) ? 2 : 1;

	if (isOdd)
	{
		for (int i = number.size() - 2; i >= 0; i -= 2)
		{
			char c = number[i];
			std::string s(1, c);
			sum += stoi(s);
		}
	}

	else
	{
		for (int i = number.size() - 1; i >= 0; i -= 2)
		{
			char c = number[i];
			std::string s(1, c);
			sum += stoi(s);
		}
	}/*
	for (size_t i = number.size() - j; i >= 0; i -=2)
	{
		char c = number[i];
		std::string s(1, c);
		sum += stoi(s);
	}
	*/
	return sum;
}

void DataConversion(std::vector<std::string>& initalData, std::vector<std::string> convertedData)
{
	for (size_t i = 0; i < convertedData.size(); i++)
	{
		std::string s = convertedData[i];
		std::string sCode = codeNumber(s);

		s.insert(0, sCode);
		initalData.push_back(s);
	}
	//std::cout << "DataConversion" << "\n";
	printVectorInFile(initalData);
}

bool checkNumber(std::string number)
{
	std::string code = codeNumber(number);
	if (code.compare("0"))
	{
		return true;
	}

	return false;
}

bool validateThirteenDigitNumbers(std::vector<std::string> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (!checkNumber(v[i]))
		{
			return false;
		}
	}

	//std::cout << "validateThirteenDigitNumber" << "\n";
	return true;
}

void printVectorInFile(std::vector<std::string> v)
{
	std::ofstream fout("output.txt");
	for (size_t i = 0; i < v.size(); i++)
	{
		fout << v[i] << "\n";
	}
}

void result(bool t)
{
	if (t)
	{
		std::cout << "Znaika counted all right";
	}
	else
	{
		std::cout << "Znaika counted not right";
	}

	//std::cout << "result" << "\n";
}