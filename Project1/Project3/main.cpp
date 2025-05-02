#include<iostream>
#include<vector>
#include<string>
#include <exception>

using std::cout;
using std::string;
using std::vector;

class Splitter {
public:

	vector<string> splitText(const string& text) {

		vector<string> result;
		int a = 0, b = 0;

		while (1) {
			b = text.find("-", a);
			if (b == -1) break;

			string tmp = text.substr(a, b - a);
			result.push_back(tmp);
			a = b + 1;
		}

		return result;
	}

	vector<int> ToInt(const vector<string>& src) {
		vector<int> result;

		for (auto item : src) {
			result.push_back(stoi(item));
		}

		return result;
	}

	int getSum(const vector<int>& arr) {
		int result = 0;

		for (auto item : arr) {
			result += item;
		}
		return result;
	}

	int splitAndSum(string text)
	{
		int result = 0;
		if (text.empty())
		{
			return result;
		}

		text += "-";
		// inline 처리하도록 하는게 좋음.
		return  getSum(ToInt(splitText(text)));
	}
};

int main()
{

	Splitter s;
	cout << s.splitAndSum("100-10-20") << " 130 이여야 함\n";
	cout << s.splitAndSum("1000-100-10-20") << " 1130\n";
	cout << s.splitAndSum("1200-10-10-10-20") << " 1250\n";
	cout << s.splitAndSum("10") << " 10\n";
	//cout << splitAndSum("-") <<  " 0\n";
	cout << s.splitAndSum("") << " Empty , 0\n";
	cout << s.splitAndSum("12345-1") << " 12346\n";
	cout << s.splitAndSum("100-10-200") << " 310\n";


	const double temp_c = 24; // 섭씨 

	double temp_f = (temp_c * 9 / 5) + 32; // 화씨로 변환
	cout << "섭씨 온도를 화씨로 변환: " << temp_c << std::endl;

	const double length = 10.0; // 길이(미터)
	double area = length * length; // 면적 계산 
	cout << "정사각형 면적: " << area << std::endl;

	return 0;
}