#include "model.hxx"
#include <catch.hxx>

TEST_CASE("move large circle left")
{
    Model model;
    int old_x = model.large_center_.x;
    model.move_large_circle_left();
    CHECK( model.large_center_.x == old_x - 10 );
}

TEST_CASE("move large circle right")
{
    Model model;
    int old_x = model.large_center_.x;
    model.move_large_circle_right();
    CHECK( model.large_center_.x == old_x + 10 );
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
    ge211::Position pos{120, 150};
    model.move_small_circle_to(pos);
    CHECK( model.small_center_ == pos );
}

TEST_CASE("get collision state touching")
{
    Model model;

    ge211::Position pos = model.large_center_;
    pos.x += large_radius - small_radius;
    pos.y += large_radius - small_radius;
    model.move_small_circle_to(pos);

    CHECK( model.is_touching() );
}

TEST_CASE("get collision state not touching")
{
    Model model;

    //
    // YOUR SETUP HERE
    //

    CHECK_FALSE( model.is_touching() );
}
