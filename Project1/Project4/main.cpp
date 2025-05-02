#include <string>
#include <vector>
#include <iostream>
#include "main.h"

#include "gtest/gtest.h"
using namespace std;

class SumChecker {
public:

	int getCharCnt(const std::string& str, char checkChar) {

		int count = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == checkChar) {
				count++;
			}
		}

		return count;
	}

	int getPositionFromString(const std::string& str, char checkChar) {
		int idx = 0;
		for (int idx = 0; idx < str.length(); idx++) {
			if (str[idx] == checkChar) {
				cout << idx << "\n";
				return idx;
			}
		}

		if (idx == str.length()) {
			return -1;
		}
	}

	int getIntValueFromString(const std::string& str, int start, int end) {

		return stoi(str.substr(start, end));

	}

	bool sumCheck(const std::string& str) {
		bool notIntValueFlag = false;

		int cnt1 = getCharCnt(str, '+');
		int cnt2 = getCharCnt(str, '=');

		if (cnt1 != 1 || cnt2 != 1) {
			return false;
		}

		int p1 = getPositionFromString(str, '+');
		int p2 = getPositionFromString(str, '=');

		if ((p1 >= p2 - 1) ||
			(p1 < 1) ||
			(p2 < 3) ||
			(p2 >= str.length() - 1))
		{
			return false;
		}

		if (isNotValid(str)) {
			return false;
		}

		int n1 = getIntValueFromString(str, 0, p1);
		int n2 = getIntValueFromString(str, p1 + 1, p2 - p1 - 1);
		int n3 = getIntValueFromString(str, p2 + 1, str.length() - 1);

		if (n1 + n2 == n3) {
			cout << "PASS";
			return true;
		}

		return false;
	}

	bool isNotValid(const std::string& str)
	{
		bool notIntValueFlag = false;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '+' || str[i] == '=') {
				continue;
			}

			if (!(str[i] >= '0' && str[i] <= '9')) {
				return true;
			}
		}
		return notIntValueFlag;
	}

};

bool sumCheck(std::string& str)
{
	SumChecker sumchecker;
	return sumchecker.sumCheck(str);
}

int main()
{
	testing::InitGoogleTest();
	RUN_ALL_TESTS();

	return 0;
}