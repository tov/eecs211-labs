#include "lab3_funs.h"
#include <stdio.h>


int main(int argc, const char* argv[])
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
}
