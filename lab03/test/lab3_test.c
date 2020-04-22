#include "../src/lab3_funs.h"

#include <assert.h>
#include <stddef.h>             // for NULL

void test_str_chr()
{
    const char* hello = "hello";
    assert( str_chr(hello, 'h') == hello );
    assert( str_chr(hello, 'e') == hello + 1 );
    assert( str_chr(hello, 'l') == hello + 2 );
    assert( str_chr(hello, 'o') == hello + 4 );
    assert( str_chr(hello, '!') == NULL );
}

int main(void)
{
    test_str_chr();
}
