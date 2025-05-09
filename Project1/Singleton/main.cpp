#include <iostream>
#include <fstream>

using namespace std;

class Singleton {
public:

	static int run() {
		static int cnt = 0; // �ѹ��� �ʱ�ȭ �� , lazy init (���� �ʱ�ȭ!)
		cnt++;
		cout << cnt << "static member\n";
	
		return cnt;
	}

	static Singleton* getInstance() {
		static Singleton instance;

		return &instance;
	}

private:
	// 1ȸ�� �ʱ�ȭ.
	Singleton() {
		cout << "Init!\n";
	}

	Singleton& operator=(const Singleton& other) = delete; // ���� ���� ����
	Singleton(const Singleton& other) = delete; // ���� ������ ����

};

class Logger {
public:
	static Logger& getInstance() {
		static Logger instance;
		return instance;
	}

	void write(std::string message) {
		logfile << message << std::endl;
	}

	~Logger() {
		logfile.close();
	}

private:
	std::ofstream logfile;
	Logger() {
		logfile.open("file.txt");
	}
	Logger& operator=(const Logger& other) = delete;
	Logger(const Logger& other) = delete;
};


int main() {

	// instance ���� ���ٰ����� static ��� ����
	Logger& logger = Logger::getInstance();
	logger.write("AA");

}