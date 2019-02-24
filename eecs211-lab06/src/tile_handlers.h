#include "tiles.h"

 class Normal_Handler : public Tile_Handler {
 public:
	Normal_Handler(){};
     std::vector<Board_Position> process_removal( Tile_Data td, int group, ge211::Dimensions d ) ; 
 };

 class Horizontal_Laser_Handler : public Tile_Handler {
 public:
 Horizontal_Laser_Handler(){};
     std::vector<Board_Position> process_removal( Tile_Data td, int group, ge211::Dimensions d ) ; 
 };

