#include "model.h"
#include <cmath>

void Model::move_large_circle_left()
{
    large_position.x += 10;
}

void Model::move_large_circle_right()
{
    large_position.x -= 10;
}

void Model::move_small_circle_to(ge211::Position pos)
{
    small_position = pos;
}

static double distance(ge211::Position pos1, ge211::Position pos2)
{
    int dx = pos1.x - pos2.x;
    int dy = pos1.y - pos2.y;
    return sqrt(dx * dx + dy * dy);
}

static ge211::Dimensions const small_dims{2 * small_radius, 2 * small_radius};
static ge211::Dimensions const large_dims{2 * large_radius, 2 * large_radius};

Collision_state Model::get_state() const
{
    ge211::Position small_center = small_position + 0.5 * small_dims;
    ge211::Position large_center = large_position + 0.5 * large_dims;

    if (distance(small_center, large_center) <= large_radius + small_radius)
        return Collision_state::touching;
    else
        return Collision_state::not_touching;
}

