#pragma once

#include <string>
#include <vector>

struct Dog
{
    std::string name;
    double age;
    double happiness; // happiness level from 1 to 5
    std::string owner;
};

Dog& youngestDog(std::vector<Dog>&);

Dog& happiestDog(std::vector<Dog>&);

std::string findOwner(const std::vector<Dog>&, const std::string&);
