#pragma once

#include <stdbool.h>

// Reads a line of input on stdin. The returned string is allocated by
// `malloc` and must be freed with `free`. Returns NULL on end-of-file
// or out-of-memory.
char* read_line(void);

// Like `read_line`, but prints a prompt and flushes it to ensure that
// it's displayed immediately even if it doesn't end with a newline. The
// arguments should be the same as for printf(1).
char* prompt_line(const char* format, ...)
    __attribute__((format(printf, 1, 2)));

// From <stdlib.h>, but necessary for using `read_line` and
// `prompt_line` correctly.
void free(void*);

// Prints a debugging message only if the debug state is currently true.
// The arguments are as for printf(1). Adjust the debug state with
// `set_debug_state`.
void really_debugf(const char* format, ...)
    __attribute__((format(printf, 1, 2)));

#ifdef ENABLE_DEBUGF
#   define  debugf        really_debugf
#else
#   define  debugf(...)   do {} while (false)
#endif
