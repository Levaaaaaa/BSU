#include "pch.h"

#include "..\Calculator\HardMath.cpp"
#include "..\Calculator\HardMath.h"
/*
TEST(DerivativeTestCase, DerivativeTest) {
	HardMath math;
	std::function<double(double)> ptr = *(math.sin);
	EXPECT_EQ(static_cast<int>(math.derivative(ptr, 0)), 18);
}
*/
TEST(TrigonometriaTestCase, SinTest)
{
	Sin sin;
	//std::function<double(double)> ptr = *math.sin;
	EXPECT_EQ(round(sin.operation(M_PI / 6) * 10) / 10, 0.5);	//округление
}

TEST(TrigonometriaTestCase, CosTest)
{
	Cos cos;
	EXPECT_EQ(round(cos.operation(M_PI / 3) * 10) / 10, 0.5);	//округление
}

TEST(TrigonometriaTestCase, TgTest)
{
	Tg tg;
	EXPECT_EQ(round(tg.operation(M_PI / 4) * 10) / 10, 1);	//округление
}

TEST(InverseTrigonometriaTestCase, ArcSinTest)
{
	HardMath math;
	EXPECT_EQ(round(math.arcsin(0.5) * 10) / 10, round((M_PI / 6) * 10) / 10);	//округление
}

TEST(InverseTrigonometriaTestCase, ArcCosTest)
{
	HardMath math;
	EXPECT_EQ(round(math.arccos(0.5) * 10) / 10, round((M_PI / 3) * 10) / 10);	//округление
}

TEST(ExponentaTestCase, ExponentaTest)
{
	HardMath math;
	EXPECT_EQ(math.expon(0), 1);
	EXPECT_EQ(round(math.expon(1) * 10) / 10, 2.7);
}

TEST(ExponentaTestCase, LnTest)
{
	HardMath math;
	EXPECT_EQ(round(math.ln(1)), 0);
	EXPECT_EQ(round(math.ln(-1)), 0);
	EXPECT_EQ(round(math.ln(2) * 10) / 10, 0.7);
	EXPECT_EQ(round(math.ln(8)), 2);
	//EXPECT_THROW(math.ln(-1), 1);
}

TEST(ExponentaTestCase, LogTest)
{
	HardMath math;
	EXPECT_EQ(round(math.log(2, 8)), 3);
	//EXPECT_EQ(round(math.expon(1) * 10) / 10, 2.7);
}