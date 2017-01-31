#pragma once

#include <vector>
#include <string>

struct Circus
{
    std::string name;
    std::string owner;
    std::vector<std::string> animals;
    std::vector<std::string> performers;
    int seatingCapacity;
    std::vector<int> performanceTimes;
};

void passedByCopy(Circus c);
void passedByReference(Circus& c);
