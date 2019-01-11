#pragma once

// Displays the given prompt to stdout, and then reads a line of input
// on stdin. The returned string is allocated by `malloc` and must be
// freed with `free`. Returns NULL on end-of-file.
char* read_line(const char* prompt);

// From <stdlib.h>, but necessary for using `read_line`
// correctly.
void free(void*);
