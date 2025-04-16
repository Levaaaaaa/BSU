#include "pch.h"
#include "..\functions.cpp"

TEST(TestCaseCountDigintsSum, TestName1) {
	EXPECT_EQ(countDigintsSum("123456789101112", false), 36);
}

TEST(TestCaseCodeNumber, TestName2) {
	EXPECT_EQ(codeNumber("03600029145"), "2");
}