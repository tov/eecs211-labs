#include "model.h"
#include <algorithm>
#include <iostream>

///
/// Constructors
///
Model::Model( ge211::Dimensions board_dimensions,
                       int groups,
                       int types,
                       ge211::Random& random,
                       std::vector<Tile_Handler_Reference> handlers)
        : board_dimensions_(board_dimensions)
        , groups_(groups)
        , types_(types)
        , random_(random)
        , handlers_(handlers)
{
    for (int col = 0; col < board_dimensions.width; col ++)
        for (int row = 0; row < board_dimensions.height; row ++)
        {
            Tile tile = new_tile_({row,col});
            map_2.insert(std::make_pair (tile.tile_data.position.hash(),tile));
        }
}

Model::Model( ge211::Dimensions board_dimensions,
                       int groups,
                       int types,
                       ge211::Random& random,
                       std::vector<Tile_Handler_Reference> handlers,
                       std::vector<std::vector<int>> board_group_layout,
                       std::vector<std::vector<int>> board_type_layout)
        : board_dimensions_(board_dimensions)
        , groups_(groups)
        , types_(types)
        , random_(random)
        , handlers_(handlers)
{
    for (int col = 0; col < board_dimensions.width; col ++)
        for (int row = 0; row < board_dimensions.height; row ++)
        {
            Tile tile = new_specific_tile_({row,col},
                                           board_group_layout[row][col],
                                           board_type_layout[row][col]);
            map_2.insert(std::make_pair (tile.tile_data.position.hash(),tile));
        }
}


///
/// Public member functions
///
std::vector<Tile_Data> Model::get_tiles()
{
    std::vector<Tile_Data> tiles_data;
    for (std::pair<int, Tile> pair : map_2 )
        tiles_data.push_back(pair.second.tile_data);
    return tiles_data;
}

bool Model::run_step()
{
    remove_tiles_(find_tiles_to_delete());
}

std::vector<Board_Position> Model::find_tiles_to_delete()
{
    // finds all the positions in the board that changed
    std::vector<Board_Position> updates;
    for (int col = 0 ; col < board_dimensions_.width ; col ++)
        for (int row = 0 ; row < board_dimensions_.height ; row ++)
        {
            Board_Position bp { row , col };
            if (map_2.at(bp.hash()).tile_data.position_prev!=map_2.at(bp.hash()).tile_data.position)
                updates.push_back(bp);
        }

    std::vector<Board_Position> marked;

    bool new_updates = true;
    while (new_updates)
    {
        new_updates=false;
        for(Board_Position bp:updates)
        {
        // updates the previus position to not catch the changes
        //  again in the future
            map_2.at(bp.hash()).tile_data.position_prev=map_2.at(bp.hash()).tile_data.position;

        // if the position is part of a marked group it skips
            if (!in_(marked, bp))
            {
        // get the tiles that are connected to the one that changed
        // and are part of the same group
                std::vector<Board_Position> group=get_group_(bp);
        // if the size of the connected group is big enough
                if (group.size()>=3)
                    for ( Board_Position bp: group )
                    {
        //marks every tile in the group for deletion
        //runs the handlers for the types and get the affected positions
                        Tile tile = map_2.at(bp.hash());
                        Tile_Handler_Reference thr = handlers_[tile.tile_data.type];
                        std::vector<Board_Position> affected = thr.get_handler().process_removal(tile.tile_data, board_dimensions_);
                        for ( Board_Position bpa: affected )
                        {
        //and adds them to the list to execute the handlers.
                            if (!in_(marked, bpa))
                            {
                                marked.push_back(bpa);
                                std::cout << "row " << bp.row << " col " << bp.column << "\n";
                            }
                        }
                    }
            }
        }
    }
    std::cout << "\n";
    return marked;
}

bool Model::is_valid_swap(Board_Position p1,Board_Position p2)
{
    return is_valid(p1) && is_valid(p2) && (p1 == p2.left() || p1 == p2.right() || p1 == p2.up() || p1 == p2.down());
}

void Model::swap(Board_Position p1, Board_Position p2)
{
    if (is_valid_swap(p1,p2))
        swap_(p1,p2);
}

bool Model::is_valid(Board_Position p)
{
    return p.row >= 0 && p.column >= 0 && p.row < board_dimensions_.height && p.column < board_dimensions_.width;
}

///
/// Private member functions
///

void Model::remove_tiles_( std::vector<Board_Position> marked )
{
    for (int row = 0 ; row < board_dimensions_.height ; row ++)
        for (int col = 0 ; col < board_dimensions_.width ; col ++)
        {
            Board_Position mbp{row,col};
            if (in_(marked,mbp))
            {
                Board_Position bp = mbp;
                while (bp.row>0)
                {
                    swap_(bp,bp.up());
                    bp = bp.up();
                }
                Tile tile = new_tile_(bp);
                map_2.at(bp.hash()) = tile;
            }
        }
}

void Model::find_connected_try_(Board_Position bp, int group, std::vector<Board_Position> &connected)
{
    if (is_valid(bp) && map_2.at (bp.hash()).tile_data.group == group && !in_(connected,bp))
        find_connected_( bp, group, connected);
}

bool Model::find_connected_(Board_Position bp, int group, std::vector<Board_Position> &connected)
{
    connected.push_back(bp);
    find_connected_try_(bp.left(), group, connected);
    find_connected_try_(bp.right(), group, connected);
    find_connected_try_(bp.up(), group, connected);
    find_connected_try_(bp.down(), group, connected);
    return true;
}

std::vector<Board_Position> Model::get_group_(Board_Position bp)
{
    std::vector<Board_Position> connected;
    find_connected_(bp, map_2.at(bp.hash()).tile_data.group, connected);
    return connected;
}

bool Model::in_(std::vector<Board_Position> &list,Board_Position position )
{
    for (Board_Position &bp: list)
        if (position == bp) return true;
    return false;
}

Tile Model::new_tile_(Board_Position bp)
{
    int type;
    if (random_.between(0,100)>95) //5% chances of special type
        type = random_.between(1,types_-1);
    else
        type = 0;

    Tile new_tile =
    {
        //tile_data
        {
            //Position
            bp,
            //Position Prev (outside the screen)
            {bp.row-board_dimensions_.height,bp.column},
            //random group ( color )
            random_.between(0,+groups_-1),
            //type
            type
        },
        handlers_[type].get_handler()
    };
    return new_tile;
}

Tile Model::new_specific_tile_(Board_Position bp, int type, int group)
{
    // type must be between 1 and types_ - 1,
    // group  must be between 0 and groups_ - 1
    Tile new_tile =
    {
        {
            bp,
            {bp.row - board_dimensions_.height, bp.column},
            group,
            type
        },
        handlers_[type].get_handler()
    };
    return new_tile;
}

void Model::swap_(Board_Position p1, Board_Position p2)
{
    map_2.at(p1.hash()).swap(map_2.at(p2.hash()));
}
