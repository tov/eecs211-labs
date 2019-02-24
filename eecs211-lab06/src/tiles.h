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
		int group, 
		ge211::Dimensions d ) = 0;
 };

class Tile_Handler_Reference {
	public:
	Tile_Handler_Reference(Tile_Handler & _handler)
	: handler(_handler) {};	
	Tile_Handler & handler;
};


