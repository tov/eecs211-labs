#pragma once
#include <vector>
#include <string>


struct Dog{
    std::string name;
    double age;
    std::string favoriteTreat;
};

double meanAge(std::vector<Dog> dogs);