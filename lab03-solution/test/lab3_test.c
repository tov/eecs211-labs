#include "../src/lab3_funs.h"
#include <211.h>
#include <stddef.h>

static void test_str_chr(void)
{
    const char* hello = "hello";
    CHECK_POINTER( str_chr(hello, 'h'), hello );
    CHECK_POINTER( str_chr(hello, 'e'), hello + 1 );
    CHECK_POINTER( str_chr(hello, 'l'), hello + 2 );
    CHECK_POINTER( str_chr(hello, 'o'), hello + 4 );
    CHECK_POINTER( str_chr(hello, '!'), NULL );
}

int main(void)
{
    test_str_chr();
}
