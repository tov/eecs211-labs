#include "model.h"

void Model::move_left()
{
    circle_position.x+=10;
}

void Model::move_right()
{
    circle_position.x-=10;
}

static double distance(ge211::Position pos1, ge211::Position pos2)
{
    int dx = pos1.x - pos2.x;
    int dy = pos1.y - pos2.y;
    return sqrt(dx * dx + dy * dy);
}

void Model::update_mouse(ge211::Position mouse_position)
{
    square_position = mouse_position;

    if (distance(square_position, circle_position) <= circle_radius)
        state = Collision_state::touching;
    else
        state = Collision_state::not_touching;
}
