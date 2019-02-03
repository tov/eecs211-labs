#include "../src/shared.h"
#include <catch.h>

TEST_CASE("sum_strings({}) == 0")
{
    std::vector<std::string> nothing;
    CHECK( sum_strings(nothing) == 0 );
}

TEST_CASE("sum_strings(...)")
{
    std::vector<std::string> something { "2", "3", "4" };
    CHECK( sum_strings(something) == 9 );
}


