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

struct animal
{
    double weight;
    unsigned int age;
    const char* type;
};

/*
 * Function declarations
 */

int sum_numbers(int);
void print_animal(struct animal);

/*
 * Function definitions
 */

void print_animal(struct animal a) {

    printf("My %s is %u years old and weighs %.3f lbs.\n",
           a.type, a.age, a.weight);

    if (a.age >= 10) {
        printf("This animal is old!\n");
    } else {
        printf("This animal is not that old\n");
    }
}

int main(void)
{
    struct apple delicious = { 0.3, "Red Delicious", "red" };
    struct animal pet = {40.2410, 5, "Dog"};
    int num = 100;

    printf("My %s apple is the color %s and weighs %g lbs.\n",
           delicious.variety, delicious.color, delicious.weight);

    // primitive way
    printf("My %s is %u years old and weighs %.3f lbs.\n",
           pet.type, pet.age, pet.weight);
    // or just use the function
    print_animal(pet);

    printf("Sum of numbers from 1 to %d = %d\n", 
           num, sum_numbers(num));
}

int sum_numbers(int num)
{
    // TODO: FIX ME
    int sum_while = 0;
    int sum_for = 0;

    // for loop implementation
    for (int i = 1; i <= num; i++) {
        sum_for += i;
    }

    // while loop implementation
    while (num) { 
        sum_while += num;
        num--;
    }

    return sum_for; // or sum_while
}
