#include <stdbool.h>
#include <stddef.h>
#include <ctype.h> // to get tolower and toupper 

const char *str_chr(const char *s, char c)
{
    while(*s && *s != c) s++;
    if (*s != c) return NULL;
    return s;
}

bool is_prefix_of(const char *haystack, const char *needle)
{
    while(*needle && *needle == *haystack) 
    {
        needle++;
        haystack++;
    }
    if (*needle) return true;
    return false;
}

const char *str_str(const char *haystack, const char *needle)
{
    while (*haystack)
    {
        if (is_prefix_of(haystack,needle)) 
            return haystack;
        haystack++;
    }
    return NULL;
}

void interpolate(const char *format, const char *args[], char *buffer)
{
    enum Modifier {normal,uppercase, lowercase} modifier = normal;
    int argc = 0;
    while (*format)
    {
        if (*format == '{')
        {
            modifier = normal;
            format++;
            while (*format != '}')
            {
                switch (*format++)
                {
                case '^':
                    {
                        modifier = uppercase;
                        break;
                    }
                case 'v':
                    {
                        modifier = lowercase;
                        break;
                    }
                default:
                    {
                        // ignore
                    }
                }
            }
            while (*args[argc])
            {
                switch (modifier)
                {
                case normal:
                    {
                        *buffer = *args[argc];
                        break;
                    }
                case uppercase:
                    {
                        *buffer = toupper(*args[argc]);
                        break;
                    }
                case lowercase:
                    {
                        *buffer = tolower(*args[argc]);
                    }
                }
                args[argc]++;
                buffer++;
            }
            argc++;
        }
        else
        {
            *buffer = *format;
            buffer++;
        }
        format++;
    }
    *buffer = *format;
}

