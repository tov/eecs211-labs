#include "model.h"
#include <ge211.h>
#include <cctype>
#include <cstdlib>
#include <fstream>

int const bubble_radius     = 30;
int const bubble_offset     = 70;
int const espinosas_number  = 7;

// UI object
class Game : public ge211::Abstract_game
{
public:
    ///
    /// Constructors
    ///

    explicit Game(const std::vector<std::string>& words);

    explicit Game(std::string const& filename);

    ///
    /// Member functions
    ///

    // Controller
    void on_start() override;

    void on_frame(double dt) override;

    void on_key(ge211::Key key) override;

    // View
    void draw(ge211::Sprite_set& sprites) override;

private:
    void new_word_();

    void init_letter_sprites();

    ///
    /// Member variables
    ///

    // Model
    Model model_;

    // View
    struct Bubble_
    {
        // Constructor
        Bubble_(ge211::Text_sprite&, ge211::Position);

        /// Member functions
        ge211::Position bubble_position() const;
        ge211::Position letter_position() const;

        /// Member variables
        ge211::Text_sprite& letter_sprite;
        ge211::Position     center;
    };

    std::vector<Bubble_> bubbles_;

    ge211::Font sans_{"sans.ttf", 30};
    std::vector<ge211::Text_sprite> letter_sprites_;

    ge211::Circle_sprite yellow_bubble_{bubble_radius, ge211::Color::medium_yellow()};
    ge211::Circle_sprite green_bubble_{bubble_radius, ge211::Color::medium_green()};
    ge211::Circle_sprite red_bubble_{bubble_radius, ge211::Color::medium_red()};
};

int main()
{
    Game{"../Resources/dictionary.dat"}.run();
}

Game::Game(std::vector<std::string> const& words)
        : model_(words)
{
    init_letter_sprites();
}

static std::vector<std::string> words_in_file(std::string const& filename)
{
    std::vector<std::string> result;
    std::ifstream dictionary(filename);
    std::string buffer;

    if (!dictionary.is_open()) {
        std::perror(("could not open dictionary: " + filename).c_str());
        std::exit(1);
    }

    while (std::getline(dictionary, buffer))
        result.push_back(buffer);

    if (dictionary.bad()) {
        std::perror(("could not read dictionary: " + filename).c_str());
        std::exit(2);
    }

    return result;
}

Game::Game(std::string const& filename)
        : Game(words_in_file(filename))
{ }

Game::Bubble_::Bubble_(ge211::Text_sprite& sprite, ge211::Position position)
        : letter_sprite(sprite)
        , center(position)
{ }

ge211::Position Game::Bubble_::bubble_position() const
{
    return center.up_by(bubble_radius).left_by(bubble_radius);
}

ge211::Position Game::Bubble_::letter_position() const
{
    return center.right_by(bubble_radius - espinosas_number);
}

void Game::init_letter_sprites()
{
    for (char letter = 'a'; letter <= 'z'; ++letter)
        letter_sprites_.emplace_back(std::string(1, letter), sans_);
}

void Game::draw(ge211::Sprite_set& sprites)
{
    std::vector<bool> const& progress = model_.typing_progress();

    for (int i = 0; i < bubbles_.size(); ++i) {
        Bubble_ const& bubble = bubbles_[i];
        sprites.add_sprite(bubble.letter_sprite,
                           bubble.letter_position(),
                           1);
        sprites.add_sprite(i < progress.size()
                           ? progress[i]
                             ? green_bubble_
                             : red_bubble_
                           : yellow_bubble_,
                           bubble.center, 0);
    }
}

void Game::new_word_()
{
    std::string const& word = model_.current_word();

    int word_width = static_cast<int>(word.length()) * bubble_offset;

    ge211::Dimensions window_dims = get_window().get_dimensions();

    int x = get_random().between(0, window_dims.width - word_width);
    int y = get_random().between(0, window_dims.height - bubble_radius * 2);
    ge211::Position position{x, y};

    bubbles_.clear();

    for (char c : word) {
        position.x += bubble_offset;
        size_t i    = static_cast<size_t>(std::tolower(c) - 'a');
        bubbles_.emplace_back(letter_sprites_.at(i), position);
    }
}

void Game::on_start()
{
    new_word_();
}

void Game::on_key(ge211::Key key)
{
    model_.hit_key(char(key.code()));

    if (model_.game_is_finished())
        model_ = Model{"gameover"};

    if (model_.typing_progress().empty())
        new_word_();
}

void Game::on_frame(double dt)
{
    model_.update(dt);
}

