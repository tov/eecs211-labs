#pragma once

#include <ge211.hxx>

#include <unordered_set>
#include <vector>

class Tile;

class Board
{
public:
    ///
    /// MEMBER TYPES
    ///

    using Rectangle = ge211::Rect<int>;
    using Position = ge211::Posn<int>;
    using Dimensions = ge211::Dims<int>;
    using Coordinate = Rectangle::Coordinate;
    using Position_set = std::unordered_set<Position>;

    ///
    /// MEMBER FUNCTIONS
    ///

    explicit Board(Dimensions);

    // Is the given position in bounds?
    bool contains(Position) const;

    // Are the two positions in bounds and adjacent?
    bool adjacent_positions(Position, Position) const;

    // Returns the dimensions of the board.
    Dimensions dimensions() const
    { return dimensions_; }

    // Returns a rectangle containing all the positions in the board.
    Rectangle positions() const;

    // Indexing by position.
    Tile operator[](Position) const;

    // Indexing by position.
    Tile& operator[](Position);

private:
    void bounds_check_(Position) const;

    std::size_t index_(Position) const;

    std::size_t compute_index_(Position) const;

    Dimensions dimensions_;
    std::vector<Tile> tiles_;
};

