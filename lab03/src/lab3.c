#include "lab3_funs.h"
#include <stdio.h>

// The left shift operation `x << y` shifts the binary representation of
// `x` to the left by `y` places. For example:
//
//  - `1 << 5` (in binary: 0b00000001 << 5) == 32  (0b00100000 in binary)
//  - `5 << 2` (in binary: 0b00000101 << 2) == 20  (0b00010100 in binary)
//
#define BUF_SIZE (1 << 20)

int main(int argc, const char *argv[])
{
    // How to use str_chr:
    printf("'N' is found in \"hello NU\" at \"%s\"\n",
           str_chr("hello NU",'N'));

    // How to use is_prefix_of:
    printf("is_prefix_of(HELLO, HE) returns %s\n",
            is_prefix_of("HELLO", "HE") ? "true" : "false");
    printf("is_prefix_of(BYEBYE, BEE) returns %s\n",
            is_prefix_of("BYEBYE", "BEE") ? "true" : "false");

    // How you might use str_str:
    printf("str_str says that ME is here: %s\n",
            str_str("WELCOME INTO 211", "ME"));

    // Careful...
    char buffer[BUF_SIZE] = {0};

    if (argc == 4) {
        // How you might use interpolate:
        interpolate("Doing labs for {} {v} {^}", argv + 1, buffer);
        printf("interpolation result: %s\n", buffer);
    } else {
        fprintf(stderr, "unexpected number of arguments\n");
    }
}
