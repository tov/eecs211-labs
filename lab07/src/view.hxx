#pragma once

#include "model.hxx"

#include <algorithm>
#include <map>

// Controls how the game is shown to the user:
class View
{
public:
    ///
    /// Public member functions
    ///
    View(const Model& model, ge211::Dimensions window_dimensions);

    void draw(ge211::Sprite_set&, Board::Position selected) const;

    Model::Position screen_to_board(ge211::Position) const;

    ge211::Position board_to_screen(Model::Position) const;

private:
    ///
    /// Private helper functions
    ///

    // The view can look at the model but doesn't change it.
    const Model& model_;

    // A geometry.
    struct Geometry
    {
        using Position    = Model::Position;
        using Dimensions  = Model::Dimensions;

        Geometry(Dimensions logical, Dimensions physical);

        Position screen_to_board(Position) const;

        Position board_to_screen(Position) const;

        int tile_radius() const;

        Dimensions grid_dims() const;

        int        grid_size;
        Dimensions board; // logical
        Dimensions margin; // physical
    }          geometry_;

    // Sprites for tiles:
    ge211::Font                               sans_;
    std::vector<ge211::Circle_sprite>         tile_sprites_;
    std::map<std::string, ge211::Text_sprite> type_sprites_;
    ge211::Rectangle_sprite                   selection_sprite_;
};
