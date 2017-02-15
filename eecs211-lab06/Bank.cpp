#include "Bank.h"

using namespace std;

// This constructor creates a bank with 5 different accounts.
Bank::Bank()
{
    Person al("Al", 1, 50.0);
    Person bill("Bill", 2, 200.5);
    Person charlie("Charlie", 3, 11235.8);
    Person david("David", 4, 999.9);
    Person evan("Evan", 5, 1000.0);
    accounts_ = {al, bill, charlie, david, evan};
}

const vector<Person>& Bank::accounts() const
{
    return accounts_;
}

// Implement this function!
// Should iterate through every person in accounts_ and remove all of
// the money in their account. Return the amount of money stolen.
// You'll need change the return value.
double Bank::stealMoney()
{
    // [YOUR CODE HERE]
}
