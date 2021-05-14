#include "controller.hxx"
#include <fstream>
#include <stdexcept>
#include <iostream>

///
/// Constructors
///

Controller::Controller(ge211::Dims<int> screen_dimensions)
        : model_(screen_dimensions),
          view_(model_),
          screen_dimensions_(screen_dimensions)
{
}

///
/// Public member functions
///

ge211::Dims<int>
Controller::initial_window_dimensions() const
{
    return screen_dimensions_;
}

void
Controller::on_key_up(ge211::Key key)
{
    if (key == ge211::Key::left()) {
        model_.turn_left(false);
    }
    if (key == ge211::Key::right()) {
        model_.turn_right(false);
    }
    if (key == ge211::Key::up()) {
        model_.thrust(false);
    }
    if (key.code() == ' ') {
        model_.fire_torpedo();
    }
    if (key.code() == 'q') {
        exit(0);
    }

}

void
Controller::on_key_down(ge211::Key key)
{
    if (key == ge211::Key::left()) {
        model_.turn_left(true);
    }
    if (key == ge211::Key::right()) {
        model_.turn_right(true);
    }
    if (key == ge211::Key::up()) {
        model_.thrust(true);
    }
}

void
Controller::on_frame(double dt)
{
    model_.update(dt);
}

void
Controller::draw(ge211::Sprite_set& sprites)
{
    view_.draw(sprites);
}


void
Controller::on_mouse_up(
        ge211::Mouse_button button, ge211::Posn<int>
position)
{
}

