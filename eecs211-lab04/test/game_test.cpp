#include "../src/model.h"
#include <catch.h>

TEST_CASE("move_circle_left")
{
    Model model;
	int x = model.circle_position.x;
	model.move_circle_left();
    CHECK( model.circle_position.x == x - 10 );
}

TEST_CASE("move_circle_right")
{
    Model model;
	int x = model.circle_position.x;
	model.move_circle_right();
    CHECK( model.circle_position.x == x + 10 );
}

TEST_CASE("move_circle_up")
{
    Model model;
    // YOUR TEST CODE HERE
    // YOUR CHECK( ... ); HERE
}

TEST_CASE("move_circle_down")
{
    Model model;
    // YOUR TEST CODE HERE
    // YOUR CHECK( ... ); HERE
}

TEST_CASE("move_cursor_to")
{
    Model model;
	ge211::Position pos{120,150};
	model.move_cursor_to(pos);
    CHECK( model.cursor_position == pos );
}

TEST_CASE("move_get_state")
{
    Model model;
	ge211::Position pos = model.circle_position;
	pos.x += circle_radius - cursor_radius;
	pos.y += circle_radius - cursor_radius;
	model.move_cursor_to(pos);
    CHECK( model.get_state() == Collision_state::touching );
}

TEST_CASE("move_get_not_state")
{
    Model model;
    ge211::Position pos = model.circle_position;
    // YOUR TEST CODE HERE
    CHECK( model.get_state() == Collision_state::not_touching );
}
