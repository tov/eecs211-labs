#include "circus.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main()
{
    cout << "Thanks for doing Lab 4!\n";

    Circus crazyCircus;
    crazyCircus.name = "The Wonderfully Wacky & Crazy EECS 211 Circus";
    crazyCircus.owner = "Jesse Tov";
    crazyCircus.animals = {"Elephant", "Lion", "Horse", "Bird", "Sea Lion", "Bear", "Cat", "Dog"};
    crazyCircus.performers = {"Tightrope walker", "Acrobat", "Juggler", "Clown", "Fire breather", "Knife swallower"};
    crazyCircus.seatingCapacity = 100000;
    crazyCircus.performanceTimes = {1, 3, 5, 7, 9, 11};

    cout << "The size of our crazyCircus is: " << sizeof(crazyCircus) << "\n";
    // That's pretty big. Let's try using a shared_pointer.


    shared_ptr<Circus> crazyPtr = make_shared<Circus>();
    *crazyPtr = crazyCircus;
    cout << "The size of crazyPtr is: " << sizeof(crazyPtr) << "\n";
    // That saves us a lot of memory on the stack.

    // Let's check and make sure that our crazyPtr is pointing to our same crazyCircus as before.
    cout << "crazyPtr points to a circus named: " << crazyPtr->name << "\n";



    // Now let's experiment with some functions. Check the passedByCopy() and passedByReference() functions below.
    passedByCopy(crazyCircus);
    cout << "The name of crazyCircus is: " << crazyCircus.name << "\n";
    cout << "The owner if crazyCircus is: " << crazyCircus.owner << "\n";

    passedByReference(*crazyPtr);
    cout << "The name of crazyCircus is: " << crazyPtr->name << "\n";
    cout << "The owner if crazyCircus is: " << crazyPtr->owner << "\n";
    // Notice that the name and owner of the circus do not change after passedByCopy() is called.
    // But after passedByReference() is called, the name and owner have changed!

    // Pointers are pretty cool, huh?

}

void passedByCopy(Circus c) {
    c.name = "Cirque du Soleil";
    c.owner = "Guy Laliberté";
}

void passedByReference(Circus& c) {
    c.name = "Cirque du Soleil";
    c.owner = "Guy Laliberté";
}



