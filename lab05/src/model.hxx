#pragma once

#include <ge211.hxx>

// To represent the abstract state of the game (the model), we are
// using the types ge211::Dims<int> (for dimensions) and ge211::Posn<int> (for
// positions). These are `struct`s that are provided by GE211, but that could
// be defined like so:
//
//     struct ge211::Dims<int>
//     {
//         int width;
//         int height;
//     };
//
//     struct ge211::Posn<int>
//     {
//         int x;
//         int y;
//     };
//

ge211::Dims<int> const scene_dims {1024, 768};

struct Model
{
    /////
    ///// Member functions
    /////

    // Moves the small circle to the given position.
    void move_small_circle_to(ge211::Posn<int> pos);

    // Moves the large circle some small distance to the left.
    // Buggy. TODO.
    void move_large_circle_left();

    // Moves the large circle some small distance to the right.
    // Buggy. TODO.
    void move_large_circle_right();

    // Moves the large circle some small distance upward. Unimplemented.
    // This one is here for you TODO.
    void move_large_circle_up();

    // Moves the large circle some small distance downward. Unimplemented.
    // This one is here for you TODO.
    void move_large_circle_down();

    // Determines whether the two circles are touching.
    bool overlapped() const;

    // Returns the position of the upper-left corner the large circle's
    // bounding box. (A bounding box is the smallest axis-aligned rectangle
    // you can fit around the sprite.)
    ge211::Posn<int> large_upper_left() const;

    // Returns the position of the upper-left corner the large circle's
    // bounding box.
    ge211::Posn<int> small_upper_left() const;

    /////
    ///// Data members (fields)
    /////

    // The center of the large circle. Starts in the center of the window.
    ge211::Posn<int> large_center {scene_dims.width / 2, scene_dims.height / 2};

    // The center of the small circle. Starts in the upper-left of the window.
    ge211::Posn<int> small_center {0, 0};

    // The radius of the large circle.
    const int large_radius = 250;

    // The radius of the small circle
    const int small_radius = 50;
};

