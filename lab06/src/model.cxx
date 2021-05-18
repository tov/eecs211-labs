#include "model.hxx"

#include <algorithm>
#include <cctype>

///
/// Helper functions
///

// Lowercases a string in-place.
static void
makelower(std::string& s)
{
    for (char& c : s) {
        c = (char) std::tolower((unsigned char) c);
    }
}


///
/// Constructors
///

Model::Model(
        const std::vector<std::string>& words,
        double letter_delay)
        : letter_delay_(letter_delay),
          seconds_remaining_(letter_delay_),
          dictionary_(words)
{
    for (auto& word : dictionary_) {
        makelower(word);
    }

    load_next_word_();
}

Model::Model(
        std::initializer_list<std::string> words,
        double letter_delay)
        : Model(std::vector<std::string>(words), 2)
{ }


///
/// Public member functions
///

std::string const&
Model::current_word() const
{
    return current_word_;
}

Model::Progress_vector const&
Model::typing_progress() const
{
    return typing_progress_;
}

double
Model::letter_delay() const
{
    return letter_delay_;
}

double
Model::seconds_remaining() const
{
    return seconds_remaining_;
}

bool
Model::game_is_finished() const
{
    return current_word_.empty();
}

void
Model::hit_key(char letter)
{
    size_t i = typing_progress_.size();

    if (i < current_word_.size()) {
        record_progress_(std::tolower(letter) == current_word_[i]
                         ? Letter_outcome::correct
                         : Letter_outcome::incorrect);
    }
}

bool
Model::on_frame(double dt)
{
    seconds_remaining_ -= dt;

    if (seconds_remaining_ < 0) {
        return record_progress_(Letter_outcome::missed);
    } else {
        return false;
    }
}

std::vector<std::string> const&
Model::dictionary() const
{
    return dictionary_;
}


///
/// Private member functions
///

bool
Model::record_progress_(Letter_outcome outcome)
{
    seconds_remaining_ = letter_delay_;
    typing_progress_.push_back(outcome);

    if (!word_is_finished_()) {
        return false;
    }

    load_next_word_();

    return true;
}

void
Model::load_next_word_()
{
    typing_progress_.clear();
    current_word_.clear();

    while (next_word_index_ < dictionary_.size() && current_word_.empty()) {
        current_word_ = dictionary_[next_word_index_++];
    }
}

bool
Model::word_is_finished_() const
{
    return typing_progress_.size() == current_word_.size();
}
