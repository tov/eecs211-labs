#include "ptr_string.h"
#include <ctype.h>

// This is strlen(3) from <string.h>.
size_t count_chars(const char* s)
{
    size_t i = 0;
    while (s[i] != '\0') ++i;
    return i;
}

// Copies from '\0'-terminated C string src to dst, but UB if dst
// has insufficient capacity.
void copy_string_into(char* dst, const char* src)
{
    while ((*dst++ = *src++) != '\0')
    { }
}

// Converts a string to uppercase in place.
void str_toupper_inplace(char* s)
{
    for (size_t i = 0; s[i] != '\0'; ++i)
        s[i] = toupper(s[i]);
}

// Converts a string to uppercase while putting the result in
// a different buffer.
void str_toupper_into(char* dst, const char* src)
{
    while ((*dst++ = toupper(*src++)) != '\0')
    { }
}

