#include "ui.hxx"

static const ge211::Color small_color = ge211::Color::medium_yellow();
static const ge211::Color large_normal_color{0, 100, 0};
static const ge211::Color large_collide_color{200, 0, 0, 150};

// Here we initialize each circle sprite with a radius and a color.
Game::Game()
        : large_sprite_touch{model.large_radius, large_collide_color},
          large_sprite_normal{model.large_radius, large_normal_color},
          small_sprite{model.small_radius, small_color}
{ }

ge211::Dims<int>
Game::initial_window_dimensions() const
{
    return scene_dims;
}

void
Game::draw(ge211::Sprite_set& sprites)
{
    sprites.add_sprite(small_sprite, model.small_upper_left(), -1);

    if (model.overlapped()) {
        sprites.add_sprite(large_sprite_touch,
                           model.large_upper_left());
    } else {
        sprites.add_sprite(large_sprite_normal,
                           model.large_upper_left());
    }
}

void
Game::on_key(ge211::Key key)
{
    if (key == ge211::Key::left()) {
        model.move_large_circle_left();
    } else if (key == ge211::Key::right()) {
        model.move_large_circle_right();
    } else if (key == ge211::Key::code('q')) {
        quit();
    }
}

void
Game::on_mouse_move(ge211::Posn<int> mouse)
{
    model.move_small_circle_to(mouse);
}