#include "model.h"

#include <ge211.h>

ge211::Color const color_yellow = ge211::Color::medium_yellow();
ge211::Color const color_green = ge211::Color::medium_green();
ge211::Color const color_red   = ge211::Color::medium_red();

// UI object
struct Game : ge211::Abstract_game
{
    ///
    /// Member functions
    ///

    // Controller
    void on_key(ge211::Key key) override;
    void on_mouse_move(ge211::Position mouse) override;

    // View
    void draw(ge211::Sprite_set& sprites) override;
    ge211::Dimensions initial_window_dimensions() const override;

    ///
    /// Member variables
    ///

    // Model
    Model model;

    // View
    ge211::Circle_sprite circle_red{circle_radius, color_red};
    ge211::Circle_sprite circle_green{circle_radius, color_green};
    ge211::Circle_sprite cursor{cursor_radius, color_yellow};
};

int main()
{
    Game{}.run();
}

ge211::Dimensions Game::initial_window_dimensions() const
{
    return scene_dimensions;
}

void Game::draw(ge211::Sprite_set& sprites)
{    
    sprites.add_sprite(cursor, model.cursor_position);

    switch (model.get_state()) {
        case Collision_state::touching:
            sprites.add_sprite(circle_red, model.circle_position);
            break;

        case Collision_state::not_touching:
            sprites.add_sprite(circle_green, model.circle_position);
            break;
    }
}

void Game::on_key(ge211::Key key)
{
    if (key == ge211::Key::left()) {
        model.move_circle_left();
    } else if (key == ge211::Key::right()) {
        model.move_circle_right();
    }
}

void Game::on_mouse_move(ge211::Position mouse)
{
    model.move_cursor_to(mouse);
}
