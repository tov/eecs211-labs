#include <ge211.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

#define DELAY 100;

using namespace ge211;
using namespace std;

Dimensions const scene_dimensions{1024, 768};

int const bubble_radius = 30;

Color const green{127, 255, 127, 255};
Color const red{255, 127, 127, 255};

// MODEL DATA DEFINITIONS
struct Bubble
{
	char letter;
	Position position;
};

Bubble new_bubble()
{
	char c='a'+rand() % ('z'-'a');
	return { c,{20+rand() % (scene_dimensions.height - 40),20+rand() % (scene_dimensions.width - 40)}};
}


struct Model
{
	Bubble bubble=new_bubble();
	char last_key='\0';
	enum State{red,yellow,green} state = red;
    void update(double const dt);
};

struct View
{
    View();
    Font sans{"sans.ttf", 30};
    Text_sprite letter;
	Circle_sprite bubble_red{bubble_radius, red};
	Circle_sprite bubble_green{bubble_radius, green};
};

struct Game : Abstract_game
{
    Model model;

    View view;
    Dimensions initial_window_dimensions() const override;
    void draw(Sprite_set& sprites) override;

    bool is_paused = false;
    void on_key(Key key) override;
    void on_frame(double dt) override;
};

int main()
{
    Game{}.run();
}

void Model::update(double const dt)
{
	static int delay = DELAY;
	delay--;
	if (last_key==bubble.letter)
	{
		state=green;
		cout<<"hit!\n";
		last_key='\0';
	}
	if (!delay)
	{
		delay=DELAY;
		state=red;
		bubble=new_bubble();
	}
	return;
}

View::View()
{
}

Dimensions Game::initial_window_dimensions() const
{
    return scene_dimensions;
}

void Game::draw(Sprite_set& sprites)
{	
    view.letter.reconfigure(Text_sprite::Builder(view.sans) << "   " << model.bubble.letter );
	sprites.add_sprite(view.letter, model.bubble.position.into<int>());
	switch (model.state)
	{
		case Model::red:
			sprites.add_sprite(view.bubble_red, model.bubble.position.into<int>());
			break;
		case Model::green:
			sprites.add_sprite(view.bubble_green, model.bubble.position.into<int>());
			break;
	}
}

void Game::on_key(Key key)
{
	model.last_key=key.code();
}

void Game::on_frame(double dt)
{
	model.update(dt);
}