#include <stdio.h>

#include "lab4_funs.h"

int main(int argc, const char* argv[])
{
    // Create two character arrays to modify in-place
    char test_string1[] = "This is a test string";
    char test_string2[] = "This is a test string";

    // Lowercase one string and uppercase the other
    make_lowercase(test_string1);
    make_uppercase(test_string2);

    // Print results
    printf("After lowercasing, string has become \"%s\"\n", test_string1);
    printf("After uppercasing, string has become \"%s\"\n", test_string2);
}

