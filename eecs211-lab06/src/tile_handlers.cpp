#include "tile_handlers.h"
#include <iostream>

std::vector<Board_Position> Normal_Handler::process_removal( Tile_Data td, int group, ge211::Dimensions d ) 
{
	std::vector<Board_Position> v={td.position};
	return v;
}

std::vector<Board_Position> Horizontal_Lazer_Handler::process_removal( Tile_Data td, int group, ge211::Dimensions d ) 
{
	std::vector<Board_Position> v;
	for (int col = 0;col<d.width;col++)
		v.push_back({td.position.row,col});
	return v;
}

