#include "controller.h"
#include "tile_handlers.h"

#include <iostream>
#include <stdexcept>

ge211::Dimensions board_dimensions{10,8};
int group_count = 5;
int types_count = 2;// Normal and Horizontal Lazer

int main()
{
////    You can also provide an explicit list of words:
    try {
	
		Normal_Handler normal;
		Horizontal_Lazer_Handler horizontal_lazer;
		
        Controller( board_dimensions,
		                 group_count, 
						 types_count, 
						 { Tile_Handler_Reference(normal), 
						   Tile_Handler_Reference(horizontal_lazer) },
						 {" ","-"}).run();

    } catch (std::runtime_error const& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
}

