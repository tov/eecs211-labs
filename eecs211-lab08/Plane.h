#include "Vehicle.h"
#include <iostream>

class Plane:Vehicle{
private:
    std::string engines_; // Number of engines
public:
    void Drive();
};

