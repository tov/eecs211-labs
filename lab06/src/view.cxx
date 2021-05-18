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
using Transform = ge211::Transform;

// Radius of each bubble:
int const bubble_radius = 40;
// Spacing between adjacent bubbles:
int const bubble_padding = 10;
// Offset between adjacent bubbles:
int const bubble_offset = 2 * bubble_radius + bubble_padding;

// Effective space taken up by a bubble, including padding around it:
Dims const bubble_box {bubble_offset, bubble_offset};

// Thickness of "cursor" ring around current bubble:
int const cursor_thickness = 4;
// Thickness of timer bar at bottom of window:
int const timer_thickness = 4;

// Size of font:
int const letter_font_size = bubble_radius;

// Bubble colors;
Color const
        future_bubble_color {0x33, 0x33, 0x33},
        current_bubble_color {0x66, 0x66, 0xCC},
        correct_bubble_color {0x00, 0x66, 0x00},
        incorrect_bubble_color {0x66, 0x00, 0x00},
        missed_bubble_color {0x99, 0x44, 0x00};

// Other colors;
Color const
        cursor_color {0xFF, 0xFF, 0xFF},
        timer_color {0xFF, 0xFF, 0xFF};

}  // end anonymous namespace


///
/// Constructor
///

View::View(Model const& model, Dims window_dims)
        : model_(model),
          window_dims_(window_dims),
          future_bubble_(bubble_radius, future_bubble_color),
          current_bubble_(bubble_radius, current_bubble_color),
          correct_bubble_(bubble_radius, correct_bubble_color),
          incorrect_bubble_(bubble_radius, incorrect_bubble_color),
          missed_bubble_(bubble_radius, missed_bubble_color),
          cursor_disc_(bubble_radius + cursor_thickness, cursor_color),
          timer_bar_({1, timer_thickness}, timer_color),
          bubble_font_("sans.ttf", letter_font_size)
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
        bubble.draw(sprites, *this);
    }

    draw_timer_(sprites);
}

void
View::draw_timer_(Sprite_set& sprites)
{
    double fraction = model_.seconds_remaining() / model_.letter_delay();
    int width = fraction * window_dims_.width;
    auto posn = Posn(window_dims_).left_by(width).up_by(timer_thickness);
    auto trans = Transform()
            .set_scale_x(width)
            .set_scale_y(timer_thickness);
    sprites.add_sprite(timer_bar_, posn, -1, trans);
}

void
View::load_word()
{
    bubbles_.clear();

    std::string const& word = model_.current_word();

    // Calculate how much space the word will take up:
    Dims word_box = bubble_box * Dims(word.size(), 1);

    // Will it fit in the window? If not then we need to scale it down:
    double scale = 1.0;
    if (!(word_box <= window_dims_)) {
        scale = std::min(window_dims_.width / double(word_box.width),
                         window_dims_.height / double(word_box.height));
        word_box *= scale;
    }

    // Choose a random position in the unit square, and then scale it to the
    // amount of space that's available:
    ge211::Dims<double> unit_dims {random_x_source_(), random_y_source_()};
    ge211::Posn<double> rel_posn {unit_dims * (window_dims_ - word_box)};

    // Now the position of the (center of) the first bubble is given by the
    // the relative position plus half the size of a bubble (to find the
    // center):
    auto position = rel_posn.into<int>() + 0.5 * scale * bubble_box;

    for (std::size_t i = 0; i < word.size(); ++i) {
        auto letter_index = std::tolower(word[i]) - 'a';
        auto const& letter = letter_sprites_.at(letter_index);
        bubbles_.emplace_back(i, letter, position, scale);
        position.x += scale * bubble_offset;
    }
}

Sprite const&
View::bubble_sprite_for_(size_t i) const
{
    auto const& progress = model_.typing_progress();

    if (i < progress.size()) {
        return bubble_sprite_for_(progress[i]);
    } else if (i == progress.size()) {
        return current_bubble_;
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

View::Bubble_::Bubble_(
        std::size_t word_index,
        Sprite const& letter,
        Posn center,
        double scale)
        : word_index(word_index),
          letter_sprite(letter),
          center(center),
          scale(scale)
{ }

void
View::Bubble_::draw(Sprite_set& sprites, View const& view) const
{
    auto shrink = Transform::scale(scale);
    auto& bubble_sprite = view.bubble_sprite_for_(word_index);

    auto bubble_posn = center - 0.5 * scale * bubble_sprite.dimensions();
    auto letter_posn = center - 0.5 * scale * letter_sprite.dimensions();

    sprites.add_sprite(bubble_sprite, bubble_posn, 1, shrink);
    sprites.add_sprite(letter_sprite, letter_posn, 2, shrink);

    // Put a "cursor" (ring) around the current letter:
    if (word_index == view.model_.typing_progress().size()) {
        auto have_thick = cursor_thickness;
        auto want_thick = std::max(1.0, scale * have_thick);
        auto cursor_posn = bubble_posn - Dims(want_thick, want_thick);

        auto have_radius = have_thick + bubble_radius;
        auto want_radius = want_thick + scale * bubble_radius;
        auto cursor_shrink = Transform::scale(want_radius / have_radius);

        sprites.add_sprite(view.cursor_disc_, cursor_posn, 0, cursor_shrink);
    }
}
