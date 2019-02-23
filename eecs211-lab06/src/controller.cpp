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
	std::cout<<"key\n";
}

void Controller::draw(ge211::Sprite_set& sprites)
{
    view_.draw(sprites , selected_);
}


void Controller::on_mouse_up(ge211::Mouse_button button, ge211::Position position)
{
	if (!view_.is_busy())
	{
		Board_Position bp = view_.board_position(position);
		
		if (model_.is_valid_position(bp))
		{
			if (selected_.is_empty())
				selected_= bp;
			else
			{
				if (bp!=selected_)
					model_.swap(bp,selected_);
				selected_=Board_Position::empty();
			}
				
		}
	}
}


///
/// Private member functions
///

