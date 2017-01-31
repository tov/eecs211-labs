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
    shared_ptr<Circus> ptr_sister = make_shared<Circus>(sister);
    test_circus.sister_circus = ptr_sister;

    return test_circus;
}

TEST(SWAP_SISTER_NAMES)
{
    Circus test_circus = create_test_circus();
    swap_sister_names(test_circus);
    CHECK_EQUAL("Test Sister Circus", test_circus.name);
    CHECK_EQUAL("Test Circus", test_circus.sister_circus->name);

    Circus test_circus_no_sister = create_test_circus();
    test_circus_no_sister.sister_circus = nullptr;
    CHECK_EQUAL("Test Circus", test_circus.name);
}


TEST(REMOVE_SISTER_CIRCUS)
{
    Circus test_circus = create_test_circus();
    remove_sister_circus(test_circus);
    CHECK_ASSERT(test_circus.sister_circus == nullptr);
}

TEST(REPLACE_SISTER_CIRCUS)
{
    Circus test_circus = create_test_circus();
    CHECK_EQUAL("New Sister Circus", replace_sister_circus(test_circus, "New Sister Circus").name);
    CHECK_EQUAL("New Sister Circus", test_circus.sister_circus->name);

}