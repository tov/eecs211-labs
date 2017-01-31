#pragma once

#include <vector>
#include <string>
#include <memory>

struct Circus
{
    std::string name;
    std::string owner;
    std::vector<std::string> animals;
    std::vector<std::string> performers;
    int seating_capacity;
    std::vector<int> performance_times;
    std::shared_ptr<Circus> sister_circus;
};

void passed_by_copy(Circus c);
void passed_by_reference(Circus& c);

void swap_sister_names(Circus& c);
void remove_sister_circus(Circus& c);
Circus& replace_sister_circus(Circus& c, std::string name);
