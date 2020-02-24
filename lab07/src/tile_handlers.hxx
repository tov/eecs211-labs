#include "tiles.hxx"

#include <vector>

class Normal_handler : public Tile_handler
{
public:
    Normal_handler()
    { };

    std::vector<Board_position>
    process_removal(Tile_data td, ge211::Dimensions d);
};

class Horizontal_lazer_handler : public Tile_handler
{
public:
    Horizontal_lazer_handler()
    { };

    std::vector<Board_position>
    process_removal(Tile_data td, ge211::Dimensions d);
};

