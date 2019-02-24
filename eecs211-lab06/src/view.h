#pragma once
#include <algorithm>
#include "model.h"

static int const tile_radius = 30;
static int const top_margin = 80;
static int const left_margin = 80;
static double const animation_time = .4;

// Controls how the game is shown to the user:
class View
{
public:
    ///
    /// Public member functions
    ///
    explicit View(Model &, int groups);
    void draw(ge211::Sprite_set&, Board_Position select_tile) const;
	bool is_busy ();
	bool update ( double ft );
	Board_Position board_position(ge211::Position position); 
    
private:
    ///
    /// Private helper functions
    ///
	bool is_changed_(std::vector<Tile_Data> tiles_data);
	ge211::Position screen_position_(Tile_Data td, double p) const;

    // The view can look at the model but doesn't change it.
    Model & model_;

	// The tiles.
    std::vector<Tile_Data> tiles_;
	double animation_progress_;

    // Sprites for tiles:
	ge211::Rectangle_sprite selection_sprite_ { {tile_radius*2,tile_radius*2}, {127, 127, 127, 255}};
    std::vector<ge211::Circle_sprite> tiles_sprites_;
	std::vector<ge211::Image_sprite> types_sprites;
};
