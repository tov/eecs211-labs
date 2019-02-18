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
    last_update += dt;
    if (last_update >= letter_delay) {
        if (!is_finished()) word_state[first_pending(word_state)] = State::missed;
        last_update = 0;
    }
}

std::vector<State>& Model::get_word_state()
{
    return word_state;
}

std::string& Model::get_word()
{
    return current_word;
}

void Model::load_word(std::string const& new_word)
{
    word_state.clear();
    for (size_t i = 0; i < new_word.length(); i++)
        word_state.push_back(State::pending);
    current_word = new_word;
}

size_t Model::first_pending(const std::vector<State>& states)
{
    size_t i = 0;
    while (i < states.size() && states[i] != State::pending) i++;
    return i;
}

std::string Model::next_word()
{
    if (word_count == words.size())
        return std::string();
    else
        return words[word_count++];
}

bool Model::is_finished()
{
    return first_pending(word_state) == word_state.size();
}

void Model::hit_key(char letter)
{
    size_t i = first_pending(word_state);
    if (i < word_state.size()) {
        if (current_word.at(i) == letter)
            word_state[i] = State::done;
        else
            word_state[i] = State::missed;
    }
    last_update = 0;
}
