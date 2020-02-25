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
    /// Constructor
    ///
    explicit Controller(Model&);

protected:
    ///
    /// Overridden member functions
    ///

    void draw(ge211::Sprite_set&) override;

    void on_frame(double) override;

    void on_mouse_up(ge211::Mouse_button, ge211::Position) override;

    void on_start() override;

    void on_key(ge211::Key key) override;

private:
    ///
    /// Helper functions
    ///

    void start_animating_();

    bool can_animate_();

    ///
    /// Member variables
    ///

    Model& model_;
    View            view_;
    Board::Position selection_{-1, -1};

    bool          animating_       = true;
    ge211::Timer  animation_time_;
    unsigned long animation_steps_ = 0;
};
