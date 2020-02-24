#include "tile_handlers.hxx"

#include <iostream>

std::vector<Board_position>
Normal_handler::process_removal(Tile_data td, ge211::Dimensions d)
{
    std::vector<Board_position> v = {td.position};
    return v;
}

std::vector<Board_position>
Horizontal_lazer_handler::process_removal(Tile_data td, ge211::Dimensions d)
{
    std::vector<Board_position> v;

    std::clog << td.position.hash() << " special!\n";

    for (int col = 0; col < d.width; col++) {
        std::clog << "ROW: " << td.position.row << " COL: " << col << "\n";
        v.push_back({td.position.row, col});
    }
    return v;
}

