#include <iostream>

using namespace std;

class Singleton {
public:
	static void run() {
		cout << "static ��� �Լ��� ����\n";
	}

};


int main() {

	// instance ���� ���ٰ����� static ��� ����
	Singleton::run();
}