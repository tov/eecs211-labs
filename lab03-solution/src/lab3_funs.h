#pragma once

#include <stdbool.h>

// Find the first instance of c in s and return a pointer to that position in
// s. Return NULL if no instance exists.
const char* str_chr(const char* s, char c);

// Determine if needle is the prefix of haystack. The characters of needle
// must exactly match the initial characters of haystack. Return true or false.
bool is_prefix_of(const char* haystack, const char* needle);

// Find the first instance of needle in haystack and return a pointer to that
// position in haystack. Return NULL if no instance exists.
const char* str_str(const char *haystack, const char* needle);

/*
// Write the format string into buffer, placing values from args as specified
// by the format string. {} means place the next argument as-is. {^} means
// place the argument after converting it entirely to uppercase. {v} means
// place the argument after converting it entirely to lowercase. You may assume
// that the proper number of args exist and that the buffer is large enough to
// fit the resulting string. Be sure to place a zero character at the end of
// the string in buffer.
void interpolate(const char* format, const char* args[], char* buffer);
*/

