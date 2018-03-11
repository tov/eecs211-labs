#include "Person.h"

using namespace std;

// The constructors below are overloaded!
// When we use the constructor, C++ will automatically choose the correct
// one based on the arguments it's given

// This is a Person constructor
// Note that bank_balance defaults to 0.0
Person::Person(const string& n, int s)
        : Person(n, s, 0.0)

{ }

// This is also a Person constructor... but it takes in different arguments
// Here we take in a double b and assign it to bank_balance_
Person::Person(const string& n, int s, double b)
        : name_(n), ssn_(s), bank_balance_(b)
{ }

// We can also overload functions...
// When we call canIBuyThis, C++ will automatically choose the correct
// method based on the arguments it's given canIBuyThis takes an int as
// an argument here...
bool Person::canIBuyThis(int itemCost) const
{
    cerr << "Calling canIBuyThis with an int... \n";
    return itemCost <= bank_balance_;
}

// ...and a double here.
bool Person::canIBuyThis(double itemCost) const
{
    cerr << "Calling canIBuyThis with a double... \n";
    return itemCost <= bank_balance_;
}

double Person::withdrawFromBank(double amount)
{
    if (amount > bank_balance_)
        throw runtime_error("You don't have that much money!");
    bank_balance_ = bank_balance_ - amount;
    return amount;
}

// Implement these accessor functions!
// You'll need change the return values.

const string& Person::name() const
{
    return name_;
}

int Person::ssn() const
{
    return ssn_;
}

double Person::bank_balance() const
{
    return bank_balance_;
}

