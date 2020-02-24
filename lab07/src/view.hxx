#pragma once
#include <algorithm>
#include "model.hxx"

static int const    tile_radius    = 30;

static int const    top_margin     = 80;

static int const    left_margin    = 80;

static double const animation_time = .4;

static int const    font_size      = 75;

// Controls how the game is shown to the user:
class View
{
public:
    ///
    /// Public member functions
    ///
    explicit View(Model&, int groups,
                  std::vector<std::string> type_sprites);

    void draw(ge211::Sprite_set&, Board_position select_tile) const;

    bool is_busy();

    bool update(double ft);

    Board_position board_position(ge211::Position position);

private:
    ///
    /// Private helper functions
    ///
    bool is_changed_(std::vector<Tile_data> tiles_data);

    ge211::Position screen_position_(Tile_data td, double p) const;

    // The view can look at the model but doesn't change it.
    Model& model_;

    // The tiles.
    std::vector<Tile_data> tiles_;
    double                 animation_progress_;

    // Sprites for tiles:
    ge211::Font                       sans_{"sans.ttf", font_size};
    ge211::Rectangle_sprite
                                      selection_sprite_
                                              {{tile_radius * 2,
                                                       tile_radius * 2},
                                               {127,   127, 127, 255}};
    std::vector<ge211::Circle_sprite> tiles_sprites_;
    std::vector<ge211::Text_sprite>   type_sprites_;
};
