#include <iostream>
#include <vector>
#include <cstdlib>
#include "lab3.h"

using namespace std;



Dog youngestDog(vector<Dog> dogs)
{
    // Write your code here
    return dogs[0];
}

Dog happiestDog(vector<Dog> dogs)
{
    // Write your code here
    return dogs[0];
}

string findOwner(vector<Dog> dogs, string name)
{
    // Write your code here
    return dogs[0].owner;
}

int main()
{
    cout << "Thanks for doing Lab 3!\n";

    // Dog Initialization:
    Dog roger{"Roger", 5.0, 3.0, "Brendan"};
    Dog angus{"Angus", 12.0, 2.4, "Brendan"};
    Dog marie{"Marie", 0.5, 4.0, "Brendan"};
    Dog samuel{"Samuel", 7.5, 4.5, "Brendan"};
    Dog pierre{"Pierre", 8.5, 3.5, "Matt"};
    Dog rebecca{"Rebecca", 15, 2.7, "Matt"};
    Dog forrester{"Forrester", 6.2, 1.5, "Matt"};

    // Vector creation:
    vector<Dog> dogs = {roger, angus, marie, samuel, pierre, rebecca, forrester};

    /*
      An example for-each loop that will print out the name of each Dog in dogs:

        for (Dog d : dogs) {
            cout << d.name << '\n';
        }
     */
}

    

