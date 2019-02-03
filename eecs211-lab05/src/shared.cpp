#include "shared.h"

int sum_strings(const std::vector<std::string>& v)
{
    int result = 0;

    for (std::string const& s : v)
        result += std::stoi(s);

    return result;
}
