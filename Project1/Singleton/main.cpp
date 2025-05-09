#include <iostream>
#include <fstream>

using namespace std;

class Singleton {
public:

	static int run() {
		static int cnt = 0; // 한번만 초기화 됨 , lazy init (늦은 초기화!)
		cnt++;
		cout << cnt << "static member\n";
	
		return cnt;
	}

	static Singleton* getInstance() {
		static Singleton instance;

		return &instance;
	}

private:
	// 1회만 초기화.
	Singleton() {
		cout << "Init!\n";
	}

	Singleton& operator=(const Singleton& other) = delete; // 복사 대입 삭제
	Singleton(const Singleton& other) = delete; // 복사 생성자 삭제

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

	// instance 없이 접근가능한 static 멤버 변수
	Logger& logger = Logger::getInstance();
	logger.write("AA");

}