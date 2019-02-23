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

struct Board
{
	Board ( ge211::Dimensions board_dimensions,
						ge211::Random &random,
						int groups,
						int types  );
	std::vector<Tile_Data> tiles_data;
	std::unordered_map<int, Tile_Data> map;
	ge211::Random &random_;
	int groups_;
	int types_;
	std::vector<Tile_Data> &get_tiles();
	void swap (Board_Position p1, Board_Position p2);
	bool is_valid (Board_Position position);
	bool run_step();
	ge211::Dimensions  board_dimensions_;
	bool find_connected(Board_Position bp, std::vector<Board_Position> &connected);
	std::vector<Board_Position> get_group(Board_Position bp);
	void mark_group(std::vector<Board_Position> group);
};
