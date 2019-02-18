#pragma once

#include <ge211.h>
#include <initializer_list>

int const letter_delay = 2;
ge211::Dimensions const scene_dimensions{1024, 768};

enum class State
{
    pending, missed, done
};

class Model
{
public:

    ///
    /// Constructors
    ///

    Model();

    explicit Model(const std::vector<std::string>&);

    Model(std::initializer_list<std::string>);

    ///
    /// Public member functions
    ///

    void update(double dt);

    std::string next_word();

    void load_word(std::string const& word);

    std::string& get_word();

    void hit_key(char letter);

    bool is_finished();

    std::vector<State>& get_word_state();

private:

    ///
    /// Private member functions
    ///

    size_t first_pending_(std::vector<State> const& bubbles);

    ///
    /// Private member variables
    ///

    std::string current_word_;
    std::vector<State> word_state_;
    std::vector<std::string> words_;
    double last_update_ = 0;
    size_t word_count_ = 0;
};
