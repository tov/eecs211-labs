#include "model.h"
#include <ge211.h>
#include <fstream>
#include <iterator>

int const bubble_radius = 30;
int const bubble_separation = 70;

struct Bubble
{
    ///
    /// Member variables
    ///
    ge211::Text_sprite& letter_sprite;
    ge211::Position position;

    ///
    /// Member functions
    ///
    ge211::Position letter_position();
};

// UI object
struct Game : ge211::Abstract_game
{
    ///
    /// Constructors
    ///

    explicit Game(const std::vector<std::string>& words);

    explicit Game(std::string const& filename);

    ///
    /// Member functions
    ///

    // Controller
    void on_key(ge211::Key key) override;

    void on_start() override;

    void on_frame(double dt) override;


    // View
    void draw(ge211::Sprite_set& sprites) override;

    ge211::Dimensions initial_window_dimensions() const override;

    void new_word();

    void init_letter_sprites();

    ///
    /// Member variables
    ///

    // Model
    Model model;

    // View
    std::vector<Bubble> bubbles;
    ge211::Font sans{"sans.ttf", 30};
    std::vector<ge211::Text_sprite> letter_sprites;
    ge211::Circle_sprite yellow_bubble{bubble_radius, ge211::Color::medium_yellow()};
    ge211::Circle_sprite green_bubble{bubble_radius, ge211::Color::medium_green()};
    ge211::Circle_sprite red_bubble{bubble_radius, ge211::Color::medium_red()};
};

int main()
{
    Game{"Resources/dictionary.dat"}.run();
}

Game::Game(std::vector<std::string> const& words)
        : model(words)
{
    init_letter_sprites();
}

static std::vector<std::string> words_in_file(std::string const& filename)
{
    std::vector<std::string> result;
    std::ifstream dictionary(filename);
    std::string buffer;

    while (std::getline(dictionary, buffer))
        result.push_back(buffer);

    return result;
}

Game::Game(std::string const& filename)
        : Game(words_in_file(filename))
{ }

ge211::Position Bubble::letter_position()
{
    ge211::Position pos = position;
    pos.x += bubble_radius - 7;
    return pos;
}

ge211::Dimensions Game::initial_window_dimensions() const
{
    return scene_dimensions;
}

void Game::on_frame(double dt)
{
    if (model.is_finished()) new_word();
    model.update(dt);
}

void Game::init_letter_sprites()
{
    for (char letter = 'a'; letter <= 'z'; ++letter) {
        letter_sprites.push_back(ge211::Text_sprite(std::string(&letter, 1), sans));
    }
}

void Game::on_start()
{
    new_word();
}

void Game::draw(ge211::Sprite_set& sprites)
{
    std::vector<State> states = model.get_word_state();
    for (size_t i = 0; i < states.size(); i++) {
        Bubble bubble = bubbles[i];
        switch (states[i]) {
            case State::pending:
                sprites.add_sprite(yellow_bubble, bubble.position, i * 2);
                break;
            case State::missed:
                sprites.add_sprite(red_bubble, bubble.position);
                break;
            case State::done:
                sprites.add_sprite(green_bubble, bubble.position);
                break;
        }
        ge211::Position pos = bubble.letter_position();
        sprites.add_sprite(bubble.letter_sprite, pos, i * 2 + 1);
    }
}

void Game::new_word()
{
    std::string word = model.next_word();
    if (word.empty())
        exit(0);
    int word_width = word.length() * (bubble_radius * 2 + bubble_separation);
    int x = get_random().between(0, scene_dimensions.width - word_width);
    int y = get_random().between(0, scene_dimensions.height - bubble_radius * 2);
    ge211::Position starting_position = {x, y};
    bubbles.clear();
    for (size_t i = 0; i < word.length(); i++) {
        char letter = word.at(i);
        ge211::Position position = starting_position;
        position.x += bubble_separation * i;
        Bubble bubble{letter_sprites[letter - 'a'], position};
        bubbles.push_back(bubble);
    }
    model.load_word(word);
}

void Game::on_key(ge211::Key key)
{
    model.hit_key(key.code());
}
