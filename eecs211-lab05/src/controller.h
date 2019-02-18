#pragma once

#include "model.h"
#include "view.h"

#include <ge211.h>

#include <string>
#include <vector>

// Controls how the user interacts with the game and coordinates
// among the other objects.
class Controller : public ge211::Abstract_game
{
public:
    ///
    /// Constructors
    ///

    explicit Controller(std::vector<std::string> const& words);

    explicit Controller(std::string const& filename);

    ///
    /// Member functions
    ///

    // Controller
    void on_start() override;

    void on_frame(double) override;

    void on_key(ge211::Key) override;

    void draw(ge211::Sprite_set&) override;

private:

    ///
    /// Private member functions (helpers)
    ///

    void load_word_();

    ///
    /// Member variables
    ///

    Model model_;
    View view_;
};
