#include "Vehicle.h"
#include <iostream>

class Plane: public Vehicle{
private:
    int engines_; // Number of engines
public:
    void Drive();
};

