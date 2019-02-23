#pragma once

#include "tiles.h"
#include <ge211.h>
#include <initializer_list>

// Encapsulates the internal state of the game:
//
//  - the current word,
//  - the progress in the current word, and
//  - the words to do next.

class Model
{
public:

    ///
    /// Constructors
    ///
    
	// Uses the dimensions of the board
    Model ( ge211::Dimensions board_dimensions, 
	            int groups, 
				int types,
				ge211::Random&  random);

    ///
    /// Public member functions
    ///
	
	std::vector<Tile_Data> const &get_tiles();
	
	bool run_step();
	
	void update ( double ft );
	
	void swap (Board_Position p1, Board_Position p2);
	
	bool is_valid_position(Board_Position p);

private:

    ///
    /// Private helper functions
    ///

    ///
    /// Private member variables
    ///

	ge211::Dimensions board_dimensions_;

	int groups_;

	ge211::Random&  random_;
	
	Board board_;
};
