#include "model.hxx"

#include <ge211.hxx>

#include <algorithm>

///
/// Constructors
///
Model::Model(Dimensions board_dimensions,
             int number_of_groups,
             int min_group_size)
        : board_(board_dimensions)
        , number_of_groups_(number_of_groups)
        , min_group_size_(min_group_size)
        , random_group_(ge211::unbounded)
        , random_action_(ge211::unbounded)
        , random_action_probability_(0.05) // 1-in-20(5%) chance of special type
{
    // use .stub_with(...) here on random sources if you want non-random
    // results while developing
}

///
/// Public member functions
///

bool Model::step()
{
    return contagion_step_() || falling_step_() || scavenge_step_();
}

bool Model::swap_tiles(Position p1, Position p2)
{
    if (board_.adjacent_positions(p1, p2)) {
        std::swap(board_[p1], board_[p2]);
        return true;
    }

    return false;
}

///
/// Private member functions
///

bool Model::contagion_step_()
{
    if (condemned_.empty()) return false;

    Position pos = condemned_.front();

    Position_set  next = board_[pos].apply_action(pos, board_);
    for (Position next_pos : next) {
        condemn_position_(next_pos);
    }

    board_[pos].remove();
    condemned_.pop();

    return true;
}

void Model::condemn_position_(Position pos)
{
    Tile& tile = board_[pos];

    if (tile.is_full()) {
        tile.condemn();
        condemned_.push(pos);
    }
}

bool Model::falling_step_()
{
    auto dims = board_.dimensions();

    bool changed = false;

    for (Coordinate col = 0; col < dims.width; ++col) {
        for (Coordinate row = dims.height - 1; row > 0; --row) {
            Position pos{col, row};

            if (board_[pos].is_empty()) {
                changed = true;
                std::swap(board_[pos], board_[pos.up_by(1)]);
            }
        }

        Position top{col, 0};

        if (board_[top].is_empty()) {
            changed = true;
            board_[top].restore(number_of_groups_, actions_, random_group_,
                                random_action_, random_action_probability_);
        }
    }

    return changed;
}

bool Model::scavenge_step_()
{
    bool changed = false;

    for (Position pos : board_.positions()) {
        if (scavenge_position_(pos)) {
            changed = true;
        }
    }

    return changed;
}

bool Model::scavenge_position_(Model::Position pos)
{
    Position_set set = gather_group_(pos);

    if (set.size() < min_group_size_) return false;

    for (Position neighbor : set) {
        condemn_position_(neighbor);
    }

    return true;
}

Board::Position_set Model::gather_group_(Position start)
{
    // The set we are building to return:
    Position_set result{start};

    // The positions whose neighbors we need to look at:
    std::vector<Position> todo{start};

    // The group (color) of tile to include.
    const int goal = board_[start].group();

    // (A local helper function written using a lambda.)
    //
    // This takes a position, and if the position is in bounds, has the right
    // group, and isn't yet in the result set, then we add it to the result set
    // and to the to-do list of positions whose neighbors we need to visit in
    // the future.
    auto consider = [&](Position pos) {
        if (!board_.contains(pos)) return;
        if (!board_[pos].has_group(goal)) return;
        if (result.count(pos)) return;

        result.insert(pos);
        todo.push_back(pos);
    };

    while (!todo.empty()) {
        Position pos = todo.back();
        todo.pop_back();

        consider(pos.up_by(1));
        consider(pos.down_by(1));
        consider(pos.left_by(1));
        consider(pos.right_by(1));
    }

    return result;
}

Model& Model::add_action(const Tile::Action& a)
{
    actions_.push_back(&a);
    return *this;
}

