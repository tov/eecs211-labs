#include "controller.h"
#include "tile_handlers.h"

#include <iostream>
#include <stdexcept>

ge211::Dimensions board_dimensions{10,8};
int group_count = 5;
int types_count = 2;

int main()
{
////    You can also provide an explicit list of words:
    try {

		Normal_Handler normal;
		Horizontal_Laser_Handler horizontal_laser;

		std::vector<Tile_Handler_Reference> handlers ;
		handlers.push_back(Tile_Handler_Reference(normal));
        handlers.push_back(Tile_Handler_Reference(horizontal_laser));

        Controller(board_dimensions,group_count, types_count, handlers).run();

    } catch (std::runtime_error const& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
}

