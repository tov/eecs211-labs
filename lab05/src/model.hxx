#pragma once

#include <ge211.hxx>

ge211::Dimensions const scene_dimensions{1024, 768};

const int large_radius = 30;
const int small_radius = 10;

struct Model
{
    // Member functions

    void move_small_circle_to(ge211::Position);
    void move_large_circle_left();
    void move_large_circle_right();
    void move_large_circle_up();
    void move_large_circle_down();

    bool is_touching() const;

    ge211::Position large_upper_left() const;
    ge211::Position small_upper_left() const;

    // Member variables

    ge211::Position large_center_{scene_dimensions.width / 2,
                                  scene_dimensions.height / 2};
    ge211::Position small_center_{scene_dimensions.width / 2,
                                  scene_dimensions.height / 2};
};

