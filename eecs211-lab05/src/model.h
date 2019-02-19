#pragma once

#include <ge211.h>
#include <initializer_list>

static ge211::Duration const letter_delay(2);

// Encapsulates the internal state of the game:
//
//  - the current word,
//  - the progress in the current word, and
//  - the words to do next.

class Model
{
public:

    ///
    /// Constructors
    ///
    
    // Uses the given vector of words as the source of words.
    explicit Model(const std::vector<std::string>& words);

    // Uses the given literal word list as the source of words.
    Model(std::initializer_list<std::string> words);

    ///
    /// Public member functions
    ///

    // The current word being process by the model.
    std::string const& current_word() const;

    // Returns the state of all letters already processed in order,
    // where true means hit and false means miss.
    std::vector<bool> const& typing_progress() const;

    // Returns whether the game is over.
    bool game_is_finished() const;

    // Processes a user key press, updating the word progress.
    void hit_key(char letter);

    // Updates the model for the passage of time and returns whether
    // the current word changed.
    bool update();

private:

    ///
    /// Private helper functions
    ///

    // Records the effect of the most recent keystroke, where true
    // means it was correct and means incorrect or out of time.
    bool record_progress_(bool success);

    // Set the current_word to the next one in the words vector.
    void load_next_word_();

    // Returns whether the current word is finished.
    bool word_is_finished_() const;

    ///
    /// Private member variables
    ///

    // Keeps track of time since the last letter was typed or timed out.
    ge211::Timer last_update_;

    // The current word we're trying to type.
    std::string current_word_;

    // The typing progress: true for correct keystrokes, false for incorrect,
    // grows as we type or time passes.
    std::vector<bool> typing_progress_;

    // The source of words.
    std::vector<std::string> words_;

    // The index of the next work for after the current word finishes.
    size_t next_word_index_ = 0;
};
