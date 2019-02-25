#pragma once

#include <ge211.h>
#include <vector>
#include<functional>
#include <unordered_map>

struct  Board_Position 
{
	int row;
	int column;
	bool operator == ( const Board_Position &position){
		return row == position.row && position.column == column;
	}
	bool operator != ( const Board_Position &position){
		return ! (*this==position);
	}
	int hash()
	{
		return row * 100+column;
	}
	Board_Position left() {
		return {row,column-1};
	}
	Board_Position right() {
		return {row,column+1};
	}
	Board_Position up() {
		return {row-1,column};
	}
	Board_Position down() {
		return {row+1,column};
	}
	static Board_Position empty() {
		return {-1,-1};
	}
	bool is_empty()
	{
		return row < 0 || column < 0;
	}
};

struct Tile_Data
{
	Board_Position position;
	Board_Position position_prev;
	int group;
	int type;
	bool marked=false;
};

class Tile_Handler {
 public:
     virtual std::vector<Board_Position> process_removal( 
		Tile_Data td, 
		ge211::Dimensions d ) = 0;
 };

struct Tile
{
	Tile_Data tile_data;
	Tile_Handler &handler;
	Tile operator = ( const Tile &tile){
		tile_data=tile.tile_data;
		handler=tile.handler;
	}
	void swap(Tile &tile)
	{
		Board_Position auxbp=tile.tile_data.position;
		Tile aux=tile;
		tile.tile_data=tile_data;
		tile.handler=handler;
		tile_data=aux.tile_data;
		handler=aux.handler;
		tile_data.position = tile.tile_data.position;
		tile.tile_data.position = auxbp;
	}
};

class Tile_Handler_Reference {
	public:
	Tile_Handler_Reference(Tile_Handler & handler)
	: handler_(handler) {};	
	
	Tile_Handler &get_handler()
	{
		return handler_;
	}
	private:
	Tile_Handler &handler_;
};



