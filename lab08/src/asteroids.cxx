#include "controller.hxx"

#include <iostream>
#include <stdexcept>

ge211::Dims<int> screen_dimensions {1024, 768};

int
main()
{
    try {
        Controller(screen_dimensions).run();
    } catch (std::runtime_error const& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
}
