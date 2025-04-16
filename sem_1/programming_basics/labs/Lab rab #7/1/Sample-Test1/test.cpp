#include "pch.h"
#include "..\1Fun.h"

TEST(TestCaseIsEven, NegNumIsEven) {
  EXPECT_FALSE(isEven(-1));
  EXPECT_TRUE(isEven(-2));
}