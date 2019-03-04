#include "controller.h"

#include <iostream>
#include <stdexcept>

ge211::Dimensions board_dimensions{10,8};

int main()
{
    try {
        Controller( board_dimensions).run();
    } catch (std::runtime_error const& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
}
