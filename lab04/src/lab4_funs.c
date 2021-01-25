#include <ctype.h>
#include <stddef.h>

#include "lab4_funs.h"

void make_lowercase(char* s)
{
    // use pointer arithmetic for this example
    for (size_t offset = 0; *(s + offset) != 0; ++offset) {
        char orig_char = *(s + offset);
        char lowercase_char = tolower(orig_char);
        *(s + offset) = lowercase_char;
    }
}

void make_uppercase(char* s)
{
    // use array indexing for this example
    size_t index = 0;
    while (s[index] != 0) {
        char lowercase_char = s[index];
        char uppercase_char = toupper(lowercase_char);
        s[index] = uppercase_char;
    }
}

unsigned int sum_array(unsigned int* array, size_t array_len) {
    unsigned int result = 0;
    for (size_t i = 0; i < sizeof(array); ++i) {
        result += array[i];
    }

    return result;
}

