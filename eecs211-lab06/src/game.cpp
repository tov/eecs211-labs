#include "controller.h"

#include <iostream>
#include <stdexcept>

ge211::Dimensions board_dimensions{10,8};
int group_count = 5;
int types_count = 5;

int main()
{
////    You can also provide an explicit list of words:
    try {
        Controller(board_dimensions,group_count, types_count).run();
    } catch (std::runtime_error const& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
}

