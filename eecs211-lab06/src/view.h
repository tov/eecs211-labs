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
    // Constructs a view with reference to a model, which it doesn't
    // modify but need const& access to find out what letters to render.
    explicit View(Model &, int groups);

    // Renders the bubbles with the letters of the current word
    // on the screen.
    void draw(ge211::Sprite_set&, Board_Position select_tile) const;
    
    // Creates the bubble objects for the current word. Takes the
    // window dimensions within which to position the bubbles, and
    // a random number generator for randomizing their positions.
	bool is_busy ();
	
	void update ( double ft );
	
	Board_Position select_tile(ge211::Position position);
	Board_Position board_position(ge211::Position position); 
    
private:

	bool is_changed_(std::vector<Tile_Data> tiles_data);

    // The view can look at the model but doesn't change it.
    Model & model_;
	ge211::Position screen_position_(Tile_Data td, double p) const;
	// The tiles.
    std::vector<Tile_Data> tiles_;
		
	double animation_progress_;

    // Sprites for tiles:
	ge211::Rectangle_sprite selection_sprite_ { {tile_radius*2,tile_radius*2}, {127, 127, 127, 255}};
    std::vector<ge211::Circle_sprite> tiles_sprites_;
    std::vector<ge211::Circle_sprite> selected_tiles_sprites_;
};

