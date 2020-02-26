#include "controller.hxx"

static const double steps_per_second = 30.0;

///
/// Constructors
///

Controller::Controller(Model& model)
        : model_(model),
          view_(model_, ge211::Abstract_game::default_window_dimensions)
{ }


///
/// Protected member functions
///

void Controller::on_frame(double dt)
{
    while (can_animate_()) {
        if (!model_.step()) {
            animating_ = false;
            break;
        }
    }
}

void Controller::draw(ge211::Sprite_set& sprites)
{
    view_.draw(sprites, selection_);
}

void Controller::on_mouse_up(ge211::Mouse_button, ge211::Position board_pos)
{
    if (animating_) return;

    const auto& board = model_.board();

    auto clicked  = view_.screen_to_board(board_pos);
    auto selected = selection_;

    selection_ = {-1, -1};

    if (!board.contains(clicked)) return;
    if (board[clicked].is_empty()) return;

    if (!board.contains(selected)) {
        selection_ = clicked;
        return;
    }

    if (board[selected].is_empty()) return;

    model_.swap_tiles(clicked, selected);
    start_animating_();
}

void Controller::on_start()
{
    model_.set_random(get_random());
    start_animating_();
}

void Controller::start_animating_()
{
    animating_ = true;
    animation_time_.reset();
    animation_steps_ = 0;
}

bool Controller::can_animate_()
{
    if (!animating_) return false;

    auto animation_seconds = animation_time_.elapsed_time().seconds();
    bool
         result            =
                 animation_steps_ < steps_per_second * animation_seconds;
    if (result) ++animation_steps_;
    return result;
}

void Controller::on_key(ge211::Key key)
{
    if (key.code() == 'q') quit();
}
