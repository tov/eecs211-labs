#include "model.h"

void Model::move_left()
{
    circle_position.x+=10;
}

void Model::move_right()
{
    circle_position.x-=10;
}

float distance ( ge211::Position pos1,  ge211::Position pos2)
{
    return sqrt(pow(pos1.x - pos2.x,2)+pow(pos1.y - pos2.y,2));
}

void Model::update(double const dt)
{
    if (distance(square_position,circle_position) <= circle_radius)
        state = Collision_state::touching;
    else
        state = Collision_state::not_touching;
}

