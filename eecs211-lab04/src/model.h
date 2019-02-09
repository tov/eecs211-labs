#pragma once

#include <ge211.h>

ge211::Dimensions const scene_dimensions{1024, 768};
int const circle_radius = 30;

enum class Collision_state
{
    touching,
    not_touching,
};

struct Model
{
    // Member functions

    void move_square_to(ge211::Position);
    void move_circle_left();
    void move_circle_right();

    // Member variables

    Collision_state state = Collision_state::touching;
    ge211::Position circle_position{scene_dimensions.width / 2,
                                    scene_dimensions.height / 2};
    ge211::Position square_position{scene_dimensions.width / 2,
                                    scene_dimensions.height / 2};
};

