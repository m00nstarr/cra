#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <string>

#include "Wheel.cpp"

using namespace std;

TEST(WheelTest, input1Test) {
	vector<string> strs;
	int map[4][15] = { 0 };
	string userdata = "";
	int n = 0;

	freopen_s(new FILE*, "input2.txt", "r", stdin);
	cin >> n;

	//입력
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		strs.push_back(temp);
	}
	cin >> userdata;

	Wheel* wheel = new Wheel(strs, userdata);
	EXPECT_EQ(6500, wheel->getPrice());
}


TEST(WheelTest, input2Test) {
	vector<string> strs;
	int map[4][15] = { 0 };
	string userdata = "";
	int n = 0;

	FILE* fp;
	freopen_s(&fp, "input2.txt", "r", stdin);
	cin >> n;

	//입력
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		strs.push_back(temp);
	}
	cin >> userdata;
	fclose(fp);

	Wheel* wheel = new Wheel(strs, userdata);
	EXPECT_EQ(9500, wheel->getPrice());
}