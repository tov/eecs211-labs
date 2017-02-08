#include "circus.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main()
{
    cout << "Thanks for doing Lab 4!\n\n";

    Circus crazy_circus;
    crazy_circus.name = "The Wonderfully Wacky & Crazy EECS 211 Circus";
    crazy_circus.owner = "Jesse Tov";
    crazy_circus.animals = {"Elephant", "Lion", "Horse", "Bird", "Sea Lion", "Bear", "Cat", "Dog"};
    crazy_circus.performers = {"Tightrope walker", "Acrobat", "Juggler", "Clown", "Fire breather", "Knife swallower"};
    crazy_circus.seating_capacity = 100000;
    crazy_circus.performance_times = {1, 3, 5, 7, 9, 11};
    Circus monty_python = {"Monty Python's Flying Circus"};
    shared_ptr<Circus> ptr_monty_python = make_shared<Circus>(monty_python);
    crazy_circus.sister_circus = ptr_monty_python;

    // Uncomment each section below to review shared pointers and references.


    cout << "Part 1: Shared Pointers\n";
    // The Circus struct seems pretty large right?
    // We can see how much memory it uses with this print statement.
    cout << "The size of our crazy_circus is: " << sizeof(crazy_circus) << "\n";
    // That's pretty big. Let's try using a shared_pointer.

    shared_ptr<Circus> crazy_ptr = make_shared<Circus>();
    *crazy_ptr = crazy_circus;

    //ed_ptr<Circus> crazy_ptr = make_shared<Circus>(crazy_circus)
    // This sets the value in memory where crazy_ptr points to be the crazy_circus.
    cout << "The size of crazyPtr is: " << sizeof(crazy_ptr) << "\n";
    // That saves us a lot of memory on the stack.

    // Let's check and make sure that our crazy_ptr is pointing to our same crazy_circus as before.
    cout << "crazyPtr points to a circus named: " << crazy_ptr->name << "\n";

    // Shared pointers can also point to nothing at all. We call this value nullptr.
    // Here's how to check for the nullptr value:
    shared_ptr<Circus> example_null_ptr;
    if (example_null_ptr == nullptr){
        cout<<"Since we got here, example_null_ptr is: "<< example_null_ptr << "\n\n";
    }



    cout << "Part 2: References and functions\n";
    // Now let's experiment with some functions. 
    // Check out the passedByCopy() and passedByReference() functions in circus.cpp
    passed_by_copy(crazy_circus);
    cout << "After calling passed_by_copy, \n";
    cout << "The name of crazyCircus is: " << crazy_circus.name << "\n";
    cout << "The owner if crazyCircus is: " << crazy_circus.owner << "\n";

    // Note here that if we pass *crazy_ptr instead, we will have the same results,
    // Because crazy_ptr points to crazy_circus right now

    passed_by_reference(crazy_circus);
    cout << "Now after calling passed_by_reference, \n";
    cout << "The name of crazyCircus is: " << crazy_circus.name << "\n";
    cout << "The owner if crazyCircus is: " << crazy_circus.owner << "\n";
    // Notice that the name and owner of the circus do not change after passed_by_copy() is called.
    // But after passed_by_reference() is called, the name and owner have changed!



}




