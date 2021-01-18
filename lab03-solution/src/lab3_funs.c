#include "lab3_funs.h"

#include <stddef.h>
#include <ctype.h>   // for tolower(3) and toupper(3)

const char* str_chr(const char* s, char c)
{
    int index = 0;
    while (s[index] != 0) {
        if (s[index] == c) {
            return &s[index];
        }
        index++;
    }

    return NULL;
}

bool is_prefix_of(const char* haystack, const char* needle)
{
    int index = 0;
    while (needle[index] != 0) {
        if (haystack[index] != needle[index]) {
            return false;
        }
        index++;
    }
    return true;
}

const char* str_str(const char* haystack, const char* needle)
{
    int index = 0;
    while (haystack[index] != 0) {
        if (is_prefix_of(&haystack[index], needle)) {
            return &haystack[index];
        }
        index++;
    }
    return NULL;
}

/*
 * BRG: Wow this is a pain. I'm cutting this. The lab doens't need to be this
 * much work with the homework covering strings anyways.
void interpolate(const char* format, const char* args[], char* buffer)
{
    int format_index = 0;
    int buf_index = 0;
    int arg_index = 0;
    while (format[format_index] != 0) {
        if (is_prefix_of(&format[format_index], "{}")) {
            int str_index = 0;
            while (args[arg_index][str_index] != 0) {

            }
            index += 2;
        } else if (is_prefix_of(&format[format_index], "{^}")) {

        } else if (is_prefix_of(&format[format_index], "{v}")) {

        } else {
            buffer[buf_index] = format[format_index];
            format_index++;
            buf_index++;
        }
    }
}
*/

