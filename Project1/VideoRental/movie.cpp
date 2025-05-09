#pragma once
#include <string>
#include "pricePolicy.cpp"
using std::string;

class Movie {
public:
	static const int CHILDRENS = 2;
	static const int NEW_RELEASE = 1;
	static const int REGULAR = 0;

	Movie(const string& title, int price_code) : title{ title }, priceCode{ price_code }, pricePolicy{ setPricePolicy(price_code) } {
	}

	int getPriceCode() {
		return priceCode;
	}

	PricePolicy* setPricePolicy(int price_code) {
		switch (price_code) {
		case Movie::NEW_RELEASE:
			return new NewReleasePricePolicy();
		case Movie::CHILDRENS:
			return new ChildrenPricePolicy();
		case Movie::REGULAR:
			return new RegularPricePolicy();
		}
		return nullptr;
	}


	PricePolicy* getPricePolicy() {
		return pricePolicy;
	}

	void setPriceCode(int price_code)
	{
		priceCode = price_code;
		pricePolicy = setPricePolicy(price_code);
	}

	string getTitle() const {
		return title;
	}

private:
	PricePolicy* pricePolicy;
	string title;
	int priceCode;
};


