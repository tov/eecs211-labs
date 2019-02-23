#include "controller.h"
#include <fstream>
#include <stdexcept>
#include <iostream>

///
/// Helper functions
///


///
/// Constructors
///

Controller::Controller(ge211::Dimensions board_dimensions, 
	                  int groups,
					  int types)
        : model_(board_dimensions, groups, types, get_random())
        , view_(model_,groups)
{ }

///
/// Public member functions
///

void Controller::on_start()
{
}

void Controller::on_frame(double dt)
{
	view_.update(dt);
}

void Controller::on_key(ge211::Key key)
{
}

void Controller::draw(ge211::Sprite_set& sprites)
{
    view_.draw(sprites);
}


void Controller::on_mouse_up(ge211::Mouse_button button, ge211::Position position)
{
	if (!view_.is_busy())
		view_.select_tile(position);
}


///
/// Private member functions
///

