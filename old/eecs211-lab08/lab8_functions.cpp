#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Vehicle.h"
#include "Car.h"
#include "Plane.h"
#include "Boat.h"

using namespace std;

/// Move the vehicle until its position has changed by the specified distance (miles)
/// Return the number of half-hours it took for the vehicle's position to be changed by the specified distance
int move_for_distance(shared_ptr<Vehicle> v, double distance){

    // [YOUR CODE HERE]
}

/// Move the vehicle until the specified amount of time has passed (hours)
/// Returns the distance covered by vehicle in the specified amount of time
double move_for_time(shared_ptr<Vehicle> v, double time){

    // [YOUR CODE HERE]
}

/// Race a set of vehicles over a set distance. The function takes in a vector of Vehicle shared_ptrs
/// Returns the shared_ptr to the Vehicle which wins the race,
/// i.e. the vehicle that moves the distance in the least amount of time
shared_ptr<Vehicle> race(vector<shared_ptr<Vehicle>> vehicles, double distance) {

    // [YOUR CODE HERE]
    return nullptr;

}





