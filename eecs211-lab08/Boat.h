#pragma once
#include "Vehicle.h"
#include <iostream>

class Boat:Vehicle{
private:
    std::string movementType_; // "Sail Boat" or "Motor Boat"
public:
    void Drive();
};

