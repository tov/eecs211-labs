#include "controller.hxx"
#include "tile_handlers.hxx"

#include <iostream>
#include <stdexcept>

ge211::Dimensions board_dimensions{10, 8};

int group_count = 6;

int types_count = 2; // Normal and Horizontal Lazer

int main()
{
    try {
        Normal_handler           normal;
        Horizontal_lazer_handler horizontal_lazer;

        Controller(board_dimensions,
                   group_count,
                   types_count,
                   {Tile_handler_reference(normal),
                    Tile_handler_reference(horizontal_lazer)},
                   {" ", "-"})
                .run();
    } catch (std::runtime_error const& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
}
