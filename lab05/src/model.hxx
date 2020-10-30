#pragma once

#include <ge211.hxx>

ge211::Dims<int> const scene_dims{1024, 768};

struct Model
{
    // Member functions

    void move_small_circle_to(ge211::Posn<int>);
    void move_large_circle_left();
    void move_large_circle_right();
    void move_large_circle_up();
    void move_large_circle_down();

    bool is_touching() const;

    ge211::Posn<int> large_upper_left() const;

    ge211::Posn<int> small_upper_left() const;

    // Data members (fields)

    // The center of the large circle.
    ge211::Posn<int> large_center{scene_dims.width / 2, scene_dims.height / 2};

    // The center of the small circle
    ge211::Posn<int> small_center{0, 0};

    // The radius of the large circle.
    const int large_radius = 250;

    // The radius of the small circle
    const int small_radius = 50;
};

