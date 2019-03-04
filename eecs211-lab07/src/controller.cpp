#include "controller.h"
#include <fstream>
#include <stdexcept>
#include <iostream>

///
/// Constructors
///

Controller::Controller(ge211::Dimensions screen_dimensions)
        : model_(screen_dimensions, get_random())
        , view_(model_)
{ }

///
/// Public member functions
///

void Controller::on_frame(double dt)
{
}

void Controller::draw(ge211::Sprite_set& sprites)
{
    view_.draw(sprites);
}


void Controller::on_mouse_up(ge211::Mouse_button button, ge211::Position position)
{
}

