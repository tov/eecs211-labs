#include "view.h"
#include <iostream>

///
/// Constructor
///

View::View(Model & model, int groups)
        : model_(model)
{
	for (int i=0;i<groups;i++)
	{
		double hue = 360 / (double) groups * (double) i;
		tiles_sprites_.emplace_back(tile_radius, ge211::Color::from_hsva(hue, 1 , 1 , 1));
		selected_tiles_sprites_.emplace_back(tile_radius, ge211::Color::from_hsva(hue, .8 , .8 , .8));
	}
}

///
/// Member functions
///

ge211::Position View::screen_position_(Tile_Data td, double p) const
{
	double x = (double) td.position_prev.column * (1-p) + (double) td.position.column * (p);
	double y = (double) td.position_prev.row * (1-p) + (double) td.position.row * (p);
	return {(int) (x * 2 * tile_radius) + left_margin ,(int) (y * 2 * tile_radius) + top_margin};
}

Board_Position View::board_position(ge211::Position position)
{
	return { (int) (position.y - top_margin) / (tile_radius * 2)  , (int) (position.x - left_margin) / (tile_radius * 2) };
}

bool View::is_changed_(std::vector<Tile_Data> tiles_data)
{
	for (Tile_Data td : tiles_data)
		if (td.position != td.position_prev)
			return true;
	return false;
}

void View::update ( double ft )
{
	if ( animation_progress_ == 1 )
	{
		tiles_ = model_.get_tiles();
		if (is_changed_(tiles_))
		{
			animation_progress_ = 0;
			model_.run_step();
		}
	}
	else
	{
		const int& r = std::min(animation_progress_ + ( ft / animation_time ), 1.00);
		animation_progress_ = std::min(animation_progress_ + ( ft / animation_time ), 1.00);
	}
	
}

void View::draw(ge211::Sprite_set& sprites, Board_Position selected_tile_) const
{
	for (Tile_Data tile_data : tiles_)
	{
		ge211::Position position = screen_position_( tile_data, animation_progress_ );
		sprites.add_sprite(tiles_sprites_[tile_data.group], position,1 );
		if (tile_data.position == selected_tile_)
			sprites.add_sprite(selection_sprite_, position,0 );
	}
}

bool View::is_busy()
{
	return animation_progress_<1;
}

///
/// Private helper class Bubble_
///

