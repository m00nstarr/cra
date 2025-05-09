class Movie;

class PricePolicy {
public:
	virtual double calculateCharge(int) = 0;
};

class NewReleasePricePolicy : public PricePolicy {
public:
	double calculateCharge(int daysRented) override {
		return  (daysRented * 3);
	}
};

class ChildrenPricePolicy : public PricePolicy {
public:
	double calculateCharge(int daysRented) override {
		double thisAmount = 1.5;
		if (daysRented > 3) {
			thisAmount += (daysRented - 3) * 1.5;
		}
		return thisAmount;
	}
};

class RegularPricePolicy : public PricePolicy {
public:
	double calculateCharge(int daysRented) override {
		double thisAmount = 2;
		if (daysRented > 2) {
			thisAmount += (daysRented - 2) * 1.5;
		}
		return thisAmount;
	}
};

