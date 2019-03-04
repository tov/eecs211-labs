#pragma once
#include "space_object.h"
#include<memory>
#include<algorithm>
#include<iostream>
#include <ge211.h>

// Encapsulates the internal state of the game:
//
//  - the current word,
//  - the progress in the current word, and
//  - the words to do next.


struct Control
{
    bool left = false;
    bool right = false;
    bool thrust = false;
};

class Model
{
public:

    static int const torpedo_radius = 5;
    static int const asteroid_radius_increase_by_mass_unit = 30;

    ///
    /// Constructors
    ///
    // Uses the dimensions of the board
    Model ( ge211::Dimensions screen_dimensions,
                ge211::Random&  random );

    ///
    /// Public member functions
    ///
    std::vector<std::unique_ptr<Space_object>> get_space_objects();
    void update ( double ft );
    void control_space_ship ( Control control );
    void launch_torpedo ();

private:

    ///
    /// Private helper functions
    ///

    ///
    /// Private member variables
    ///
    std::vector<std::unique_ptr<Space_object>> space_objects_={};;
    ge211::Dimensions screen_dimensions_;
    int asteroid_max_mass_;
    ge211::Random&  random_;
    Space_ship space_ship_;
};
