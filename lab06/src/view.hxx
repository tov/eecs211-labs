#pragma once

#include "model.hxx"

static int const font_size = 30;
static int const bubble_radius = 30;
static int const bubble_offset = 70;

// Controls how the game is shown to the user:
class View
{
public:
    // Constructs a view with reference to a model, which it doesn't
    // modify but need const& access to find out what letters to render.
    explicit View(Model const&);

    // Renders the bubbles with the letters of the current word
    // on the screen.
    void draw(ge211::Sprite_set&) const;
    
    // Creates the bubble objects for the current word. Takes the
    // window dimensions within which to position the bubbles.
    void load_word(ge211::geometry::Dims<int> window_dims);

private:

    // The view can look at the model but doesn't change it.
    Model const& model_;

    // A private helper type.
    struct Bubble_
    {
        ///
        /// Constructor
        ///

        Bubble_(ge211::Text_sprite&, ge211::geometry::Posn<int>);

        ///
        /// Member functions
        ///

        // The top-left position for drawing the bubble.
        ge211::geometry::Posn<int> bubble_position() const;
        
        // The top-left position for drawing the letter.
        ge211::geometry::Posn<int> letter_position() const;

        ///
        /// Member variables
        ///

        /// Text sprite containing the letter to display.
        ge211::Text_sprite& letter_sprite;

        // The center position of the bubble.
        ge211::geometry::Posn<int>     center;
    };

    // The bubbles.
    std::vector<Bubble_> bubbles_;

    // The font for the letters.
    ge211::Font sans_{"sans.ttf", font_size};

    // The whole alphabet, a-z, in `Text_sprite`s.
    std::vector<ge211::Text_sprite> letter_sprites_;

    // Sprites for bubbles:
    ge211::Circle_sprite yellow_bubble_{bubble_radius, ge211::Color::medium_yellow()};
    ge211::Circle_sprite green_bubble_{bubble_radius, ge211::Color::medium_green()};
    ge211::Circle_sprite red_bubble_{bubble_radius, ge211::Color::medium_red()};

    // Random sources
    ge211::Random_source<int> random_x_coor_;
    ge211::Random_source<int> random_y_coor_;
};

