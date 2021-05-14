#include "controller.hxx"

#include <iostream>
#include <stdexcept>

int
main()
{
    ////    You can also provide an explicit list of words:
    //    Controller{"explicit", "word", "list"}.run();

    try {
        Controller("dictionary.dat").run();
    }

    catch (std::runtime_error const& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
}

