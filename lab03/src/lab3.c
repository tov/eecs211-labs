#include "lab3_funs.h"
#include <stdio.h>

int main(int argc, const char *argsv[] )
{
    // How to use str_chr:
    printf("%s\n", str_chr("hello NU",'N'));

    // How to use is_prefix_of:
    printf("HE in HELLO %d, BEE in BYEBYE %d\n",
            (int) is_prefix_of("HELLO", "HE"),
            (int) is_prefix_of("BEE", "BYEBYE"));

    // How you might use str_str:
    printf("%s\n", str_str("WELCOME INTO 211", "ME"));

    char buffer[1024] = {'\0'};

    if (argc == 4) {
        // How you might use interpolate:
        interpolate("Doing labs for {} {v} {^}", ++argsv, buffer);
        printf("interpolation result: %s\n", buffer);
    } else {
        fprintf(stderr, "unexpected number of arguments\n");
    }

    return 0;
}

