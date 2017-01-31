#include "Dog.h"

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

Dog& youngestDog(vector<Dog>& dogs)
{
    // Write your code here
    Dog youngest = dogs[0];
    for(Dog d : dogs){
        if(d.age < youngest.age){
            youngest = d;
        }
    }
    return youngest;
}

Dog& happiestDog(vector<Dog>& dogs)
{
    // Write your code here
    return dogs[0];
}

string findOwner(const vector<Dog>& dogs, const string& name)
{
    // Write your code here
    return dogs[0].owner;
}



