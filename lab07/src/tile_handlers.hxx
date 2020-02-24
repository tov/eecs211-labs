#include "tiles.hxx"

#include <vector>

class Normal_Handler : public Tile_Handler
{
public:
    Normal_Handler()
    { };

    std::vector<Board_position>
    process_removal(Tile_Data td, ge211::Dimensions d);
};

class Horizontal_Lazer_Handler : public Tile_Handler
{
public:
    Horizontal_Lazer_Handler()
    { };

    std::vector<Board_position>
    process_removal(Tile_Data td, ge211::Dimensions d);
};

