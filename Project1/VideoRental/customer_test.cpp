#include "gmock/gmock.h"
#include "customer.cpp"


TEST(CustomerTest, NoRentalTest) {
    Customer customer{ string{ "NOT IMPORTANT"} };

    string expected = 
        string{"Rental Record for NOT IMPORTANT\n"}
        + string{"Amount owed is 0.0\n"}
        + string{ "You earned 0 frequent renter points" };

    EXPECT_EQ(expected, customer.statement());
}


TEST(CustomerTest, RegularRentalTest) {
    Customer customer{ string{ "BOB"} };

    customer.addRental(Rental{ Movie{"AAA Live Concert", Movie::REGULAR}, 3 });
    string expected = "" 
        + string{"Rental Record for BOB\n"}
        + string{"\tAAA Live Concert\t3.5\n"}
        + string{ "Amount owed is 3.5\n" }
        + string{"You earned 1 frequent renter points"}
        ;

    EXPECT_EQ(expected, customer.statement());
}


TEST(CustomerTest, ChildrenRentalTest) {
    Customer customer{ string{ "BOB"} };

    customer.addRental(Rental{ Movie{"AAA Live Concert", Movie::REGULAR}, 3 });
    customer.addRental(Rental{ Movie{"PinkPong", Movie::CHILDRENS}, 4 });

    string expected = ""
        + string{"Rental Record for BOB\n"}
        + string{"\tAAA Live Concert\t3.5\n"}
        + string{"\tPinkPong\t3.0\n"}
        + string{"Amount owed is 6.5\n"}
    + string{ "You earned 2 frequent renter points" };
    ;

    EXPECT_EQ(expected, customer.statement());
}

TEST(CustomerTest, ChangePricePolicyTest) {
    Customer customer{ string{ "BOB"} };

    customer.addRental(Rental{ Movie{"AAA Live Concert", Movie::REGULAR}, 3 });
    customer.addRental(Rental{ Movie{"PinkPong", Movie::CHILDRENS}, 4 });

    customer.getVectorList()[1].getMovie().setPriceCode(Movie::REGULAR);

    
    string expected = ""
        + string{ "Rental Record for BOB\n" }
        + string{ "\tAAA Live Concert\t3.5\n" }
        + string{ "\tPinkPong\t3.0\n" }
        + string{ "Amount owed is 6.5\n" }
    + string{ "You earned 2 frequent renter points" };
    ;

    EXPECT_NE(expected, customer.statement());
}



TEST(CustomerTest, NewReleaseRentalTest) {
    Customer customer{ string{ "BOB"} };

    customer.addRental(Rental{ Movie{"Mayhem Ball", Movie::NEW_RELEASE}, 10 });
    string expected = ""
        + string{"Rental Record for BOB\n"}
        + string{"\tMayhem Ball\t30.0\n"}
        + string{"Amount owed is 30.0\n"}
        + string{ "You earned 2 frequent renter points" };
    ;

    EXPECT_EQ(expected, customer.statement());
}

TEST(CustomerTest, SampleTest) {
    Customer customer{ string{ "Bob" } };

    customer.addRental(Rental{ Movie{ string{ "Jaws" }, Movie::REGULAR }, 2 });
    customer.addRental(Rental{ Movie{ string{ "Golden Eye" }, Movie::REGULAR }, 3 });
    customer.addRental(Rental{ Movie{ string{ "Short New" }, Movie::NEW_RELEASE }, 1 });
    customer.addRental(Rental{ Movie{ string{ "Long New" }, Movie::NEW_RELEASE }, 2 });
    customer.addRental(Rental{ Movie{ string{ "Bambi" }, Movie::CHILDRENS }, 3 });
    customer.addRental(Rental{ Movie{ string{ "Toy Story" }, Movie::CHILDRENS }, 4 });

    string expected = "" +
        string{ "Rental Record for Bob\n" } +
        string{ "\tJaws\t2.0\n" } +
        string{ "\tGolden Eye\t3.5\n" } +
        string{ "\tShort New\t3.0\n" } +
        string{ "\tLong New\t6.0\n" } +
        string{ "\tBambi\t1.5\n" } +
        string{ "\tToy Story\t3.0\n" } +
        string{ "Amount owed is 19.0\n" } +
        string{ "You earned 7 frequent renter points" };

    EXPECT_EQ(expected, customer.statement());
}
