#include "pch.h"
#include "..\Rational.h"
#include "..\Rational.cpp"

TEST(TDefaultConstructor, TestConstr1) {
	Rational r;
	EXPECT_EQ(r.getNumer(), 0);
	EXPECT_EQ(r.getDenom(), 1);
}

TEST(TConstructor, TestConstr2) {
	Rational r(1,7);
	EXPECT_EQ(r.getNumer(), 1);
	EXPECT_EQ(r.getDenom(), 7);
}

TEST(TestSum, TestReduce) {
	Rational r(1, 2), r1(1, 2);
	Rational sum;
	sum = r1.add(r);
	EXPECT_EQ(sum.getNumer(), 1);
	EXPECT_EQ(sum.getDenom(), 1);
}

TEST(TestSum, TestZero)
{
	Rational r(0, 2), r1(0, 2);
	Rational sum;
	sum = r1.add(r);
	EXPECT_EQ(sum.getNumer(), 0);
	EXPECT_EQ(sum.getDenom(), 4);
}