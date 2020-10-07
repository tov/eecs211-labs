#include "lab3_funs.h"

#include <stddef.h>
#include <ctype.h>   // for tolower(3) and toupper(3)

const char *str_chr(const char *s, char c)
{
    while (*s) {
        if (c == *s) {
            return s;
        }
        s++;
    }

    return NULL;
}

bool is_prefix_of(const char *haystack, const char *needle)
{
    while (*needle) {
        if (*haystack == 0 || *haystack != *needle) {
            return false;
        }
        needle++;
        haystack++;
    }

    return true;
}

const char *str_str(const char *haystack, const char *needle)
{
    while (*haystack) {
        if(is_prefix_of(haystack, needle)) {
            return haystack;
        }
        haystack++;
    }
    return NULL;
}

static bool
concat_arg(char** buf, const char** arg, int format_case)
{
    while (*arg && **arg) {
        **buf = **arg;
        switch (format_case) {
            case 1:
                **buf = toupper(**buf);
                break;
            case 2:
                **buf = tolower(**buf);
                break;
        }
        (*buf)++;
        (*arg)++;
    }
    // moves to the next argument
    (*arg)++;
    return true;
}

void interpolate(const char *format, const char *args[], char *buffer)
{
    char* buf_it = buffer;
    const char *group = format;
    const char *end = format;
    const char *arg_it = *args;

    while ( (end = str_chr(end, '{')) ) {
       while (group < end) {
            *buf_it = *group;
            buf_it++;
            group++;
        }

        if (is_prefix_of(end, "{^}")) {
            if (!concat_arg(&buf_it, &arg_it, 1)) {
                break;
            }
            end += 3;

        } else if (is_prefix_of(end, "{v}")) {
            if (!concat_arg(&buf_it, &arg_it, 2)) {
                break;
            }
            end += 3;
        } else if (is_prefix_of(end, "{}")) {
            if (!concat_arg(&buf_it, &arg_it, 3)) {
                break;
            }
            end += 2;

        } else {
            *buf_it = *group;
            buf_it++;
            end++;
        }

        group = end;
    }

    *buf_it = 0;
}
