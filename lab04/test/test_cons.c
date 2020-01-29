#include "../src/cons.h"

// Uncomment the following `#define` line to see what’s happening in the
// program. If `ENABLE_DEBUGF` is #defined above the #include <lib211.h>
// for your program then it defines `debugf` to be like `printf` for
// debugging; if `ENABLE_DEBUGF` isn’t #defined then `debugf` does
// nothing.

// #define ENABLE_DEBUGF

#include <lib211.h>

#include <assert.h>
#include <printf.h>
#include <stdint.h>

// Computes the length of a list. Recursive, which means it will “blow
// the stack” on a sufficiently long list.
size_t list_len_111style(list_t lst)
{
    return is_empty(lst)? 0 : 1 + list_len_111style(rest(lst));
}

// Computes the length of a list. Iterative, so uses only one stack
// frame regardless of list length.
size_t list_len(list_t lst)
{
    size_t count = 0;

    while (is_cons(lst)) {
        ++count;
        lst = rest(lst);
    }

    return count;
}

// Helper for recursive list printing function.
void print_list_111style_helper(list_t lst)
{
    if (is_cons(lst)) {
        printf("cons(%d, ", first(lst));
        print_list_111style_helper(rest(lst));
        printf(")");
    } else {
        printf("empty");
    }
}

// Prints a list. Recursive == small lists only.
void print_list_111style(list_t lst)
{
    print_list_111style_helper(lst);
    printf("\n");
}

// Prints a list. Iterative == space safe.
void print_list(list_t lst)
{
    size_t count = 0;

    while (is_cons(lst)) {
        printf("cons(%d, ", first(lst));
        lst = rest(lst);
        ++count;
    }

    printf("empty");

    while (count--) printf(")");

    printf("\n");
}

// Generates the list 0, 1, ..., (length - 1).
list_t iota(size_t length)
{
    list_t result = empty;
    while (length) result = cons(--length, result);
    return result;
}

// Tries length function `len_fun` on a list of length `n`.
void try_len(size_t (*lenf)(list_t), size_t n)
{
    debugf("Trying n = %zu: iota()...", n);
    list_t lst = iota(n);
    debugf(" len()...");
#ifdef ENABLE_DEBUGF
    size_t len = lenf(lst);
#endif
    debugf(" got %zu! uncons_all()... ", len);
    uncons_all(lst);
    debugf("done.\n");
}

// Little functions for passing to `map`:
static int add1(int z) { return z + 1; }
static int dbl(int z) { return z * 2; }

static void dblp(int* pz) { *pz *= 2; }

int main()
{
    print_list(empty);

    list_t my_list = cons(2, cons(3, cons(4, cons(5, empty))));
    print_list(my_list);
    print_list(rest(my_list));

    list_t doubled = map(dbl, my_list);
    print_list(doubled);
    for_each(dblp, doubled);
    print_list(doubled);

    list_t incred = map(add1, rest(doubled));

    uncons_all(doubled);
    uncons_all(my_list);

    print_list(incred);
    uncons_all(incred);

    // // Tries list_len_111style on lists of exponetially increasing
    // // length:
    // for (size_t i = 1; i <= SIZE_MAX / 2; i *= 2)
    //     try_len(list_len_111style, i);
}

