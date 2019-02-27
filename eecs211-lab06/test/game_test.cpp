#include "../src/model.h"
#include "../src/tile_handlers.h"
#include <ge211.h>
#include <catch.h>

ge211::Dimensions board_dimensions{6,4};
int group_count = 6;
int types_count = 2; // Normal and Horizontal Lazer


TEST_CASE("Normal")
{
    Normal_Handler normal;
    Horizontal_Lazer_Handler horizontal_lazer;
    temp t;
    Model model(board_dimensions,
                group_count,
                types_count,
                get_random(), // not working, needs to come from an abstract game class
                {Tile_Handler_Reference(normal),
                 Tile_Handler_Reference(horizontal_lazer)},
                {{ 1, 2, 3, 4, 5, 6 },
                 { 2, 5, 6, 1, 2, 3 },
                 { 1, 2, 3, 4, 5, 6 },
                 { 4, 5, 6, 1, 2, 3 }},
                {{ 1, 1, 1, 1, 1, 1 },
                 { 1, 2, 1, 1, 1, 1 },
                 { 1, 1, 1, 1, 1, 1 },
                 { 1, 1, 1, 1, 1, 1 }});
    model.swap({1, 0}, {1, 1});
    std::vector<Board_Position> answer = {{0, 1}, {1, 1}, {2, 1}};
    CHECK( model.find_tiles_to_delete() == answer );
}
