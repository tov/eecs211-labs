#include "lib211.h"

#include <stdio.h>
#include <stdlib.h>

#define READ_LINE_BUF_SIZE 80

static void* realloc_or_die(void* old, size_t size)
{
    void* longer = realloc(old, size);

    if (longer == NULL) {
        free(old);
        perror(NULL);
        exit(1);
    }

    return longer;
}

static char* just_read_line()
{
    int c = getchar();
    if (c == EOF) return NULL;

    size_t capacity = READ_LINE_BUF_SIZE;
    size_t size     = 0;

    char* buffer    = realloc_or_die(NULL, capacity);

    for (;;) {
        if (c == EOF || c == '\n') {
            buffer[size] = '\0';
            return buffer;
        } else {
            buffer[size++] = (char) c;
        }

        c = getchar();

        if (size + 1 > capacity) {
            capacity *= 2;
            buffer = realloc_or_die(buffer, capacity);
        }
    }
}

char* read_line(const char* prompt)
{
    if (prompt != NULL && prompt[0] != '\0') {
        printf("%s", prompt);
        fflush(stdout);
    }

    return just_read_line();
}
