#include <stdio.h>

//
// Struct definitions
//

struct Apple
{
    double weight;
    char*  variety;
    char*  color;
};

//
// Function declarations
//

int some_numbers(int);

//
// Function definition
//

int main()
{
    struct Apple delicious = { 0.3, "Red Delicious", "red" };
    printf("My %s apple is the color %s and weighs %f lbs.\n",
            delicious.weight, delicious.variety, delicious.color);
}

int some_numbers(int num)
{
    // TODO;
    return -1;
}
