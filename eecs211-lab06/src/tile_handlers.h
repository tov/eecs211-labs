#include "tiles.h"
#include <iostream>

 class Normal_Handler : public Tile_Handler {
 public:
	Normal_Handler(){};
     std::vector<Board_Position> process_removal( Tile_Data td, ge211::Dimensions d ) ; 
 };

 class Horizontal_Lazer_Handler : public Tile_Handler {
 public:
 Horizontal_Lazer_Handler(){};
     std::vector<Board_Position> process_removal( Tile_Data td, ge211::Dimensions d ) ; 
 };

