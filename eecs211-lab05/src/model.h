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

    explicit Model(const std::vector<std::string>& words);

    Model(std::initializer_list<std::string> words);

    ///
    /// Public member functions
    ///

    std::string const& current_word() const;

    std::vector<bool> const& typing_progress() const;

    bool game_is_finished() const;

    bool hit_key(char letter);

    bool update();

private:

    ///
    /// Private helper functions
    ///

    bool record_progress_(bool success);

    void load_next_word_();

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

