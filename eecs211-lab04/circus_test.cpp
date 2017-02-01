#include "circus.h"

#include <UnitTest++/UnitTest++.h>
#include <stdexcept>

using namespace std;

// Helper for creating a Circus to test on
Circus create_test_circus() {
    Circus test_circus;
    test_circus.name = "Test Circus";
    test_circus.owner = "Test Owner";
    test_circus.animals = {"Elephant", "Lion", "Sea Lion"};
    test_circus.performers = {"Tightrope walker", "Acrobat", "Juggler"};
    test_circus.seating_capacity = 1000;
    test_circus.performance_times = {7, 9, 11};
    Circus sister = {"Test Sister Circus"};
    test_circus.sister_circus = make_shared<Circus>(sister);

    return test_circus;
}

TEST(SWAP_NAMES)
{
    Circus test_circus = create_test_circus();
    swap_names(test_circus);
    CHECK_EQUAL("Test Sister Circus", test_circus.name);
    CHECK_EQUAL("Test Circus", test_circus.sister_circus->name);

    Circus test_circus_no_sister = create_test_circus();
    test_circus_no_sister.sister_circus = nullptr;
    swap_names(test_circus_no_sister);
    CHECK_EQUAL("Test Circus", test_circus_no_sister.name);
}


TEST(REMOVE_SISTER_CIRCUS)
{
    Circus test_circus = create_test_circus();
    remove_sister_circus(test_circus);
    //CHECK_EQUAL(nullptr, test_circus.sister_circus);
    //TODO: Make this test work
}

TEST(REPLACE_SISTER_CIRCUS)
{
    Circus test_circus = create_test_circus();
    replace_sister_circus(test_circus, "New Sister Circus");
    CHECK_EQUAL("New Sister Circus", test_circus.sister_circus->name);

}