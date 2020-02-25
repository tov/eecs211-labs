#include "actions.hxx"

Board::Position_set
Normal_action::apply(Position, const Board&) const
{
    return {};
}

Board::Position_set
Horizontal_lazer_action::apply(Position pos, const Board& board) const
{
    Position_set set;

    for (Position p{0, pos.y}; board.contains(p); p = p.right_by(1))
        set.insert(p);

    return set;
}

