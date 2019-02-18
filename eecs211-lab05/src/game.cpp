#include "controller.h"

#include <iostream>
#include <stdexcept>

int main()
{
    try {
        Controller("../Resources/dictionary.dat").run();
    } catch (std::runtime_error const& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
}

