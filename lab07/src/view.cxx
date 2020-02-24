#include "view.hxx"
#include <iostream>

///
/// Constructor
///

View::View(Model & model, int groups,
                  std::vector<std::string> type_sprites)
        : model_(model)
{
    for (int i=0;i<groups;i++)
    {
        double hue = 360 / (double) groups * (double) i;
        tiles_sprites_.emplace_back(tile_radius, ge211::Color::from_hsva(hue, 1 , 1 , 1));
    }
    for (std::string type_text: type_sprites)
    {
          type_sprites_.emplace_back(type_text, sans_);
    }
}

///
/// Member functions
///

Board_position View::board_position(ge211::Position position)
{
    return { (int) (position.y - top_margin) / (tile_radius * 2)  , (int) (position.x - left_margin) / (tile_radius * 2) };
}

bool View::update( double ft )
{
    if ( animation_progress_ == 1 )
    {
        tiles_ = model_.get_tiles();
        if (is_changed_(tiles_))
        {
            animation_progress_ = 0;
            return true;
        }
    }
    else
    {
        const int& r = std::min(animation_progress_ + ( ft / animation_time ), 1.00);
        animation_progress_ = std::min(animation_progress_ + ( ft / animation_time ), 1.00);
    }
    return false;
}

void View::draw(ge211::Sprite_set& sprites, Board_position selected_tile_) const
{
    for (Tile_Data tile_data : tiles_)
    {
        ge211::Position position = screen_position_( tile_data, animation_progress_ );
        sprites.add_sprite(tiles_sprites_[tile_data.group], position,1 );
        if (tile_data.position == selected_tile_)
            sprites.add_sprite(selection_sprite_, position,0 );
        ge211::Position type_sprite_position = position;
        type_sprite_position.y += ( tile_radius - type_sprites_[tile_data.type].dimensions().height/2);
        type_sprite_position.x += ( tile_radius - type_sprites_[tile_data.type].dimensions().width/2);
        sprites.add_sprite( type_sprites_[tile_data.type], type_sprite_position ,2 );
    }
}

bool View::is_busy()
{
    return animation_progress_<1;
}

///
/// Private members
///

ge211::Position View::screen_position_(Tile_Data td, double p) const
{
    double x = (double) td.position_prev.column * (1-p) + (double) td.position.column * (p);
    double y = (double) td.position_prev.row * (1-p) + (double) td.position.row * (p);
    return {(int) (x * 2 * tile_radius) + left_margin ,(int) (y * 2 * tile_radius) + top_margin};
}

bool View::is_changed_(std::vector<Tile_Data> tiles_data)
{
    for (Tile_Data td : tiles_data)
        if (td.position != td.position_prev)
            return true;
    return false;
}

