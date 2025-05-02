#include "gtest/gtest.h"
#include "calc.cpp"
TEST(CalcTest, getSum) {
	// Arrange 
	Cal calc;

	//act
	int ret = calc.getSum(2, 3);

	//assert
	EXPECT_EQ(ret, 5);
}

TEST(CalcTest, getGob) {

	Cal calc;
	EXPECT_EQ(calc.getGob(2, 3), 6);
	EXPECT_EQ(calc.getGob(33, 4), 132);

}

