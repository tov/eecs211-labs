#include "controller.h"
#include <fstream>
#include <stdexcept>
#include <iostream>

///
/// Constructors
///

Controller::Controller(ge211::Dimensions board_dimensions,
                      int groups,
                      int types,
                      std::vector<Tile_Handler_Reference> handlers,
                      std::vector<std::string> type_sprites)
        : model_(board_dimensions, groups, types, get_random(), handlers)
        , view_(model_,groups, type_sprites)
{ }

///
/// Public member functions
///

void Controller::on_frame(double dt)
{
    if (view_.update(dt))
        model_.run_step();
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
        if (model_.is_valid(bp))
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

