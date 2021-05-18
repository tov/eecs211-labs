#pragma once

#include <ge211.hxx>
#include <initializer_list>

// Encapsulates the internal state of the game:
//
//  - the current word,
//  - the progress in the current word, and
//  - the words to do next.

class Model
{
public:

    ///
    /// Associated types
    ///

    // What happened with a particular letter?
    enum class Letter_outcome
    {
        correct,
        incorrect,
        missed,
    };

    // What happened with all the letters?
    using Progress_vector = std::vector<Letter_outcome>;


    ///
    /// Constructors
    ///

    // Uses the given vector of words as the source of words.
    // Allows specifyng the time between letters, which defaults to 2 seconds.
    explicit Model(
            const std::vector<std::string>& words,
            double letter_delay = 2);

    // Uses the given literal word list as the source of words.
    // Allows specifyng the time between letters, which defaults to 2 seconds.
    explicit Model(
            std::initializer_list<std::string> words,
            double letter_delay = 2);


    ///
    /// Public member functions
    ///

    // The current word being process by the model.
    std::string const& current_word() const;

    // Returns the state of all letters already processed in order,
    // where true means hit and false means miss.
    Progress_vector const& typing_progress() const;

    // The amount of time to type each letter.
    double letter_delay() const;

    // The amount of time left to type the current letter.
    double seconds_remaining() const;

    // Returns whether the game is over.
    bool game_is_finished() const;

    // Processes a user key press, updating the word progress.
    void hit_key(char actual);

    // Updates the model for the passage of time and returns whether
    // the current word changed.
    bool on_frame(double dt);

    // Lets us see the word list. (For testing.)
    std::vector<std::string> const& dictionary() const;


private:
    ///
    /// Private helper functions
    ///

    // Records the effect of the most recent keystroke, where true
    // means it was correct and means incorrect or out of time.
    bool record_progress_(Letter_outcome outcome);

    // Set the current_word to the next one in the words vector.
    void load_next_word_();

    // Returns whether the current word is finished.
    bool word_is_finished_() const;


    ///
    /// Private member variables
    ///

    // Seconds between letters.
    double letter_delay_;

    // Seconds remaining for this letter.
    double seconds_remaining_;

    // The current word we're trying to type.
    std::string current_word_;

    // The typing progress: true for correct keystrokes, false for incorrect,
    // grows as we type or time passes.
    Progress_vector typing_progress_;

    // The source of words.
    std::vector<std::string> dictionary_;

    // The index of the next work for after the current word finishes.
    size_t next_word_index_ = 0;
};
