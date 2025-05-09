#include <vector>
#include <string>
#include "movie.cpp"
#include "rental.cpp"

using std::vector;
using std::string;

class Customer {
private:
    string name;
    vector<Rental> rentals;

public:
    Customer(const string& name) : name{ name } {}

    void addRental(Rental arg) {
        rentals.push_back(arg);
    }

    string getName() const {
        return name;
    }

    vector<Rental>& getVectorList() {
        return rentals;
    }



    string statement() {
       
        RentalService videoRentalService;
        return  "Rental Record for " + getName() + "\n"
            + videoRentalService.getReceipt(rentals);
    }
};
