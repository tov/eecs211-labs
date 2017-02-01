#include "circus.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
#include <string>
using namespace std;


void passed_by_copy(Circus c) {
    c.name = "Cirque du Soleil";
    c.owner = "Guy Laliberté";
}

void passed_by_reference(Circus& c) {
    c.name = "Cirque du Soleil";
    c.owner = "Guy Laliberté";
}

//#TODO: Make sure functions can be implemented correctly and pass tests

/// If the Circus c has a sister_circus (i.e. sister_circus isn't nullptr),
/// Swap the name of the Circus c and its sister's name.
void swap_names(Circus& c) {

    // [YOUR CODE HERE]

}

/// Remove Circus c's sister_circus (i.e. make the shared pointer point to nullptr)
void remove_sister_circus(Circus& c) {

    // [YOUR CODE HERE]

}

/// Create a new Circus with the specified name
/// Reassign Circus c's sister_circus shared pointer to point to the new Circus
/// You can add more fields to the circus besides a name --> be creative!
void replace_sister_circus(Circus& c, string name) {

    // [YOUR CODE HERE]

}



