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

void Model::move_square_to(ge211::Position goal)
{
    square_position = goal;
}

Collision_state Model::get_state() const
{
    if (distance(square_position, circle_position) <= circle_radius)
        return Collision_state::touching;
    else
        return Collision_state::not_touching;
}

