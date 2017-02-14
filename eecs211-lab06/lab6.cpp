#include "Person.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

void buySoda(Person& p, double sodaPrice);
void printPerson(Person& p);

int main()
{
    cout << "Thanks for doing Lab 6!\n\n";

    Person myPerson = Person("Jesse", 1234567, 100.0);

    // The code below won't work! SSN and bank_balance are private data members!
    // This means they can't be accessed from outside the class.
    // Uncomment the code and try to run it if you need to be convinced.
    /*
    cout << myPerson.name_ << '\n';
    cout << myPerson.SSN_ << '\n';
    */

    // However, we CAN access the Person's public data members and functions.
    // Ex. canIBuyThis and withdrawFromBank
    // buySoda is defined below and uses both of these functions.
    buySoda(myPerson, 2.5);

    printPerson(myPerson);
}

void buySoda(Person& p, double sodaPrice) {
    if (p.canIBuyThis(sodaPrice)) {
        p.withdrawFromBank(sodaPrice);
    }
    else {
        cout << "You don't have enough money!\n";
    }
}

// Implement this function!
// First, you'll need to implement the getter functions in Person.cpp.
// Then you'll use them in this function to get the Person's data members...
// ...and print the information about the person.
void printPerson(Person& p) {

    // [YOUR CODE HERE]

}


