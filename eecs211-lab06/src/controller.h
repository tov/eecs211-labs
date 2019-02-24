#pragma once

#include "model.h"
#include "view.h"

#include <ge211.h>

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
    Controller ( ge211::Dimensions board_dimensions, 
	                  int groups,
					  int types,
					  std::vector<Tile_Handler_Reference> handlers,
					  std::vector<std::string> type_sprites);

    ///
    /// Member functions
    ///

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
	
    void on_mouse_up(ge211::Mouse_button button, ge211::Position position) override;


private:

    ///
    /// Private member functions (helpers)
    ///

    // Loads the current word into to the view.
	
    ///
    /// Member variables
    ///
	Board_Position selected_= Board_Position::empty();

    Model model_;
    View view_;
};
