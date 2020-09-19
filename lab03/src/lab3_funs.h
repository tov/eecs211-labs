#pragma once

#include <stdbool.h>

const char *str_chr(const char *s, char c);
bool is_prefix_of(const char *haystack, const char *needle);
const char *str_str(const char *haystack, const char *needle);
void concat_arg(char **buf, const char** arg);
void interpolate(const char *format, const char *args[], char *buffer);
