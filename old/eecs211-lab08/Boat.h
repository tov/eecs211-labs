#pragma once
#include "Vehicle.h"
#include <iostream>

class Boat: public Vehicle{
private:
    std::string movementType_; // "Sail Boat" or "Motor Boat"
public:
    Boat() : Vehicle(), movementType_("Sail Boat") {}
    Boat(std::string str) : Vehicle(), movementType_(str) {}
    ~Boat() {}
    void Drive();
    std::string vehicleType();
};

