#include <iostream>
#include "view.hxx"

///
/// Constructor
///

View::View(Model const& model)
        : model_(model)
        , random_x_coor_(ge211::unbounded)
        , random_y_coor_(ge211::unbounded)
{
    // use .stub_with(...) here on random sources if you want non-random
    // results while developing

    for (char letter = 'a'; letter <= 'z'; ++letter)
        letter_sprites_.emplace_back(std::string(1, letter), sans_);
}

///
/// Member functions
///

void View::draw(ge211::Sprite_set& sprites) const
{
    std::vector<bool> const& progress = model_.typing_progress();

    for (std::size_t i = 0; i < bubbles_.size(); ++i) {
        Bubble_ const& bubble = bubbles_[i];
        sprites.add_sprite(bubble.letter_sprite,
                           bubble.letter_position(),
                           1);
        sprites.add_sprite(i < progress.size()
                           ? progress[i]
                             ? green_bubble_
                             : red_bubble_
                           : yellow_bubble_,
                           bubble.center, 0);
    }
}

void View::load_word(ge211::geometry::Dims<int> window_dims)
{
    std::string const& word = model_.current_word();

    int word_width = static_cast<int>(word.length()) * bubble_offset;

    // pick a random x position, but if the word is too long, just put it at x=0
    int x = 0;
    int max_pos = window_dims.width - word_width;
    if (max_pos > 0) {
        x = random_x_coor_.next_between(0, window_dims.width - word_width);
    }

    int y = random_y_coor_.next_between(0, window_dims.height - bubble_radius * 2);
    ge211::geometry::Posn<int> position{x, y};

    bubbles_.clear();

    for (char c : word) {
        auto i      = static_cast<size_t>(std::tolower(c) - 'a');
        bubbles_.emplace_back(letter_sprites_.at(i), position);
        position.x += bubble_offset;
    }
}

///
/// Private helper class Bubble_
///

View::Bubble_::Bubble_(ge211::Text_sprite& sprite, ge211::geometry::Posn<int> position)
        : letter_sprite(sprite)
        , center(position)
{ }

ge211::geometry::Posn<int> View::Bubble_::bubble_position() const
{
    return center.up_by(bubble_radius).left_by(bubble_radius);
}

ge211::geometry::Posn<int> View::Bubble_::letter_position() const
{
    return center.right_by(bubble_radius - letter_sprite.dimensions().width / 2);
}
