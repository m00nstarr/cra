#include <vector>

#include "movie.cpp";

class Rental {
public:
	Rental(const Movie& movie, int days_rented) : movie{ movie }, daysRented{ days_rented } {}

	int getDaysRented() const {
		return daysRented;
	}

	Movie& getMovie() {
		return movie;
	}

	int getType() {
		return movie.getPriceCode();
	}

private:
	Movie movie;
	int daysRented;
};

class RentalService {
private:
	
	string roundDoubleToString(double tar) {
		char buf[20] = { 0 };
		sprintf_s(buf, sizeof(buf), "%.1f", tar);
		return string{ buf };
	}

public:
	double calculateFee(Rental item)
	{
		double thisAmount = 0;

		switch (item.getType()) {
		case Movie::REGULAR:
			thisAmount += 2;
			if (item.getDaysRented() > 2) {
				thisAmount += (item.getDaysRented() - 2) * 1.5;
			}
			break;

		case Movie::NEW_RELEASE:
			thisAmount += item.getDaysRented() * 3;
			break;

		case Movie::CHILDRENS:
			thisAmount += 1.5;
			if (item.getDaysRented() > 3) {
				thisAmount += (item.getDaysRented() - 3) * 1.5;
			}
			break;
		}

		return thisAmount;
	}
	
	int calculateFrequentPoint(Rental item) {
		if (item.getType() == Movie::NEW_RELEASE && item.getDaysRented() > 1) {
			return 2;
		}
		return 1;
	}

	double getTotalFee(const std::vector<Rental>& rentalList)
	{
		double totalAmount = 0;
		for (Rental rentalMovie : rentalList) {

			totalAmount += (rentalMovie.getMovie().getPricePolicy())->calculateCharge(rentalMovie.getDaysRented());
			//totalAmount += calculateFee(rentalMovie);
		}
		return totalAmount;
	}

	int getTotalFrequentPoints(const std::vector<Rental>& rentalList)
	{
		int frequentRenterPoints = 0;
		for (Rental rentalMovie : rentalList) {
			frequentRenterPoints += calculateFrequentPoint(rentalMovie);
		}

		return frequentRenterPoints;
	}

	string getReceipt(const std::vector<Rental> &rentalList) {
		
		string receipt;
		for (Rental rentalMovie : rentalList) {
			receipt += "\t" + rentalMovie.getMovie().getTitle() + "\t" + roundDoubleToString(calculateFee(rentalMovie)) + "\n";
		}
		receipt += "Amount owed is " + roundDoubleToString(getTotalFee(rentalList)) + "\n";
		receipt += "You earned " + std::to_string(getTotalFrequentPoints(rentalList)) + " frequent renter points";

		return receipt;
	}
};