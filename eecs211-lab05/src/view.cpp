#include "view.h"

View::View(Model const& model)
        : model_(model)
{
    for (char letter = 'a'; letter <= 'z'; ++letter)
        letter_sprites_.emplace_back(std::string(1, letter), sans_);
}

View::Bubble_::Bubble_(ge211::Text_sprite& sprite, ge211::Position position)
        : letter_sprite(sprite)
        , center(position)
{ }

ge211::Position View::Bubble_::bubble_position() const
{
    return center.up_by(bubble_radius).left_by(bubble_radius);
}

ge211::Position View::Bubble_::letter_position() const
{
    return center.right_by(bubble_radius - espinosas_number);
}

void View::draw(ge211::Sprite_set& sprites) const
{
    std::vector<bool> const& progress = model_.typing_progress();

    for (int i = 0; i < bubbles_.size(); ++i) {
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

void View::load_word(ge211::Dimensions window_dims,
                     ge211::Random& rng)
{
    std::string const& word = model_.current_word();

    int word_width = static_cast<int>(word.length()) * bubble_offset;

    int x = rng.between(0, window_dims.width - word_width);
    int y = rng.between(0, window_dims.height - bubble_radius * 2);
    ge211::Position position{x, y};

    bubbles_.clear();

    for (char c : word) {
        position.x += bubble_offset;
        auto i      = static_cast<size_t>(std::tolower(c) - 'a');
        bubbles_.emplace_back(letter_sprites_.at(i), position);
    }
}

