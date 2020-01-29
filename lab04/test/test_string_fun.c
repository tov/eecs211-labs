#include "../src/string_fun.h"
#include <lib211.h>

#include <assert.h>
#include <stdlib.h>
#include <string.h>


// This is a C preprocessor macro. It defines ARRAYLEN(A)
// to be replaced by the icky thing to its right, so that we
// can avoid typing that icky things later.
#define ARRAYLEN(A) ((sizeof(A))/(sizeof(*(A))))


// Checks that `string_concat(s1, s2)` produces `expected`.
static void
check_string_concat(const char* s1, const char* s2, const char* expected)
{
    char* actual = string_concat(s1, s2);
    CHECK_STRING( actual, expected );
    free(actual);
}

// Checks that `strip_concat(input, n)` produces `expected`.
void check_strip_concat(const char* input[], size_t n, const char* expected)
{
    char* actual = strip_concat(input, n);
    CHECK_STRING( actual, expected );
    free(actual);
}


///
/// The actual tests
///

void string_concat_test(void)
{
    check_string_concat("hello,", " 211", "hello, 211");
    check_string_concat("", "abcd", "abcd");
    check_string_concat("xyzw", "", "xyzw");
    check_string_concat("", "", "");
}

void tiny_strip_concat_test(void)
{
    const char* input[] = { "// comment", "non" };
    check_strip_concat(input, ARRAYLEN(input), "non\n");
}

void strip_concat_test(void)
{
    const char* input[] = {
        "// the simplest C program",
        "int main()",
        "{",
        "    // optional:",
        "    return 0;",
        "}"
    };
    const char* expected = "int main()\n{\n    return 0;\n}\n";

    check_strip_concat(input, ARRAYLEN(input), expected);
}

int main()
{
    string_concat_test();
    tiny_strip_concat_test();
    strip_concat_test();
}
