#include <stdio.h>

//
// Struct definitions
//

struct apple
{
    double weight;
    char*  variety;
    char*  color;
};


//
// Function declarations
//

int sum_numbers(int);


//
// Function definitions
//

int main(void)
{
    struct apple delicious = { 0.3, "Red Delicious", "red" };

    printf("My %s apple is the color %s and weighs %g lbs.\n",
           delicious.variety, delicious.color, delicious.weight);
}

int sum_numbers(int num)
{
    // TODO: FIX ME
    return -1;
}
