#pragma once

#include <ge211.h>
#include <initializer_list>

static ge211::Duration const letter_delay(.3);

class Model
{
public:

    ///
    /// Constructors
    ///
    
    // Construct Model given a vector of strings that is 
    // used to create the words vector, then the first word is loaded 
    explicit Model(const std::vector<std::string>& words);

    // Construct Model given a initializer_list of strings that is 
    // used to create the words vector, then the first word is loaded 
    Model(std::initializer_list<std::string> words);

    ///
    /// Public member functions
    ///

    // Returns a reference to a string containing 
    // the current word being process by the model
    std::string const& current_word() const;

    // Returns a vector of booleans representing 
    // the state of all letters already processed 
    // where true means hit and false means miss
    std::vector<bool> const& typing_progress() const;

    // Returns a boolean representing the 
    // state of the game where true means 
    // finished ( no more words to play ) and
    // false means in progress
    bool game_is_finished() const;

    // Process a new key pressed and
    // after determine if it is the right one
    // it records the typing progress
   void hit_key(char letter);

	// Determines if the time lapsed since 
    // the last letter was active is bigger than 
    // the wait time and if so mark progress 
    // as a miss
	// Returns a boolean representing the state of the 
	// current word where true means finished and 
	// false means in progress. 
    bool update();

private:

    ///
    /// Private helper functions
    ///

    // Records the typing progress of the current word
	// Receives a boolean parameter to determine 
    // if it was a hit(true) or a miss(false).
	// Returns a boolean representing the state of the 
	// current word where true means finished and 
	// false means in progress. 	
    bool record_progress_(bool success);

    // Set the current_word to the next one in the 
    // words vector
    void load_next_word_();

    // Returns a boolean representing the 
    // state of the current word where true means
    // the word is finished and false the word is 
    // still in progress
    bool word_is_finished_() const;

    ///
    /// Private member variables
    ///

    ge211::Timer last_update_;

    std::string current_word_;
    std::vector<bool> typing_progress_;

    std::vector<std::string> words_;
    size_t next_word_index_ = 0;
};
