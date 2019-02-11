#pragma once

#include <ge211.h>

ge211::Dimensions const scene_dimensions{1024, 768};

int const large_radius = 30;
int const small_radius = 10;

enum class Collision_state
{
    touching,
    not_touching,
};

struct Model
{
    // Member functions

    void move_small_circle_to(ge211::Position);
    void move_large_circle_left();
    void move_large_circle_right();

    Collision_state get_state() const;

    ge211::Position large_upper_left() const;
    ge211::Position small_upper_left() const;

    // Member variables

    ge211::Position large_center_{scene_dimensions.width / 2,
                                  scene_dimensions.height / 2};
    ge211::Position small_center_{scene_dimensions.width / 2,
                                  scene_dimensions.height / 2};
};

