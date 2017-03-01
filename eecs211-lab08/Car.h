#pragma once
#include "Vehicle.h"
#include <iostream>

class Car: public Vehicle{
private:
    double speed_;
public:
    Car() : Vehicle(), speed_(60) {}
    Car(double s) : Vehicle(), speed_(s) {}
    ~Car() {}
    void Drive();
    std::string vehicleType();
};


