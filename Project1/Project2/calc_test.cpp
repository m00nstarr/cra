#include "gtest/gtest.h"
#include "calc.cpp"

using namespace testing;

class SorterFixture : public Test {
protected:
	void SetUp() override {
		std::vector<int> arr = { 5,2,2,1,2,3,3,3,3,2,1,1,1,7,3,2,1,2,3,8,4,1 };

		ISorter* sorter = new SelectionSorter();
		sortPrinter = new SortPrinter(sorter);

		for (auto e : arr) {
			sortPrinter->insert(e);
		}

		sortPrinter->run();
	}

	void TearDown() override {

		return;
	}

	SortPrinter* sortPrinter;
	int a;

};

class CalcFixture : public Test {

protected:
	Cal *calculator; 

	void SetUp() override {
		calculator = new Cal();
	}

	void TearDown() override {
		delete calculator;
	}
};

TEST_F(CalcFixture, zegopTest) {
	int ret = calculator->getZegop(3);
	EXPECT_EQ(ret, 9);

	EXPECT_EQ(calculator->getZegop(4), 16);
	EXPECT_EQ(calculator->getZegop(5), 25);
}

TEST_F(SorterFixture, selectionSort) {
	cout << a << "\n";
	vector<int> sortedArr = sortPrinter->getArray();

	for (int i = 0; i < sortedArr.size() - 1; i++) {
		int curItem = sortedArr[i];
		int nxtItem = sortedArr[i + 1];

		EXPECT_LE(curItem, nxtItem);
	}
}
