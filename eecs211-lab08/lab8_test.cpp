#include "Boat.h"
#include "Car.h"
#include "Plane.h"
#include "lab8_functions.h"
#include "Vehicle.h"

#include <UnitTest++/UnitTest++.h>
#include <stdexcept>
#include <iostream>
#include <vector>

//using namespace std;

TEST(B_DRIVE){
    Boat s("Sail Boat");
    Boat m("Motor Boat");
    s.Drive();
    m.Drive();
    CHECK_EQUAL(10, s.position());
    CHECK_EQUAL(25, m.position());
}

TEST(C_DRIVE){
    Car c;
    c.Drive();
    CHECK_EQUAL(30, c.position());
}

TEST(P_DRIVE){
    Plane p;
    p.Drive();
    CHECK_EQUAL(100, p.position());
}

TEST(B_MOVEFORDISTANCE){
    shared_ptr<Vehicle> m = make_shared<Boat>("Motor Boat");
    shared_ptr<Vehicle> s = make_shared<Boat>("Sail Boat");
    CHECK_EQUAL(2, move_for_distance(s, 20));
    CHECK_EQUAL(3, move_for_distance(s, 25));
    CHECK_EQUAL(2, move_for_distance(s, 15));
    CHECK_EQUAL(2, move_for_distance(m, 50));
    CHECK_EQUAL(3, move_for_distance(m, 60));
    CHECK_EQUAL(2, move_for_distance(m, 40));
}

TEST(C_MOVEFORDISTANCE){
    shared_ptr<Vehicle> c = make_shared<Car>();
    CHECK_EQUAL(move_for_distance(c, 60), 2);
    CHECK_EQUAL(move_for_distance(c, 80), 3);
    CHECK_EQUAL(move_for_distance(c, 40), 2);
}

TEST(P_MOVEFORDISTANCE){
    shared_ptr<Vehicle> p = make_shared<Plane>();
    CHECK_EQUAL(move_for_distance(p, 200), 2);
    CHECK_EQUAL(move_for_distance(p, 150), 2);
    CHECK_EQUAL(move_for_distance(p, 300), 3);
}

TEST(B_MOVEFORTIME){
    shared_ptr<Vehicle> m = make_shared<Boat>("Motor Boat");
    shared_ptr<Vehicle> s = make_shared<Boat>("Sail Boat");
    CHECK_EQUAL(move_for_time(s, 1), 20);
    CHECK_EQUAL(move_for_time(m, 1), 50);
}

TEST(C_MOVEFORTIME){
    shared_ptr<Vehicle> c = make_shared<Car>();
    CHECK_EQUAL(move_for_time(c, 1), 60);
}

TEST(P_MOVEFORTIME){
    shared_ptr<Vehicle> p = make_shared<Plane>();
    CHECK_EQUAL(move_for_time(p, 1), 200);
}

TEST(RACE){
    shared_ptr<Vehicle> b = make_shared<Boat>();
    shared_ptr<Vehicle> c = make_shared<Car>();
    shared_ptr<Vehicle> p = make_shared<Plane>();
    vector<shared_ptr<Vehicle>> vehicles = {b, p, c};
    shared_ptr<Vehicle> winner = race(vehicles, 100);
    CHECK_EQUAL(winner, p);
}

