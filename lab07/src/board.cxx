#include "board.hxx"
#include "tile.hxx"

Board::Board(Board::Dimensions dims)
        : dimensions_(dims),
          tiles_(unsigned(dims.width * dims.height))
{ }

bool
Board::contains(Board::Position pos) const
{
    return 0 <= pos.x && pos.x < dimensions().width &&
           0 <= pos.y && pos.y < dimensions().height;
}

bool
Board::adjacent_positions(Position a, Position b) const
{
    return contains(a) &&
           contains(b) &&
           (a.up_by(1) == b ||
            a.down_by(1) == b ||
            a.left_by(1) == b ||
            a.right_by(1) == b);
}

Board::Rectangle
Board::positions() const
{
    return Rectangle::from_top_left({0, 0}, dimensions());
}

Tile
Board::operator[](Board::Position pos) const
{
    return tiles_[index_(pos)];
}

Tile&
Board::operator[](Board::Position pos)
{
    return tiles_[index_(pos)];
}

void
Board::bounds_check_(Position pos) const
{
    if (!contains(pos)) {
        throw std::invalid_argument("Board: position out of bounds");
    }
}

std::size_t
Board::index_(Board::Position pos) const
{
    bounds_check_(pos);
    return compute_index_(pos);
}

std::size_t
Board::compute_index_(Board::Position pos) const
{
    return pos.y * dimensions_.width + pos.x;
}
