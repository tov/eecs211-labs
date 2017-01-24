#include <vector>
#include <exception>
#include "UnitTest++/UnitTest++.h"
#include "lab3.h"
using namespace std;

TEST(HAPPIESTDOG)
{
    Dog roger{"Roger", 5.0, 3.0, "Brendan"};
    Dog angus{"Angus", 12.0, 2.4, "Brendan"};
    Dog marie{"Marie", 0.5, 4.0, "Brendan"};
    Dog samuel{"Samuel", 7.5, 4.5, "Brendan"};
    Dog pierre{"Pierre", 8.5, 3.5, "Matt"};
    Dog robert{"Robert", 15, 2.7, "Matt"};
    Dog forrester{"Forrester", 6.2, 1.5, "Matt"};

    // Vector creation:
    vector<Dog> dogs = {roger, angus, marie, samuel, pierre, robert, forrester};

    CHECK_EQUAL(happiestDog(dogs).name, "Samuel");
}

TEST(YOUNGESTDOG)
{
    // tests here
}

TEST(FINDOWNER)
{
    // tests here

}


