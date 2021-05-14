#pragma once

#include "model.hxx"

// Controls how the game is shown to the user:
class View
{
public:
    // Type for window dimensions.
    using Dims = ge211::Dims<int>;

    // Constructs a view with reference to a model, which it doesn't
    // modify but need const& access to find out what letters to render.
    // Optionally, you can specify the dimensions of the window.
    explicit View(Model const& model,
                  Dims window_dims = {800, 600});

    // Renders the state of the game (bubbles, score, timer) to the screen.
    void draw(ge211::Sprite_set&);

    // Creates the bubble objects for the current word.
    void load_word();

    // Returns the window dimensions.
    Dims window_dimensions() const;

private:
    // Type for positions.
    using Posn = ge211::Posn<int>;

    // A private helper type for keeping track of bubbles.
    // (Defined below.)
    struct Bubble_;

    ///
    /// PRIVATE HELPER FUNCTIONS
    ///

    void
    add_bubble_(ge211::Sprite_set&, Bubble_ const&);

    void
    add_score_(ge211::Sprite_set&);

    void
    add_timer_bar_(ge211::Sprite_set&);

    ge211::Sprite const&
    bubble_sprite_for_(size_t index) const;

    ge211::Sprite const&
    bubble_sprite_for_(Model::Letter_outcome) const;

    ///
    /// PRIVATE MEMBER VARIABLES
    ///

    // The view can look at the model but doesn't change it.
    Model const& model_;

    // The dimensions of the window to open.
    Dims window_dims_;

    // The bubbles.
    std::vector<Bubble_> bubbles_;

    // Sprites for bubbles:
    ge211::Circle_sprite const future_bubble_;
    ge211::Circle_sprite const correct_bubble_;
    ge211::Circle_sprite const incorrect_bubble_;
    ge211::Circle_sprite const missed_bubble_;

    // To display the time remaining.
    ge211::Rectangle_sprite const timer_bar_;

    // The fonts for the letters and the score.
    ge211::Font bubble_font_;
    ge211::Font score_font_;

    // The whole alphabet, A-Z, in `Text_sprite`s.
    std::vector<ge211::Text_sprite> letter_sprites_;

    // For displaying the score.
    ge211::Text_sprite score_sprite_;

    // Random sources -- these are used to position the words proportional
    // the the available space in the window.
    ge211::Random_source<float> random_x_source_{0.0, 1.0};
    ge211::Random_source<float> random_y_source_{0.0, 1.0};
};

struct View::Bubble_
{
    ///
    /// Constructor
    ///

    Bubble_(ge211::Text_sprite&, Posn);

    ///
    /// Member functions
    ///

    // The top-left position for drawing the bubble.
    Posn bubble_position() const;

    // The top-left position for drawing the letter.
    Posn letter_position() const;

    ///
    /// Member variables
    ///

    /// Text sprite containing the letter to display.
    ge211::Text_sprite& letter_sprite;

    // The center position of the bubble.
    Posn center;
};
