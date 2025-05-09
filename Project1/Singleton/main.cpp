#include <iostream>

using namespace std;

class Singleton {
public:
	static void run() {
		cout << "static 멤버 함수의 이해\n";
	}

};


int main() {

	// instance 없이 접근가능한 static 멤버 변수
	Singleton::run();
}