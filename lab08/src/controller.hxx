#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

#include <string>
#include <vector>

// Code for handling user input and managing the overall flow
// of the game. Owns the model and view.
class Controller : public ge211::Abstract_game
{
public:

    ///
    /// Constructors
    ///
    // For passing in small word lists by hand.
    Controller(ge211::Dims<int> board_dimensions);

    ge211::Dims<int> initial_window_dimensions() const override;

    ///
    /// Member functions
    ///
    // Called by ge211 when it needs to redraw the screen. Delegates to
    // the view.
    void draw(ge211::Sprite_set& sprites) override;

    // Called by ge211 when the game engine is ready. We use this to tell
    // the model to react to time passing.
    void on_frame(double dt) override;

    void on_key_up(ge211::Key) override;
    void on_key_down(ge211::Key) override;

    // Called by ge211 when the user press the mouse. We forward the mouse_up
    // to the model.
    void on_mouse_up(ge211::Mouse_button button, ge211::Posn<int> position)
    override;

private:

    ///
    /// Member variables
    ///
    Model model_;
    View view_;
    ge211::Dims<int> screen_dimensions_;
};
