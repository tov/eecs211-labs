#include "controller.hxx"

#include <fstream>
#include <stdexcept>


///
/// Helper functions
///

// Reads a vector of strings from a file, one string per line. Throws
// std::runtime_error if there's a problem.
static std::vector<std::string>
load_dictionary(std::string const& filename)
{
    std::ifstream dictionary = ge211::open_resource_file(filename);
    std::vector<std::string> result;
    std::string buffer;

    while (std::getline(dictionary, buffer)) {
        result.push_back(buffer);
    }

    if (dictionary.bad()) {
        throw std::runtime_error("could not read dictionary: " + filename);
    }

    return result;
}


///
/// Constructors
///

Controller::Controller(std::vector<std::string> const& words)
        : model_(words),
          view_(model_)
{ }

Controller::Controller(std::string const& filename)
        : Controller(load_dictionary(filename))
{ }

Controller::Controller(std::initializer_list<std::string> words)
        : Controller(std::vector<std::string>(words))
{ }


///
/// Public member functions
///

void
Controller::on_start()
{
    load_word_();
}

void
Controller::on_frame(double dt)
{
    if (model_.on_frame(dt)) {
        load_word_();
    }
}

void
Controller::on_key(ge211::Key key)
{
    model_.hit_key(char(key.code()));

    if (model_.game_is_finished()) {
        model_ = Model {"gameover"};
    }

    if (model_.typing_progress().empty()) {
        load_word_();
    }
}

void
Controller::draw(ge211::Sprite_set& sprites)
{
    view_.draw(sprites);
}

ge211::Dims<int>
Controller::initial_window_dimensions() const
{
    return view_.window_dimensions();
}

///
/// Private member functions
///

void
Controller::load_word_()
{
    view_.load_word();
}
