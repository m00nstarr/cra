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
		cout << "ÆÄ¶ûÆÄ¶û\n";
	};
};

class RedDoll : public Doll {
public:
	void push() override {
		cout << "»¡°­»¡°­\n";
	};
};

class Factory {
public:
	Doll* makeFactory(string type) {

		if (type == "red") {
			return new RedDoll();
		}
		
		if (type == "blue") {
			return new BlueDoll();
		}

		return nullptr;
	}
};

int main() {

	Factory* dollFactory = new Factory();
	Doll* i_made_this_doll = dollFactory->makeFactory("blue");
	
	i_made_this_doll->push();
	delete i_made_this_doll;

	i_made_this_doll = dollFactory->makeFactory("red");
	i_made_this_doll->push();

	delete i_made_this_doll;
	delete dollFactory;

	return 0;
}