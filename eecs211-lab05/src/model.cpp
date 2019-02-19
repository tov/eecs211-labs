#include "model.h"
#include <algorithm>

///
/// Constructors
///

Model::Model(const std::vector<std::string>& words)
        : words_(words)
{
    load_next_word_();
}

Model::Model(std::initializer_list<std::string> words)
        : words_(words)
{
    load_next_word_();
}

///
/// Public member functions
///

std::string const& Model::current_word() const
{
    return current_word_;
}

std::vector<bool> const& Model::typing_progress() const
{
    return typing_progress_;
}

bool Model::game_is_finished() const
{
    return current_word_.empty();
}

void Model::hit_key(char letter)
{
    size_t i = typing_progress_.size();

    if (i < current_word_.size())
        record_progress_(current_word_[i] == letter);
}

bool Model::update()
{
    if (last_update_.elapsed_time() > letter_delay)
        return record_progress_(false);
    else
        return false;
}

///
/// Private member functions
///

bool Model::record_progress_(bool success)
{
    last_update_.reset();

    typing_progress_.push_back(success);

    if (word_is_finished_()) {
        load_next_word_();
        return true;
    } else
        return false;
}

void Model::load_next_word_()
{
    typing_progress_.clear();

    if (next_word_index_ < words_.size())
        current_word_ = words_[next_word_index_++];
    else
        current_word_ = "";
}

bool Model::word_is_finished_() const
{
    return typing_progress_.size() == current_word_.size();
}
