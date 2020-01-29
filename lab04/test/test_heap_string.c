#include "../src/heap_string.h"
#include <lib211.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void test_str_toupper_clone(void)
{
    const char original[] = "Heap allocation!",
               expected[] = "HEAP ALLOCATION!";

    char* clone = str_toupper_clone(original);
    CHECK_STRING( clone, expected );

    free(clone);
}

int main()
{
    test_str_toupper_clone();
}

