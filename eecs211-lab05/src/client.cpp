#include "shared.h"
#include <iostream>
#include <string>

int main()
{
    std::string buffer;
    std::vector<std::string> args;

    while (std::getline(std::cin, buffer) && !buffer.empty())
        args.push_back(buffer);

    int sum = sum_strings(args);

    std::cout << sum << "\n";
}
