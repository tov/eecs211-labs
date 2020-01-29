// See .c file for purpose statements.
#pragma once

// For size_t:
#include <stddef.h>

size_t count_chars(const char* s);

void copy_string_into(char* dst, const char* src);

void str_toupper_inplace(char* s);

void str_toupper_into(char* dst, const char* src);
