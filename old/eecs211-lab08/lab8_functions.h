#pragma once

#include "Vehicle.h"
#include <vector>
#include <memory>

using namespace std;


int move_for_distance(shared_ptr<Vehicle> v, double distance);
double move_for_time(shared_ptr<Vehicle> v, double time);
shared_ptr<Vehicle> race(vector<shared_ptr<Vehicle>> vehicles, double distance);