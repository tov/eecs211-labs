#include<stdio.h>
#define NORMAL 0
#define UPPERCASE  1
#define LOWERCASE  2

char *str_chr(const char *s, char c)
{
	while(*s && *s!=c) s++;
	if (*s!=c) return NULL;
	return s;
}


int is_prefix_of(const char* haystack, const char* needle)
{
	while(*needle && *needle==*haystack) 
	{
		needle++;
		haystack++;
	}
	if (*needle) return 0;
	return 1;	
}

char *str_str(const char *haystack, const char *needle)
{
	while (*haystack)
	{
		if (is_prefix_of(haystack,needle)) 
			return haystack;
		haystack++;
	}
	return NULL;
}

char to_upper(char s)
{
	if (s>='a' && s<='z')
		return 'A'+(s-'a');
	return s;
}

char to_lower(char s)
{
	if (s>='A' && s<='Z')
		return 'a'+(s-'A');
	return s;
}


char* interpolate(const char* format, const char* args[], char * buffer)
{
	int modifier=NORMAL;
	int argc=0;
	while (*format)
	{
		if (*format == '{')
		{
			format++;
			while (*format!='}')
			{
				switch (*format++)
				{
					case '^':
					{
						modifier=UPPERCASE;
						break;
					}
					case 'v':
					{
						modifier=LOWERCASE;
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
					case NORMAL:
					{
						*buffer=*args[argc];
					}
					case UPPERCASE:
					{
						*buffer=to_upper(*args[argc]);
					}
					case LOWERCASE:
					{
						*buffer = to_lower(*args[argc]);
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
	return buffer;
}
// Your new struct goes here


// Your new function goes here

#ifndef USE_TEST_MAIN

int main(){
    const char *args[3]={"211","IS","great"};
    printf(str_chr("hello NU\n",' '));
    printf("HE in HELLO %d, BEE in BYEBYE %d\n",is_prefix_of("HELLO","HE"),is_prefix_of("BEE","BYEBYE"));
    printf(str_str("WELCOME INTO 211\n","ME"));
    char buffer[255];
    printf(interpolate("Doing labs for {} {v} {^}",args,buffer));
    return 0;
}

#endif
