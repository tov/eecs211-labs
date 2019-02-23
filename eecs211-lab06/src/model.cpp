#include "model.h"
#include <algorithm>
#include<iostream>

///
/// Constructors
///

Model::Model(ge211::Dimensions board_dimensions, int groups,  int types, ge211::Random& random)
		: board_dimensions_(board_dimensions)
		, groups_(groups)
		, random_(random)
		, board_(board_dimensions,random, groups, types)
{
}

///
/// Public member functions
///
std::vector<Tile_Data> const &Model::get_tiles()
{
	return board_.get_tiles();
}

bool Model::run_step()
{
	return board_.run_step();
}

void Model::swap (Board_Position p1, Board_Position p2)
{
	board_.swap(p1,p2);
}

bool Model::is_valid_position(Board_Position p)
{
	return p.row>=0 && p.column>=0 && p.row < board_dimensions_.height && p.column < board_dimensions_.width;

}
///
/// Private member functions
///
