#include <stdbool.h>
#include<stdio.h>
#include<ctype.h> //to get tolower and toupper 

const char *str_chr(const char *s, char c)
{
    while(*s && *s != c) s++;
    if (*s != c) return NULL;
    return s;
}

bool is_prefix_of(const char* haystack, const char* needle)
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

char* interpolate(const char* format, const char* args[], char * buffer)
{
    enum Modifier {normal,uppercase, lowercase} modifier = normal;
    int argc = 0;
    char *start = buffer;
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
                        return NULL;
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
    return start;
}

int main(int argc, const char *argsv[] )
{
    printf("%s\n",str_chr("hello NU",'N'));
    printf("HE in HELLO %d, BEE in BYEBYE %d\n",is_prefix_of("HELLO","HE"),is_prefix_of("BEE","BYEBYE"));
    printf("%s\n",str_str("WELCOME INTO 211","ME"));
    char buffer[] = "-------------------------------------------------------------\n";
	if (argc == 4)
	{
		printf("interpolation result:%s\n",interpolate("Doing labs for {} {v} {^}",++argsv,buffer));
	}
	else
	{
		fprintf(stderr, "unexpected number of arguments\n");
	}
    return 0;
}

