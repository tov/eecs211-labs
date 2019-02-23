#include "tiles.h"
#include <iostream>

Board::Board( ge211::Dimensions board_dimensions,
						ge211::Random &random,
						int groups,
						int types )
					: random_ (random)
					, groups_(groups)
					,types_(types)
{
	
	for (int x = 0 ; x < board_dimensions.width ; x ++)
	{
		for (int y=0 ;y< board_dimensions.height; y ++)
		{
			int type = random.between(0,0);
			int group = random.between(0,groups-1);
			tiles_data.push_back({{y,x},{y-board_dimensions.height,x},group, type});
		}
	}
}

std::vector<Tile_Data> &Board::get_tiles()
{
	return tiles_data;
}

bool Board::run_step ()
{
	for (Tile_Data &td : tiles_data)
		td.position_prev=td.position;
}

Tile_Data &Board::find_tile(Board_Position position)
{
	for (Tile_Data &td : tiles_data)
		if (td.position.same(position)) return td;
}

void Board::swap (Board_Position p1, Board_Position p2)
{
	std::cout << "(" << p1.row << "," << p1.column << ")-(" << p2.row << "," << p2. column << ")\t";
	Tile_Data&td1 = find_tile(p1);
	Tile_Data&td2 = find_tile(p2);
	std::cout << "(" << td1.position.row << "," << td1.position.column << ")-(" << td2.position.row << "," << td2.position. column << ")\n";
	td1.position = p2;
	td2.position = p1;
}

bool Board_Position::same(Board_Position position){
		return row == position.row && position.column == column;
}
