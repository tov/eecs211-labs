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

    // Construct Controller given a reference to a vector of words that is 
    // used to create an instance of the model 
    explicit Controller(std::vector<std::string> const& words);

    // Construct Controller given a reference to a string with the
    // path to a file containing the words to be added to the game
    // The file is loaded into a vector of string and then the Controller  
    // constructor that can receive it as a parameter is called 
    explicit Controller(std::string const& filename);

    ///
    /// Member functions
    ///

    // Controller

    // Called when the game engine is ready 
    // to start the game. It loads the first word    
    void on_start() override;

    // Called when the game engine is ready 
    // to process another frame. It runs the model update
    void on_frame(double dt) override;

    // Called when the user press a key
    // forwards the key to the model using 
    // the model.hit_key function 
    void on_key(ge211::Key key) override;

    // Executes the view draw member to render the 
    // bubbles with the letters of the current word 
    // on the screen
    void draw(ge211::Sprite_set& sprites) override;

private:

    ///
    /// Private member functions (helpers)
    ///

    // Loads the current word to the view. It passes the 
    // screen dimensions and a reference to a ge211::Random object
    // to locate the bubbles on the screen.
    void load_word_();

    ///
    /// Member variables
    ///

    Model model_;
    View view_;
};
