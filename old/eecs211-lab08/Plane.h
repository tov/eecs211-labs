#pragma once
#include "Vehicle.h"
#include <iostream>

class Plane: public Vehicle{
private:
    int engines_; // Number of engines
public:
    Plane() : Vehicle(), engines_(2) {}
    Plane(int e) : Vehicle(), engines_(e) {}
    ~Plane() {}
    void Drive();
    std::string vehicleType();
};

