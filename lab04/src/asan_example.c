#include <stdio.h>
#include <stdlib.h>

// Allocate and initialize the array.
int* allocate_it(size_t size)
{
    int* array = malloc(size * sizeof array[0]);
    if (!array) {
        return NULL;
    }

    for (size_t i = 0; i < size; ++i) {
        array[i] = 10 * i;
    }

    return array;
}

void print_one(const int* array, size_t index)
{
    printf("array[%zu] is %d\n", index, array[index]);
}

// Print the values at the requested indices.
void print_all(const int* array, char* indices[], size_t n_indices)
{
    for (size_t i = 0; i < n_indices; ++i) {
        size_t index = atol(indices[i]);
        print_one(array, index);
    }
}

int main(int argc, char* argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s SIZE INDICES...\n", argv[0]);
        return 1;
    }

    size_t size = atol(argv[1]);
    int* array = allocate_it(size);
    if (!array) {
        perror(argv[0]);
        return 2;
    }

    print_all(array, argv + 2, argc - 2);

    free(array);
}
