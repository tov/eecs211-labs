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
void moveForDistance(Vehicle* v, double distance){

    // [YOUR CODE HERE]
}

/// Move the vehicle until the specified amount of time has passed (hours)
void moveForTime(Vehicle* v, double time){

    // [YOUR CODE HERE]
}

/// Race a set of vehicles over a set distance. The function takes in a vector of Vehicle shared_ptrs
/// Returns the shared_ptr to the Vehicle which wins the race,
/// i.e. the vehicle that moves the distance in the least amount of time
shared_ptr<Vehicle> race(vector<shared_ptr<Vehicle>> vehicles, double distance) {

    // [YOUR CODE HERE]
    return nullptr;

}

int main()
{
    cout << "===========================\n";
    cout << "= Thanks for doing Lab 8! =\n";
    cout << "===========================\n\n";

    shared_ptr<Vehicle> c = make_shared<Car>();
    shared_ptr<Vehicle> p = make_shared<Plane>();
    shared_ptr<Vehicle> b = make_shared<Boat>();

    cout << "The position of c is: " << c->position() << "\n";
    cout << "The position of p is: " << p->position() << "\n";
    cout << "The position of b is: " << b->position() << "\n\n";
    cout << "Calling drive on each vehicle...\n\n";
    c->Drive();
    p->Drive();
    b->Drive();
    cout << "After calling Drive, the position of c is: " << c->position() << "\n";
    cout << "After calling Drive, the position of p is: " << p->position() << "\n";
    cout << "After calling Drive, the position of b is: " << b->position() << "\n\n";

    vector<shared_ptr<Vehicle>> vehicles = {c , p, b};
    shared_ptr<Vehicle> winner = race(vehicles, 100);
    if (winner != nullptr)
        cout << "The winner of the race over 100 miles is the: " << winner->vehicleType() << "!\n";


}



