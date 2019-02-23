#include <ge211.h>
#include <vector>
#include<functional>

struct  Board_Position 
{
	int row;
	int column;
	bool same(Board_Position second_position);
};

struct Tile_Data
{
	Board_Position position;
	Board_Position position_prev;
	int group;
	int type;
};

struct Board
{
	Board ( ge211::Dimensions board_dimensions,
						ge211::Random &random,
						int groups,
						int types  );
	std::vector<Tile_Data> tiles_data;
	Tile_Data *map[100][100];
	ge211::Random &random_;
	int groups_;
	int types_;
	std::vector<Tile_Data> &get_tiles();
	void swap (Board_Position p1, Board_Position p2);
	bool run_step();
	Tile_Data &find_tile(Board_Position position);
};
