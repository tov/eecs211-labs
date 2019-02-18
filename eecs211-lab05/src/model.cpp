#include "model.h"
#include <cmath>

Model::Model()
{
}

Model::Model(const std::vector<std::string>& words)
{
    words_ = words;
}

void Model::update(double dt)
{
    last_update_ += dt;
    if (last_update_ >= letter_delay) {
        if (!is_finished()) word_state_[first_pending_(word_state_)] = State::missed;
        last_update_ = 0;
    }
}

std::vector<State>& Model::get_word_state()
{
    return word_state_;
}

std::string& Model::get_word()
{
    return current_word_;
}

void Model::load_word(std::string const& new_word)
{
    word_state_.clear();
    for (size_t i = 0; i < new_word.length(); i++)
        word_state_.push_back(State::pending);
    current_word_ = new_word;
}

size_t Model::first_pending_(const std::vector<State>& bubbles)
{
    size_t i = 0;
    while (i < bubbles.size() && bubbles[i] != State::pending) i++;
    return i;
}

std::string Model::next_word()
{
    if (word_count_ == words_.size())
        return std::string();
    else
        return words_[word_count_++];
}

bool Model::is_finished()
{
    return first_pending_(word_state_) == word_state_.size();
}

void Model::hit_key(char letter)
{
    size_t i = first_pending_(word_state_);
    if (i < word_state_.size()) {
        if (current_word_.at(i) == letter)
            word_state_[i] = State::done;
        else
            word_state_[i] = State::missed;
    }
    last_update_ = 0;
}
