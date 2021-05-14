#include "model.hxx"
#include <catch.hxx>

using namespace ge211;

TEST_CASE("move large circle left")
{
    Model model;
    Posn<int> old = model.large_center;

    model.move_large_circle_left();

    CHECK(model.large_center.x == old.x - 10);
    CHECK(model.large_center.y == old.y);
}

TEST_CASE("move large circle right")
{
    Model model;
    Posn<int> old = model.large_center;

    model.move_large_circle_right();

    CHECK(model.large_center.x == old.x + 10);
    CHECK(model.large_center.y == old.y);
}

TEST_CASE("move large circle up")
{
    Model model;

    //
    // YOUR TESTS HERE
    //
}

TEST_CASE("move large circle down")
{
    Model model;

    //
    // YOUR TESTS HERE
    //
}

TEST_CASE("move small circle to")
{
    Model model;
    Posn<int> pos {120, 150};
    model.move_small_circle_to(pos);
    CHECK(model.small_center == pos);
}

TEST_CASE("get collision state touching")
{
    Model model;

    Posn<int> pos = model.large_center;
    pos.x += model.large_radius - model.small_radius;
    pos.y += model.large_radius - model.small_radius;
    model.move_small_circle_to(pos);

    CHECK(model.overlapped());
}

TEST_CASE("get collision state not touching")
{
    Model model;

    //
    // YOUR SETUP HERE
    //

    CHECK_FALSE(model.overlapped());
}
