// need to make this work:
// #include "../lab3.h"

#include <assert.h>

char *str_chr(const char *s, char c);

void test_str_chr()
{
    const char* hello = "hello";
    assert( str_chr(hello, 'h') == hello );
    assert( str_chr(hello, 'e') == hello + 1 );
    assert( str_chr(hello, 'l') == hello + 2 );
    assert( str_chr(hello, 'o') == hello + 4 );
    assert( str_chr(hello, '!') == NULL );
}

int main()
{
}
