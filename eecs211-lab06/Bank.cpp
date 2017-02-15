#include "Bank.h"

using namespace std;

// This constructor creates a bank with 5 different accounts.
Bank::Bank() {
    Person al = Person("Al", 1, 50.0);
    Person bill = Person("Bill", 2, 200.5);
    Person charlie = Person("Charlie", 3, 11235.8);
    Person david = Person("David", 4, 999.9);
    Person evan = Person("Evan", 5, 1000.0);
    accounts_ = {al, bill, charlie, david, evan};
}

vector<Person> Bank::accounts() {
    return accounts_;
}

// Implement this function!
// Should iterate through every person in accounts_ and remove all of the money in their account.
// Return the amount of money stolen.
double Bank::stealMoney() {

    // [YOUR CODE HERE]
    return 0.0;

}