#include <iostream>
#include "view.hxx"

///
/// Defined constants
///

// An *anonymous namespace* makes its contents private to this file,
// like putting `static` on each definition.
namespace {

using Color = ge211::Color;
using Dims = ge211::Dims<int>;
using Sprite = ge211::Sprite;
using Sprite_set = ge211::Sprite_set;

int const
        bubble_radius = 24,
        bubble_font_size = bubble_radius,
        bubble_spacing = 8,
        bubble_offset = 2 * bubble_radius + bubble_spacing,
        bubble_margin = bubble_radius + bubble_spacing,
        score_font_size = 120,
        timer_thickness = 4;
Dims const
        bubble_box{bubble_offset, bubble_offset},
        score_margin{30, 0};

Color const
        future_bubble_color{0x33, 0x33, 0x33},
        correct_bubble_color{0x00, 0x99, 0x00},
        incorrect_bubble_color{0xFF, 0x00, 0x00},
        missed_bubble_color{0x99, 0x99, 0x00},
        score_color{0x99, 0xCC, 0xFF, 0x99},
        timer_color{0xFF, 0xFF, 0xFF};

}  // end anonymous namespace

///
/// Constructor
///

View::View(Model const& model, Dims window_dims)
        : model_(model),
          window_dims_(window_dims),
          future_bubble_(bubble_radius, future_bubble_color),
          correct_bubble_(bubble_radius, correct_bubble_color),
          incorrect_bubble_(bubble_radius, incorrect_bubble_color),
          missed_bubble_(bubble_radius, missed_bubble_color),
          timer_bar_({1, timer_thickness}, timer_color),
          bubble_font_("sans.ttf", bubble_font_size),
          score_font_("sans.ttf", score_font_size)
{
    // use .stub_with(...) here on random sources if you want non-random
    // results while developing

    for (char c = 'A'; c <= 'Z'; ++c) {
        std::string letter(1, c);
        letter_sprites_.emplace_back(letter, bubble_font_);
    }
}

///
/// Member functions
///


void
View::draw(Sprite_set& sprites)
{
    for (auto const& bubble : bubbles_) {
        add_bubble_(sprites, bubble);
    }

    add_score_(sprites);
    add_timer_bar_(sprites);
}

void
View::add_bubble_(Sprite_set& sprites, View::Bubble_ const& bubble)
{
    sprites.add_sprite(
            bubble_sprite_for_(&bubble - &bubbles_[0]),
            bubble.bubble_position(),
            0);
    sprites.add_sprite(
            bubble.letter_sprite,
            bubble.letter_position(),
            1);
}

void
View::add_score_(Sprite_set& sprites)
{
    ge211::Text_sprite::Builder builder(score_font_);
    builder.color(score_color);
    builder << model_.score();
    score_sprite_ = builder.build();

    Posn posn(window_dims_);
    posn -= score_margin + score_sprite_.dimensions();
    sprites.add_sprite(score_sprite_, posn, 1);
}

void
View::add_timer_bar_(Sprite_set& sprites)
{
    double fraction = model_.seconds_remaining() / Model::letter_delay;
    int width = fraction * window_dims_.width;
    auto posn = Posn(window_dims_).left_by(width).up_by(timer_thickness);
    auto trans = ge211::Transform()
            .set_scale_x(width)
            .set_scale_y(timer_thickness);
    sprites.add_sprite(timer_bar_, posn, 0, trans);
}

void
View::load_word()
{
    bubbles_.clear();

    auto const& word = model_.current_word();
    auto word_box = bubble_box * Dims(word.length(), 1);

    int word_width = bubble_offset * int(word.length());
    int x_span = window_dims_.width - 2 * bubble_margin - word_width;
    int y_span = window_dims_.height - 2 * bubble_margin;
    Posn position(bubble_margin + x_span * random_x_source_(),
                  bubble_margin + y_span * random_y_source_());

    for (char c : word) {
        auto i = size_t(std::tolower(c) - 'a');
        bubbles_.emplace_back(letter_sprites_.at(i), position);
        position.x += bubble_offset;
    }
}

View::Dims
View::window_dimensions() const
{
    return window_dims_;
}

Sprite const&
View::bubble_sprite_for_(size_t i) const
{
    if (i < model_.typing_progress().size()) {
        return bubble_sprite_for_(model_.typing_progress()[i]);
    } else {
        return future_bubble_;
    }
}

Sprite const&
View::bubble_sprite_for_(Model::Letter_outcome outcome) const
{
    using O = Model::Letter_outcome;
    switch (outcome) {
    case O::correct:
        return correct_bubble_;
    case O::incorrect:
        return incorrect_bubble_;
    case O::missed:
        return missed_bubble_;
    }
}


///
/// Private helper class Bubble_
///

View::Bubble_::Bubble_(ge211::Text_sprite& sprite, Posn position)
        : letter_sprite(sprite),
          center(position)
{ }

View::Posn
View::Bubble_::bubble_position() const
{
    return center.up_left_by({bubble_radius, bubble_radius});
}

View::Posn
View::Bubble_::letter_position() const
{
    return center.up_left_by(letter_sprite.dimensions() / 2);
}
