#include "gtest/gtest.h"

#include <vector>
#include "D:\\Leva\\BSU\\ОиМП\\Tasks\\Занятия\\Занятие 26_10_22\\Google Test\\ptrFun.h"
#include "D:\\Leva\\BSU\\ОиМП\\Tasks\\Занятия\\Занятие 26_10_22\\Google Test\\ptrFun.cpp"

TEST(TCheckFile, TestFileRead)
{
	std::vector<int> V;
	readFile("D:\\Leva\\BSU\\ОиМП\\Tasks\\Занятия\\Занятие 26_10_22\\Google Test\\Текст2.txt", V);

	for (size_t i = 0; i < V.size(); i++)
	{
		ASSERT_NE(V.size(), 0);
	}
}