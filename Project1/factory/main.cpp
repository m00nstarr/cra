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
		cout << "파랑파랑 인형\n";
	};
};

class TinyDoll : public Doll {
public:
	void push() override {
		cout << "Tiny 인형\n";
	};
};

class YellowDoll : public Doll {
public:
	void push() override {
		cout << "노랑노랑 인형\n";
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
		cout << "tiny Shoe 를 입었습니다\n";
	}
};

class BlueShoe : public Shoe {
public:
	void wear() {
		cout << "blue Shoe 를 입었습니다\n";
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
		cout << "tiny Acc를 착용하였습니다.\n";
	}
};

class BlueAcc : public Acc {
public:
	void put() {
		cout << "blue Acc를 착용하였습니다.\n";
	}
};


class Creator {
public:
	Doll* myDoll;

	void play() {
		Doll* myDoll = createDoll();
		Shoe* myShoe = createShoe();
		Acc* myAcc = createAcc();

		myDoll->push();
		myShoe->wear();
		myAcc->put();

		delete myDoll;
		delete myShoe;
		delete myAcc;
	};

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

int main() {

	Creator* creator = new BlueCreatorBaby();
	creator->play();
	delete creator;

	creator = new TinyCreatorBaby();
	creator->play();
	delete creator;

	return 0;
}