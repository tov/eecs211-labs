#include "model.h"

#include <ge211.h>

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace ge211;
using namespace std;

Color const color_green{127, 255, 127, 255};
Color const color_red{255, 127, 127, 255};

// UI Object

Dimensions const square_dimension{15,15};

struct Game : Abstract_game
{
    //View
    Circle_sprite circle_red{circle_radius, color_red};
    Circle_sprite circle_green{circle_radius, color_green};
    
    Rectangle_sprite square_sprite{square_dimension, color_green};
    Model model;

    //Controller
    void on_key(Key key) override;
    void on_mouse_move(Position mouse) override;
    void on_frame(double dt) override;

    Dimensions initial_window_dimensions() const override;
    void draw(Sprite_set& sprites) override;

};

int main()
{
    Game{}.run();
}

Dimensions Game::initial_window_dimensions() const
{
    return scene_dimensions;
}

void Game::draw(Sprite_set& sprites)
{    
    sprites.add_sprite(square_sprite, model.square_position.into<int>());
    switch (model.state)
    {
        case Model::Collision_state::touching:
            sprites.add_sprite(circle_red, model.circle_position.into<int>());
            break;
        case Model::Collision_state::not_touching:
            sprites.add_sprite(circle_green, model.circle_position.into<int>());
            break;
    }
}

void Game::on_key(Key key)
{   if (key==Key::left())
    {
        model.move_left();
    } else if (key==Key::right())
    {
        model.move_right();
    }
}

void Game::on_mouse_move(Position mouse)
{
    model.square_position=mouse;
}

void Game::on_frame(double dt)
{
    model.update(dt);
}