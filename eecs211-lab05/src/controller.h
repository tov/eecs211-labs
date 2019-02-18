#pragma once

#include "model.h"
#include "view.h"

#include <ge211.h>

#include <string>
#include <vector>

// UI object
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

    void on_frame(double dt) override;

    void on_key(ge211::Key key) override;

    void draw(ge211::Sprite_set& sprites) override;

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
