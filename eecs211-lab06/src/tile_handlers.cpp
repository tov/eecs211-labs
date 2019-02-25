#include "tile_handlers.h"
#include <iostream>

std::vector<Board_Position> Normal_Handler::process_removal( Tile_Data td, ge211::Dimensions d ) 
{
    std::vector<Board_Position> v={td.position};
    return v;
}

std::vector<Board_Position> Horizontal_Lazer_Handler::process_removal( Tile_Data td, ge211::Dimensions d ) 
{
    std::vector<Board_Position> v;
    std::cout<< td.position.hash() <<"special!\n";
    for (int col = 0;col<d.width;col++)
    {    
        std::cout << "ROW: " << td.position.row << " COL: " << col << "\n";
        v.push_back({td.position.row,col});
    }
    return v;
}

