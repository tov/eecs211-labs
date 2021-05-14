#pragma once

#include "board.hxx"

#include <ge211.hxx>

#include <vector>

class Tile
{
    enum class Status
    {
        full, condemned, empty,
    };

public:
    class Action;

    using Action_list = std::vector<const Action *>;

    Tile();

    void restore(
            int number_of_groups,
            const Action_list&,
            ge211::Random_source<int>& random_group,
            ge211::Random_source<int>& random_action,
            ge211::Random_source<bool>& random_action_probability);

    bool is_full() const
    { return status_ == Status::full; }

    bool is_condemned() const
    { return status_ == Status::condemned; }

    bool is_empty() const
    { return status_ == Status::empty; }

    void condemn();

    void remove();

    int group() const
    { return group_; }

    bool has_group(int group) const
    { return is_full() && group_ == group; }

    Board::Position_set apply_action(Board::Position, const Board&) const;

    const std::string& action_symbol() const;

private:
    Status status_;
    int group_;
    const Action *action_;
};

class Tile::Action
{
public:
    using Position = Board::Position;
    using Position_set = Board::Position_set;

    // Let `Tile` call the protected `apply()` function.
    friend Tile;

    // Returns a fixed textual representation for displaying this action.
    const std::string& symbol() const
    { return symbol_; }

    // Polymorphic classes require virtual destructors:
    virtual ~Action() = default;

protected:
    // Derived classes need to call this with the correct
    // symbol.
    explicit Action(const std::string symbol = "")
            : symbol_(symbol)
    { }

    // Called when a tile goes away to produce a list of tiles to zap
    // next.
    virtual Position_set
    apply(Position pos, const Board& board) const = 0;

private:
    std::string symbol_;
};

