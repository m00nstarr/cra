#include <iostream>
#include "WeatherTracker.cpp"

int main() {

	WeatherTracker *weather = new WeatherTracker();

	weather->SetCurrentConditions("rainy");


	return 0;
}