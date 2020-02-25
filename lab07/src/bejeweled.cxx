#include "controller.hxx"
#include "actions.hxx"

#include <iostream>
#include <stdexcept>

static const Model::Dimensions board_dimensions{8, 10};

static const int min_group_size = 4;

static const int number_of_groups = 6;

static const Normal_action normal;

static const Horizontal_lazer_action hlazer;

int main() try
{
    Model model(board_dimensions, number_of_groups, min_group_size);

    model.add_action(normal)
         .add_action(hlazer);

    Controller(model).run();
}

catch (std::runtime_error const& e) {
    std::cerr << e.what() << "\n";
    return 1;
}
