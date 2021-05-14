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

    // Uses the given vector as the source of words for the model.
    explicit Controller(std::vector<std::string> const& words);

    // Opens the given file and reads one word per line, as the source of
    // words for the model.
    explicit Controller(std::string const& filename);

    // For passing in small word lists by hand.
    Controller(std::initializer_list<std::string> words);

    ///
    /// Member functions
    ///

protected:
    // Called by ge211 when it needs to redraw the screen. Delegates to
    // the view.
    void draw(ge211::Sprite_set& sprites) override;

    // Called by ge211 once right before the game starts. We use this to
    // tell the view to load the bubbles for the first word.
    void on_start() override;

    // Called by ge211 when the game engine is ready. We use this to tell
    // the model to react to time passing.
    void on_frame(double dt) override;

    // Called by ge211 when the user press a key. We forward the keypress
    // to the model.
    void on_key(ge211::Key key) override;

    // Called by ge211 to find out how big to make the window.
    ge211::Dims<int> initial_window_dimensions() const override;

private:

    ///
    /// Private member functions (helpers)
    ///

    // Loads the current word into to the view.
    void load_word_();

    ///
    /// Member variables
    ///

    Model model_;
    View view_;
};
