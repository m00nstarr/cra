#include "gtest/gtest.h"
#include <iostream>
#include "main.h"

using namespace std;

TEST(sumChecker, sumTest) {

	string str = "25+61=86"; //PASS
	EXPECT_EQ(true, sumCheck(str)) << "25+61=86\n";

	str = "12345+12345=24690"; //PASS
	EXPECT_TRUE(sumCheck(str)) << str << "\n";

	str = "12345+=12345"; // ERROR
	EXPECT_FALSE(sumCheck(str)) << str << "\n";

	str = "5++5=10"; //ERROR
	EXPECT_FALSE(sumCheck(str)) << str << "\n";

	str = "10000+1=10002"; //FAIL
	EXPECT_FALSE(sumCheck(str)) << str << "\n";


}