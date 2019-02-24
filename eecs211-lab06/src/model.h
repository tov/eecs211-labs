#pragma once

#include "tiles.h"
#include <ge211.h>

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
				ge211::Random&  random,
			    std::vector<Tile_Handler_Reference> handlers);

    ///
    /// Public member functions
    ///
	std::vector<Tile_Data> get_tiles();
	bool run_step();
	void update ( double ft );
	void swap (Board_Position p1, Board_Position p2);
	bool is_valid(Board_Position p);
	bool is_valid_swap(Board_Position p1,Board_Position p2);

private:

    ///
    /// Private helper functions
    ///
	bool find_connected_(Board_Position bp, std::vector<Board_Position> &connected);
	std::vector<Board_Position> get_group_(Board_Position bp);
	void mark_group_(std::vector<Board_Position> list);
	void remove_tiles_();
	bool in_(std::vector<Board_Position> &list, Board_Position bp);
    ///
    /// Private member variables
    ///
	std::unordered_map<int, Tile_Data> map_;
	ge211::Dimensions board_dimensions_;
	int groups_;
	int types_;
	ge211::Random&  random_;
	std::vector<Tile_Handler_Reference> handlers_;
};
