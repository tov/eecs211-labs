#include "lab3_funs.h"
#include <stdio.h>

int main(int argc, const char *argsv[] )
{
    printf("%s\n", str_chr("hello NU",'N'));
    printf("HE in HELLO %d, BEE in BYEBYE %d\n",
            (int) is_prefix_of("HELLO", "HE"),
            (int) is_prefix_of("BEE", "BYEBYE"));
    printf("%s\n", str_str("WELCOME INTO 211", "ME"));

    char buffer[] = "----------------------------------------------------"
                    "---------\n";

    if (argc == 4) {
        printf("interpolation result:%s\n",
                interpolate("Doing labs for {} {v} {^}",
                ++argsv,
                buffer));
    } else {
        fprintf(stderr, "unexpected number of arguments\n");
    }

    return 0;
}

