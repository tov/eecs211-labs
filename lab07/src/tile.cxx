#include "tile.hxx"

Tile::Tile()
        : status_(Tile::Status::empty),
          group_(0),
          action_(nullptr)
{ }

void Tile::restore(
        int number_of_groups,
        const Action_list& actions,
        ge211::Random& random)
{
    status_ = Tile::Status::full;
    group_  = random.between(0, number_of_groups - 1);

    // 1-in-20 (5%) chance of special type:
    if (random.between(1, 20) == 1) {
        auto choice = random.between<std::size_t>(1, actions.size() - 1);
        action_ = actions[choice];
    } else {
        action_ = actions[0];
    }
}

Board::Position_set
Tile::apply_action(Board::Position pos, const Board& board) const
{
    if (action_) {
        return action_->apply(pos, board);
    } else {
        return {};
    }
}

const std::string&
Tile::action_symbol() const
{
    if (action_) {
        return action_->symbol();
    } else {
        // static means this lives between calls:
        static const std::string empty;
        return empty;
    }
}

void Tile::condemn()
{
    if (is_full())
        status_ = Status::condemned;
}

void Tile::remove()
{
    status_ = Status::empty;
}
