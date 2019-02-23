#include "tiles.h"
#include <iostream>

Board::Board( ge211::Dimensions board_dimensions,
						ge211::Random &random,
						int groups,
						int types )
 	: random_ (random)
	, groups_(groups)
	,types_(types)
	,board_dimensions_(board_dimensions)
{
	
	for (int x = 0 ; x < board_dimensions.width ; x ++)
	{
		for (int y=0 ;y< board_dimensions.height; y ++)
		{
			int type = random.between(0,0);
			int group = random.between(0,groups-1);
			Tile_Data td = {{y,x},{y-board_dimensions.height,x},group, type};
			tiles_data.push_back(td);
			map[td.position.hash()]=td;
		}
	}
}

bool Board::is_valid(Board_Position p)
{
	return p.row>=0 && p.column>=0 && p.row < board_dimensions_.height && p.column < board_dimensions_.width;
}

std::vector<Tile_Data> &Board::get_tiles()
{
	tiles_data.clear();
	for (std::pair<int, Tile_Data> pair : map )
	{
		tiles_data.push_back(pair.second);
	}
	return tiles_data;
}

bool in (std::vector<Board_Position> &list,Board_Position position )
{
	for (Board_Position &bp: list)
	{
		if (position == bp) return true;
	}
	return false;
}

bool Board::find_connected(Board_Position bp, std::vector<Board_Position> &connected)
{
	connected.push_back(bp);
	std::cout << "connected :" << bp.hash() << "," << connected.size() << "\n";

	int group = map[bp.hash()].group;

	Board_Position bpl=bp.left();
	if (is_valid(bpl) && map[bpl.hash()].group == group && !in(connected,bpl))
	{
		find_connected( bpl, connected);
	}
	
	Board_Position bpr=bp.right();
	if (is_valid(bpr) && map[bpr.hash()].group == group && !in(connected, bpr))
	{
		find_connected(bpr, connected);
	}
		
	Board_Position bpu=bp.up();
	if (is_valid(bpu) && map[bpu.hash()].group == group && !in(connected, bpu))
	{
		find_connected(bpu, connected);
	}
		
	Board_Position bpd=bpd.down();
	if (is_valid(bpd) && map[bpd.hash()].group == group && !in(connected, bpd))
	{
		find_connected(bpd, connected);
	}
	
	return true;
}

std::vector<Board_Position> Board::get_group(Board_Position bp)
{
	std::vector<Board_Position> connected;
	find_connected(bp, connected);
	return connected;
}

void Board::mark_group(std::vector<Board_Position> list)
{
	for(Board_Position &bp: list)
	{
		map[bp.hash()].marked=true;
	}
}	

void Board::remove_tiles()
{
	for (int x = 0 ; x < board_dimensions_.width ; x ++)
	{
		for (int y=0 ;y< board_dimensions_.height; y ++)
		{
			Board_Position bp{y,x};
			if (map[bp.hash()].marked)
			{
				while (bp.row>0)
				{
					Tile_Data td = map[bp.up().hash()];
					td.position = bp;
					map[bp.hash()]=td;
					bp = bp.up();
				}
				int type = random_.between(0,0);
				int group = random_.between(0,groups_-1);
				Tile_Data td = {bp,{y-board_dimensions_.height,x},group, type};			
				map[bp.hash()]=td;
			}
		}
	}
}

bool Board::run_step ()
{
	std::cout << "here\n";
	std::vector<Board_Position> updates;
	for (int x = 0 ; x < board_dimensions_.width ; x ++)
	{
		for (int y=0 ;y< board_dimensions_.height; y ++)
		{
			Board_Position bp{y,x};
			if (map[bp.hash()].position_prev!=map[bp.hash()].position)
				updates.push_back(bp);
		}
	}
	for(Board_Position bp:updates)
	{
		map[bp.hash()].position_prev=map[bp.hash()].position;
		if (!map[bp.hash()].marked)
		{
			std::vector<Board_Position> group=get_group(bp);
			if (group.size()>=3)
				mark_group(group);
		}
	}
	remove_tiles();
	std::cout << "done\n";
}

void Board::swap (Board_Position p1, Board_Position p2)
{
	Tile_Data td1 = map[p1.hash()];
	Tile_Data td2 = map[p2.hash()];
	td1.position = p2;
	td2.position = p1;
	map[p1.hash()] = td2;
	map[p2.hash()] = td1;
}

