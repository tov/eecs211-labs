#pragma once

#include "model.h"

static int const font_size         = 30;
static int const bubble_radius     = 30;
static int const bubble_offset     = 70;
static int const espinosas_number  = 7;

// Controls how the game is shown to the user:
class View
{
public:
    explicit View(Model const&);

    void draw(ge211::Sprite_set&) const;

    void load_word(ge211::Dimensions window_dims,
                   ge211::Random& rng);

private:

    // The view can look at the model but doesn't change it.
    Model const& model_;

    struct Bubble_
    {
        // Constructor
        Bubble_(ge211::Text_sprite&, ge211::Position);

        /// Member functions
        ge211::Position bubble_position() const;
        ge211::Position letter_position() const;

        /// Member variables
        ge211::Text_sprite& letter_sprite;
        ge211::Position     center;
    };

    std::vector<Bubble_> bubbles_;

    ge211::Font sans_{"sans.ttf", font_size};
    std::vector<ge211::Text_sprite> letter_sprites_;

    ge211::Circle_sprite yellow_bubble_{bubble_radius, ge211::Color::medium_yellow()};
    ge211::Circle_sprite green_bubble_{bubble_radius, ge211::Color::medium_green()};
    ge211::Circle_sprite red_bubble_{bubble_radius, ge211::Color::medium_red()};
};

