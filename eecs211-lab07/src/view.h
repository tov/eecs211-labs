#pragma once
#include <algorithm>
#include "model.h"

// Controls how the game is shown to the user:
class View
{
public:
    ///
    /// Public member functions
    ///
    explicit View(Model &);
                        
    void draw(ge211::Sprite_set&) const;
    
private:
    ///
    /// Private helper functions
    ///

    // The view can look at the model but doesn't change it.
    Model & model_;

    // Sprites for tiles:
    ge211::Image_sprite asteroid_{"asteroid.png"};
    ge211::Image_sprite space_ship_{"space_ship.gif"};
    ge211::Circle_sprite torpedo_{model_.torpedo_radius, ge211::Color::medium_red()};   
};
