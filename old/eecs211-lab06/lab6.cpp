#include "Person.h"
#include "Bank.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

void buySoda(Person& p, double sodaPrice);
void printPerson(const Person& p);

int main()
{
    cout << "Thanks for doing Lab 6!\n\n";

    Person myPerson = Person("Jesse", 1234567, 100.0);

    // This also works...
    //   Person myPerson {"Jesse", 1234567, 100.0};
    //
    // Also these work:
    //   Person myPerson = {"Jesse", 1234567, 100.0};
    //   Person myPerson = Person{"Jesse", 1234567, 100.0};
    //   Person myPerson("Jesse", 1234567, 100.0);
    //
    // THIS DOESN'T WORK:
    //   Person myPerson = ("Jesse", 1234567, 100.0);
    //
    // Weird, right?

    // The code below won't work! ssn_ and bank_balance_ are private data
    // members! This means they can't be accessed from outside the class.
    // Uncomment the code and try to run it if you need to be convinced.
    /*
    cout << myPerson.name_ << '\n';
    cout << myPerson.ssn_ << '\n';
    */

    // However, we CAN access the Person's public data members and functions.
    // Ex. canIBuyThis and withdrawFromBank
    // buySoda is defined below and uses both of these functions.
    cout << "### Practice with classes ###\n";
    buySoda(myPerson, 2.5);
    printPerson(myPerson);

    cout << "\n### More practice with classes ###\n";
    Bank myBank = Bank();
    double moneyStolen = myBank.stealMoney();
    cout << "myBank stole " << moneyStolen << " dollars today.\n";
    // Should be "myBank stole 13486.2 dollars today." if function
    // is implemented correctly.
}

void buySoda(Person& p, double sodaPrice)
{
    if (p.canIBuyThis(sodaPrice)) {
        p.withdrawFromBank(sodaPrice);
    } else {
        cerr << "You don't have enough money!\n";
    }
}

// Implement this function!
// First, you'll need to implement the getter functions in Person.cpp.
// Then you'll use them in this function to get the Person's data members...
// ...and print the information about the person in the format:
//
// "This Person is named (name_), has Social Security Number (ssn_),
// and has (bank_balance_) dollars in their bank account."
void printPerson(const Person& p)
{

    
    // [YOUR CODE HERE]


}


