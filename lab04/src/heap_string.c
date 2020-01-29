#include "heap_string.h"
#include "ptr_string.h"

// For malloc():
#include <stdlib.h>

// Allocates a new copy of the given string on the heap. The result must
// be freed. Returns NULL if it can't allocate memory.
char* string_clone(const char* s)
{
    size_t count = count_chars(s);
    char* result = malloc(count + 1);
    if (result != NULL) copy_string_into(result, s);
    return result;
}

// Allocates a new, UPPERCASE copy of the given string on the heap. The
// result must be freed. Returns NULL if it can't allocate memory.
char* str_toupper_clone(const char* s)
{
    size_t count = count_chars(s);
    char* result = malloc(count + 1);
    if (result != NULL) str_toupper_into(result, s);
    return result;
}

