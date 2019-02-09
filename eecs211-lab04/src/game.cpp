#include <ge211.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace ge211;
using namespace std;

Dimensions const scene_dimensions{1024, 768};
Dimensions const square_dimension{15,15};

int const circle_radius = 30;

Color const color_green{127, 255, 127, 255};
Color const color_red{255, 127, 127, 255};

// MODEL DATA DEFINITIONS
struct Model
{
    Position circle_position{scene_dimensions.width/2, scene_dimensions.height/2};
    Position square_position{scene_dimensions.width/2, scene_dimensions.height/2};
    enum State{red,green} circle_state = red;
    void update(double const dt);
    void move_left ();
    void move_right ();
};

// UI Object

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

void Model::move_left()
{
    circle_position.x+=10;
}
void Model::move_right()
{
    circle_position.x-=10;
}

float distance ( Position pos1,  Position pos2)
{
    return sqrt(pow(pos1.x - pos2.x,2)+pow(pos1.y - pos2.y,2));
}

void Model::update(double const dt)
{
    if ( distance(square_position,circle_position) <= circle_radius)
        circle_state=red;
    else
        circle_state=green;
}

Dimensions Game::initial_window_dimensions() const
{
    return scene_dimensions;
}

void Game::draw(Sprite_set& sprites)
{    
    sprites.add_sprite(square_sprite, model.square_position.into<int>());
    switch (model.circle_state)
    {
        case Model::red:
            sprites.add_sprite(circle_red, model.circle_position.into<int>());
            break;
        case Model::green:
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