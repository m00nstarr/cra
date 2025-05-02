#include <iostream>
#include <vector>
using namespace std;

class Cal {
public:
	int getSum(int a, int b) {
		return a + b;
	}

	int getGob(int a, int b) {
		return a * b;
	}

	int getZegop(int a) {
		return a * a;
	}
};


class ISocket {
public:
	virtual ~ISocket() {

	}

	virtual void plugIn() = 0;
	virtual void unPlug() = 0;
};

class SamsangElect : public ISocket {

public:
	void plugIn() override {
		enable110V();
	}
	void unPlug() override {
		disable110V();
	}
private:
	void enable110V() {
		cout << "삼상 110V ON \n";
	}

	void disable110V() {
		cout << "삼상 110V OFF \n";

	}
};

class SunPower : public ISocket {
public:
	void plugIn() override {
		enable330V();
	}
	void unPlug() override {
		disable330V();
	}
private:
	void enable330V() {
		cout << "태양열 330V ON \n";
	}

	void disable330V() {
		cout << "태양열 330V OFF \n";

	}
};



class RobotHead {
public:
	RobotHead() {

	}

	virtual void study() {
		cout << "공부중\n";
	}
};


class ISorter {
public:
	virtual void run(vector<int>&) = 0;
	virtual string getName() = 0;
};

class BubbleSorter : public ISorter {

public:
	BubbleSorter() {
		type = "Bubble";
	}

	void run(vector<int>& arr) {
		for (int i = 0; i < arr.size(); i++) {
			for (int j = 0; j < arr.size() - 1 - i; j++) {
				if (arr[j] > arr[j + 1]) {
					std::swap(arr[j], arr[j + 1]);
				}
			}
		}
	}

	string getName() {
		return type;
	}

private:
	string type;
};

class SelectionSorter : public ISorter {
public:
	SelectionSorter() {
		type = "selection";
	}

	void run(vector<int>& arr) {
		for (int i = 0; i < arr.size(); i++) {
			for (int j = i + 1; j < arr.size(); j++) {
				if (arr[i] > arr[j]) {
					std::swap(arr[i], arr[j]);
				}
			}
		}
	}

	string getName() {
		return type;
	}
private:
	string type;
};


class SortPrinter {
public:

	SortPrinter(ISorter* sorter)
	{
		this->sorter = sorter;
	}

	void insert(int num) {
		arr.push_back(num);
	}

	void selection(ISorter* sorter) {
		this->sorter = sorter;
	}

	void run() {
		sorter->run(arr);
	}

	void show() {
		cout << sorter->getName() << " 정렬 사용 \n";
		for (auto e : arr) {
			cout << e << " ";
		}
		cout << "\n";
	}
	
	const vector<int>& getArray() {
		return arr;
	}


private:
	ISorter* sorter;
	vector<int> arr;
};
