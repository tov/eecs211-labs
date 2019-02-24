#include "model.h"
#include <algorithm>
#include<iostream>

///
/// Constructors
///
Model::Model( ge211::Dimensions board_dimensions, 
                       int groups,  
					   int types, 
					   ge211::Random& random,
			           std::vector<Tile_Handler_Reference> handlers)
		: board_dimensions_(board_dimensions)
		, groups_(groups)
		, random_(random)
		, handlers_(handlers)
{
	for (int x = 0 ; x < board_dimensions.width ; x ++)
	{
		for (int y=0 ;y< board_dimensions.height; y ++)
		{
			int type = random.between(0,types-1);
			int group = random.between(0,groups-1);
			Tile_Data td = {{y,x},{y-board_dimensions.height,x},group, type};
				map_[td.position.hash()]=td;
		}
	}	
}

///
/// Public member functions
///
std::vector<Tile_Data> Model::get_tiles()
{
	std::vector<Tile_Data> tiles_data;
	for (std::pair<int, Tile_Data> pair : map_ )
	{
		tiles_data.push_back(pair.second);
	}
	return tiles_data;
}

bool Model::run_step()
{
	std::vector<Board_Position> updates;
	for (int x = 0 ; x < board_dimensions_.width ; x ++)
	{
		for (int y=0 ;y< board_dimensions_.height; y ++)
		{
			Board_Position bp{y,x};
			if (map_[bp.hash()].position_prev!=map_[bp.hash()].position)
				updates.push_back(bp);
		}
	}
	for(Board_Position bp:updates)
	{
		map_[bp.hash()].position_prev=map_[bp.hash()].position;
		if (!map_[bp.hash()].marked)
		{
			std::vector<Board_Position> group=get_group_(bp);
			if (group.size()>=3)
				mark_group_(group);
		}
	}
	remove_tiles_();
	return false;
}

bool Model::is_valid_swap(Board_Position p1,Board_Position p2)
{
	return p1 == p2.left() || p1 == p2.right() || p1 == p2.up() || p1 == p2.down();
}

void Model::swap(Board_Position p1, Board_Position p2)
{
	if (!is_valid_swap(p1,p2)) return;
	Tile_Data td1 = map_[p1.hash()];
	Tile_Data td2 = map_[p2.hash()];
	td1.position = p2;
	td2.position = p1;
	map_[p1.hash()] = td2;
	map_[p2.hash()] = td1;	
}

bool Model::is_valid(Board_Position p)
{
	return p.row >= 0 && p.column >= 0 && p.row < board_dimensions_.height && p.column < board_dimensions_.width;
}

///
/// Private member functions
///

void Model::mark_group_(std::vector<Board_Position> list)
{
	for(Board_Position &bp: list)
	{
		map_[bp.hash()].marked=true;
	}
}	

void Model::remove_tiles_()
{
	for (int x = 0 ; x < board_dimensions_.width ; x ++)
		for (int y=0 ;y< board_dimensions_.height; y ++)
		{
			Board_Position bp{y,x};
			if (map_[bp.hash()].marked)
			{
				while (bp.row>0)
				{
					Tile_Data td = map_[bp.up().hash()];
					td.position = bp;
					map_[bp.hash()]=td;
					bp = bp.up();
				}
				int type = random_.between( 0, 0 );
				int group = random_.between( 0, groups_ - 1 );
				Tile_Data td = {bp,{y-board_dimensions_.height,x},group, type};			
				map_[bp.hash()]=td;
			}
		}
}

bool Model::find_connected_(Board_Position bp, std::vector<Board_Position> &connected)
{
	connected.push_back(bp);
	int group = map_[bp.hash()].group;

	Board_Position bpl=bp.left();
	if (is_valid(bpl) && map_[bpl.hash()].group == group && !in_(connected,bpl))
		find_connected_( bpl, connected);
	
	Board_Position bpr=bp.right();
	if (is_valid(bpr) && map_[bpr.hash()].group == group && !in_(connected, bpr))
		find_connected_(bpr, connected);
		
	Board_Position bpu=bp.up();
	if (is_valid(bpu) && map_[bpu.hash()].group == group && !in_(connected, bpu))
		find_connected_(bpu, connected);
		
	Board_Position bpd=bp.down();
	if (is_valid(bpd) && map_[bpd.hash()].group == group && !in_(connected, bpd))
		find_connected_(bpd, connected);
	
	return true;
}

std::vector<Board_Position> Model::get_group_(Board_Position bp)
{
	std::vector<Board_Position> connected;
	find_connected_(bp, connected);
	return connected;
}

bool Model::in_(std::vector<Board_Position> &list,Board_Position position )
{
	for (Board_Position &bp: list)
		if (position == bp) return true;
	return false;
}
