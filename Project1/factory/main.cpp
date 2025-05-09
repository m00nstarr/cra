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

class TinyDoll : public Doll {
public:
	void push() override {
		cout << "Tiny ����\n";
	};
};

class YellowDoll : public Doll {
public:
	void push() override {
		cout << "������ ����\n";
	};
};

class Shoe {
public:
	virtual ~Shoe() {}
	virtual void wear() = 0;
};

class TinyShoe : public Shoe {
public: 
	void wear() {
		cout << "tiny Shoe �� �Ծ����ϴ�\n";
	}
};

class BlueShoe : public Shoe {
public:
	void wear() {
		cout << "blue Shoe �� �Ծ����ϴ�\n";
	}
};

class Acc {
public:
	virtual ~Acc() {}
	virtual void put() = 0;
};

class TinyAcc : public Acc {
public:
	void put() {
		cout << "tiny Acc�� �����Ͽ����ϴ�.\n";
	}
};

class BlueAcc : public Acc {
public:
	void put() {
		cout << "blue Acc�� �����Ͽ����ϴ�.\n";
	}
};


class Creator {
public:
	virtual Doll* createDoll() = 0;
	virtual Shoe* createShoe() = 0;
	virtual Acc* createAcc() = 0;
};

class BlueCreatorBaby : public Creator {
public:
	Doll* createDoll() override {
		return new BlueDoll();
	}
	Shoe* createShoe() override {
		return new BlueShoe();
	}
	Acc* createAcc() override {
		return new BlueAcc();
	}
};

class TinyCreatorBaby : public Creator {
public:
	Doll* createDoll() override {
		return new TinyDoll();
	}
	Shoe* createShoe() override {
		return new TinyShoe();
	}
	Acc* createAcc() override {
		return new TinyAcc();
	}
};

void play(Creator *creator) {
	Doll* myDoll = creator->createDoll();
	Shoe* myShoe = creator->createShoe();
	Acc* myAcc = creator->createAcc();

	myDoll->push();
	myShoe->wear();
	myAcc->put();

	delete myDoll;
	delete myShoe;
	delete myAcc;
};


int main() {

	Creator* creator = new BlueCreatorBaby();
	play(creator);
	delete creator;

	creator = new TinyCreatorBaby();
	play(creator);
	delete creator;

	return 0;
}