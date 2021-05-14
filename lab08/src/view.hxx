#pragma once
#include <algorithm>
#include "model.hxx"

// Controls how the game is shown to the user:
class View
{
public:
    ///
    /// Public member functions
    ///
    explicit View(Model&);

    void draw(ge211::Sprite_set&) const;

private:
    ///
    /// Private helper functions
    ///

    // The view can look at the model but doesn't change it.
    Model& model_;

    // Sprites for tiles:
    ge211::Image_sprite asteroid_ {"asteroid.png"};
    ge211::Image_sprite space_ship_ {"space_ship.gif"};
    ge211::Image_sprite torpedo_ {"torpedo.gif"};

    double asteroid_scale_ = 1.0;
    double space_ship_scale_ = .3;
    double torpedo_scale_ = .03;
};
