#include "view.hxx"
#include <iostream>

static ge211::Color const selection_color{180, 200, 190, 255};

///
/// Constructor
///

static ge211::Color from_hue(double hue)
{
    return ge211::Color::from_hsva(hue, 1, 1, 1);
}

View::View(const Model& model, ge211::Dims<int> window)
        : model_(model),
          geometry_(model.board().dimensions(), window),
          sans_("sans.ttf", 2 * geometry_.grid_size),
          selection_sprite_(geometry_.grid_dims(), selection_color)
{
    const int    groups = model_.number_of_groups();
    const double step   = 360.0 / groups;

    double hue = 0;

    for (int i = 0; i < groups; ++i) {
        tile_sprites_.emplace_back(geometry_.tile_radius(), from_hue(hue));
        hue += step;
    }

    for (auto action : model_.actions()) {
        const std::string& type = action->symbol();
        if (type.empty()) continue;

        ge211::Text_sprite::Builder builder{sans_};
        type_sprites_.emplace(type, (builder << type).build());
    }
}

///
/// Member functions
///

void View::draw(ge211::Sprite_set& sprites, Board::Position selection) const
{
    const Board& board = model_.board();
    auto ldims = board.dimensions();

    for (Board::Coordinate col = 0; col < ldims.width; ++col) {
        for (Board::Coordinate row = 0; row < ldims.height; ++row) {
            Board::Position lpos{col, row};
            ge211::Posn<int> ppos = board_to_screen(lpos);
            const Tile& tile = board[lpos];

            if (lpos == selection) {
                sprites.add_sprite(selection_sprite_, ppos, 0);
            }

            if (tile.is_empty()) continue;

            sprites.add_sprite(tile_sprites_.at(tile.group()), ppos, 1);

            auto iter = type_sprites_.find(tile.action_symbol());
            if (iter != type_sprites_.end()) {
                const auto& sprite = iter->second;
                auto extra = geometry_.grid_dims() - sprite.dimensions();
                sprites.add_sprite(sprite, ppos + extra / 2, 2);
            }
        }
    }
}

Model::Position View::screen_to_board(Model::Position pos) const
{
    return geometry_.screen_to_board(pos);
}

Model::Position View::board_to_screen(Model::Position pos) const
{
    return geometry_.board_to_screen(pos);
}

View::Geometry::Geometry(View::Geometry::Dimensions ldims,
                         View::Geometry::Dimensions pdims)
{
    int hfit = pdims.width / (ldims.width + 1);
    int vfit = pdims.height / (ldims.height + 1);

    grid_size = std::min(hfit, vfit);
    margin    = (pdims - grid_size * ldims) / 2;
}

View::Geometry::Position
View::Geometry::screen_to_board(Position pos) const
{
    Position o(0, 0);
    return o + (pos - o - margin) / grid_size;
}

View::Geometry::Position
View::Geometry::board_to_screen(Position pos) const
{
    Position o(0, 0);
    return o + (pos - o) * grid_size + margin;
}

int View::Geometry::tile_radius() const
{
    return grid_size / 2;
}

View::Geometry::Dimensions View::Geometry::grid_dims() const
{
    return {grid_size, grid_size};
}

