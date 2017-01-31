#include "circus.h"

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


void passedByCopy(Circus c) {
    c.name = "Cirque du Soleil";
    c.owner = "Guy Laliberté";
}

void passedByReference(Circus& c) {
    c.name = "Cirque du Soleil";
    c.owner = "Guy Laliberté";
}