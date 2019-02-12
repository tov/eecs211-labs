#include "../src/model.h"
#include <catch.h>

TEST_CASE("move large circle left")
{
    Model model;
    int x = model.large_center_.x;
    model.move_large_circle_left();
    CHECK( model.large_center_.x == x - 10 );
}

TEST_CASE("move large circle right")
{
    Model model;
    int x = model.large_center_.x;
    model.move_large_circle_right();
    CHECK( model.large_center_.x == x + 10 );
}

TEST_CASE("move large circle up")
{
    Model model;
    // YOUR TEST CODE HERE
    // YOUR CHECK( ... ); HERE
}

TEST_CASE("move large circle down")
{
    Model model;
    // YOUR TEST CODE HERE
    // YOUR CHECK( ... ); HERE
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
    CHECK( model.get_state() == Collision_state::touching );
}

TEST_CASE("get collision state not touching")
{
    Model model;
    ge211::Position pos = model.circle_position;
    // YOUR TEST CODE HERE
    CHECK( model.get_state() == Collision_state::not_touching );
}
