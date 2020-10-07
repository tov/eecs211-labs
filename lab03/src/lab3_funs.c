#include "lab3_funs.h"

#include <stddef.h>
#include <ctype.h>   // for tolower(3) and toupper(3)

const char *str_chr(const char *s, char c)
{
    while (*s) {
        if (c == *s) {
            return s;
        }

        ++s;
    }

    return NULL;
}

bool is_prefix_of(const char *haystack, const char *needle)
{
    while (*needle) {
        if (*haystack == 0 || *haystack != *needle) {
            return false;
        }

        ++needle;
        ++haystack;
    }

    return true;
}

const char *str_str(const char *haystack, const char *needle)
{
    while (*haystack) {
        if (is_prefix_of(haystack, needle)) {
            return haystack;
        }

        ++haystack;
    }

    return NULL;
}

enum format_type { TOUPPER, TOLOWER, LITERAL };

static bool concat_arg(char** buf, const char** arg, enum format_type ft)
{
    while (**arg) {
        switch (ft) {

        case TOUPPER:
            **buf = toupper(**arg);
            break;

        case TOLOWER:
            **buf = tolower(**arg);
            break;

        case LITERAL:
            **buf = **arg;
            break;

        }

        ++*buf;
        ++*arg;
    }

    // moves to the next argument
    ++*arg;

    return true;
}

void interpolate(const char *format, const char *args[], char *buffer)
{
    const char *group = format;
    const char *end   = format;
    const char *arg_it = *args;

    while ( (end = str_chr(end, '{')) ) {
        while (group < end) {
            *buffer++ = *group++;
        }

        if (is_prefix_of(end, "{^}")) {
            concat_arg(&buffer, &arg_it, TOUPPER);
            end += 3;
        } else if (is_prefix_of(end, "{v}")) {
            concat_arg(&buffer, &arg_it, TOLOWER);
            end += 3;
        } else if (is_prefix_of(end, "{}")) {
            concat_arg(&buffer, &arg_it, LITERAL);
            end += 2;
        } else {
            *buffer++ = *group++;
        }

        group = end;
    }

    *buffer = 0;
}
