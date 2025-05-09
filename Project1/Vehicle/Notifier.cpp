#include <iostream>
#include <string>
#include "Phone.cpp"
#include "Emailer.cpp"

using namespace std;

class Notifier {
public:

	void Notify(string weather_description) {

		if (weather_description == "rainy") {
			string alert = phone_.GenerateWeatherAlert(weather_description);
			cout << alert << "\n";
		}
		if (weather_description == "sunny") {
			string alert = emailer_.GenerateWeatherAlert(weather_description);
			cout << alert << "\n";
		}
	}

	Phone phone_;
	Emailer emailer_;
};