#pragma once

#include "tile.hxx"

class Normal_action : public Tile::Action
{
public:
    Normal_action()
    { }

protected:
    Position_set apply(Position, const Board&) const override;
};

class Horizontal_lazer_action : public Tile::Action
{
public:
    Horizontal_lazer_action()
            : Action("-")
    { }

protected:
    Position_set apply(Position, const Board&) const override;
};

