#include "model.h"
#include <cmath>

void Model::move_circle_left()
{
    circle_position.x += 10;
}

void Model::move_circle_right()
{
    circle_position.x -= 10;
}

static double distance(ge211::Position pos1, ge211::Position pos2)
{
    int dx = pos1.x - pos2.x;
    int dy = pos1.y - pos2.y;
    return sqrt(dx * dx + dy * dy);
}

void Model::move_cursor_to(ge211::Position goal)
{
    cursor_position = goal;
}

Collision_state Model::get_state() const
{
	ge211::Position cursor_center = cursor_position;
	cursor_center.x += cursor_radius;
	cursor_center.y += cursor_radius;
	ge211::Position circle_center = circle_position;
	circle_center.x += circle_radius;
	circle_center.y += circle_radius;
    if (distance(cursor_center, circle_center) <= circle_radius+cursor_radius)
        return Collision_state::touching;
    else
        return Collision_state::not_touching;
}

