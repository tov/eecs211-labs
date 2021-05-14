#pragma once

#include "model.hxx"

#include <ge211.hxx>

// UI object
struct Game
        : ge211::Abstract_game
{
    ///
    /// Constructor
    ///

    // Initializes a new game.
    Game();

    ///
    /// Member functions
    ///

    // Called by the framework on key events.
    void on_key(ge211::Key) override;

    // Called by the framework when the mouse moves.
    void on_mouse_move(ge211::Posn<int>) override;

    // Called by the framework to find out what to draw on the screen.
    void draw(ge211::Sprite_set&) override;

    // Called by the framework to find out how big to make the window.
    ge211::Dims<int> initial_window_dimensions() const override;

    ///
    /// Data members (fields)
    ///

    // Model - where we store the state of the game.
    Model model;

    // Sprites - prepared images for drawing on the screen.
    ge211::Circle_sprite
            large_sprite_touch,     // the large circle when touching
    large_sprite_normal,    // the large circle when apart
    small_sprite;           // the small circle
};

