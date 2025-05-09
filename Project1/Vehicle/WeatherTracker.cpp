#include <iostream>
#include <string>
#include "Notifier.cpp"
using namespace std;

class WeatherTracker {
public:
	WeatherTracker() {
		current_conditions_ = "";
		notifier = new Notifier();
	}

	void SetCurrentConditions(string weather_description) {
		current_conditions_ = weather_description;
		notifier->Notify(weather_description);
	}

private:
	string current_conditions_;
	Notifier *notifier;
};