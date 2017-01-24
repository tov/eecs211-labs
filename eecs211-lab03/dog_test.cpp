#include <vector>
#include <exception>
#include <UnitTest++/UnitTest++.h>
#include "Dog.h"
using namespace std;

// Helper for creating a vector of dogs to test on.
vector<Dog> test_dog_vector()
{
    Dog roger{"Roger", 5.0, 3.0, "Brendan"};
    Dog angus{"Angus", 12.0, 2.4, "Brendan"};
    Dog marie{"Marie", 0.5, 4.0, "Brendan"};
    Dog samuel{"Samuel", 7.5, 4.5, "Brendan"};
    Dog pierre{"Pierre", 8.5, 3.5, "Matt"};
    Dog rebecca{"Rebecca", 15, 2.7, "Matt"};
    Dog forrester{"Forrester", 6.2, 1.5, "Matt"};

    // Vector creation:
    vector<Dog> dogs = {roger, angus, marie, samuel, pierre, rebecca, forrester};

    return dogs;
}

TEST(HappiestDog)
{
    vector<Dog> dogs = test_dog_vector();

    CHECK_EQUAL("Samuel", happiestDog(dogs).name);
}

TEST(YoungestDog)
{
    vector<Dog> dogs = test_dog_vector();

    CHECK_EQUAL(0.5, youngestDog(dogs).age);
}

TEST(FindOwner)
{
    vector<Dog> dogs = test_dog_vector();

    CHECK_EQUAL("Brendan", findOwner(dogs, "Marie"));
    CHECK_THROW(findOwner(dogs, "Jesse"), runtime_error);
}


