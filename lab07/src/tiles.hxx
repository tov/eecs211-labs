#pragma once

#include <ge211.hxx>

#include <vector>

struct Board_position
{
    int row;
    int column;

    bool operator==(const Board_position& position)
    {
        return row == position.row && position.column == column;
    }

    bool operator!=(const Board_position& position)
    {
        return !(*this == position);
    }

    int hash()
    {
        return row * 100 + column;
    }

    Board_position left()
    {
        return {row, column - 1};
    }

    Board_position right()
    {
        return {row, column + 1};
    }

    Board_position up()
    {
        return {row - 1, column};
    }

    Board_position down()
    {
        return {row + 1, column};
    }

    static Board_position empty()
    {
        return {-1, -1};
    }

    bool is_empty()
    {
        return row < 0 || column < 0;
    }
};

struct Tile_data
{
    Board_position position;
    Board_position position_prev;
    int            group;
    int            type;
    bool           marked = false;
};

class Tile_handler
{
public:
    virtual std::vector<Board_position> process_removal(
            Tile_data td,
            ge211::Dimensions d) = 0;
};

struct Tile
{
    Tile_data tile_data;
    Tile_handler& handler;

    Tile& operator=(const Tile& tile)
    {
        tile_data = tile.tile_data;
        handler   = tile.handler;
        return *this;
    }

    void swap(Tile& tile)
    {
        Board_position auxbp = tile.tile_data.position;
        Tile           aux   = tile;
        tile.tile_data = tile_data;
        tile.handler   = handler;
        tile_data = aux.tile_data;
        handler   = aux.handler;
        tile_data.position      = tile.tile_data.position;
        tile.tile_data.position = auxbp;
    }
};

class Tile_handler_reference
{
public:
    Tile_handler_reference(Tile_handler& handler)
            : handler_(handler)
    { };

    Tile_handler& get_handler()
    {
        return handler_;
    }

private:
    Tile_handler& handler_;
};



