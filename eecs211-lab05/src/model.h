#pragma once

#include <ge211.h>
#include <initializer_list>

int const letter_delay = 2;

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

    void hit_key(char letter);

    void update(double dt);

private:

    ///
    /// Private helper functions
    ///

    void record_progress_(bool success);

    void load_next_word_();

    bool word_is_finished_() const;

    ///
    /// Private member variables
    ///

    double last_update_ = 0;

    std::string current_word_;
    std::vector<bool> typing_progress_;

    std::vector<std::string> words_;
    size_t next_word_index_ = 0;
};

