#include <stdio.h>

/*
 * Struct definitions
 */

struct apple
{
    double weight;
    const char* variety;
    const char* color;
};


/*
 * Function definitions
 */

int main(void)
{
    struct apple delicious = { 0.3, "Red Delicious", "red" };

    printf("My %s apple is the color %s and weighs %g lbs.\n",
           delicious.variety, delicious.color, delicious.weight);

    return 0;
}

