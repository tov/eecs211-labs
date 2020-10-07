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

static void copy_toupper(char** bufp, const char* arg)
{
    while (*arg) {
        **bufp = toupper(*arg);
        ++*bufp;
        ++arg;
    }
}

static void copy_tolower(char** bufp, const char* arg)
{
    while (*arg) {
        // Does the same thing as in copy_toupper:
        *(*bufp)++ = tolower(*arg++);
    }
}

static void copy_literal(char** bufp, const char* arg)
{
    while (*arg) {
        *(*bufp)++ = *arg++;
    }
}

void interpolate(const char *format, const char *args[], char *buffer)
{
    while (*format) {
        if (is_prefix_of(format, "{^}")) {
            format += 3;
            copy_toupper(&buffer, *args++);
        } else if (is_prefix_of(format, "{v}")) {
            format += 3;
            copy_tolower(&buffer, *args++);
        } else if (is_prefix_of(format, "{}")) {
            format += 2;
            copy_literal(&buffer, *args++);
        } else {
            *buffer++ = *format++;
        }
    }

    *buffer = 0;
}
