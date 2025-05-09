#include <iostream>

using namespace std;

class Doll {
public:
	virtual ~Doll() {}
	virtual void push() = 0;
};

class BlueDoll : public Doll {
public:
	void push() override {
		cout << "�Ķ��Ķ� ����\n";
	};
};

class RedDoll : public Doll {
public:
	void push() override {
		cout << "�������� ����\n";
	};
};

class YellowDoll : public Doll {
public:
	void push() override {
		cout << "������ ����\n";
	};
};

class Creator {
public:
	Doll* myDoll;

	void play() {
		Doll* myDoll = factoryMethod();
		myDoll->push();
	};
	virtual Doll* factoryMethod() {
		return nullptr;
	};
};

class BlueCreatorBaby : public Creator {
public:
	Doll* factoryMethod() override {
		return new BlueDoll();
	}
};

class RedCreatorBaby : public Creator {
public:
	Doll* factoryMethod() override {
		return new RedDoll();
	}

};


int main() {

	Creator* creator = new BlueCreatorBaby();
	creator->play();


	return 0;
}