#include "../src/model.h"
#include <catch.h>

TEST_CASE("move_circle_left")
{
    Model model;
	int x = model.large_position.x;
	model.move_large_circle_left();
    CHECK( model.large_position.x == x - 10 );
}

TEST_CASE("move_circle_right")
{
    Model model;
	int x = model.large_position.x;
	model.move_large_circle_right();
    CHECK( model.large_position.x == x + 10 );
}

TEST_CASE("move_cursor_to")
{
    Model model;
	ge211::Position pos{120,150};
	model.move_small_circle_to(pos);
    CHECK( model.small_position == pos );
}

TEST_CASE("move_get_state")
{
    Model model;
	ge211::Position pos = model.large_position;
	pos.x += large_radius - small_radius;
	pos.y += large_radius - small_radius;
	model.move_small_circle_to(pos);
    CHECK( model.get_state() == Collision_state::touching );
}

