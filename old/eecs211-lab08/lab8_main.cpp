#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Vehicle.h"
#include "Car.h"
#include "Plane.h"
#include "Boat.h"
#include "lab8_functions.h"

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