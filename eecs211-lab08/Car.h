#pragma once
#include "Vehicle.h"
#include <iostream>

class Car:Vehicle{
private:
    std::string build_;
    double movementSpeed_;
public:
    void Drive();
};


