#include "cons.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// This definition is visible only from within this file.
// test/test_cons.c cannot see it, but it can see in "cons.h" that this
// definition exists, and that `list_t` is a synonym for a pointer to
// this.
struct cons_pair
{
    int    car;
    list_t cdr;
};

// Defines the empty list as the null pointer.
list_t const empty = NULL;

list_t cons(int first, list_t rest)
{
    list_t result = malloc(sizeof *result);
    if (result == NULL) {
        // If malloc fails, we'll print an error message and exit.
        perror("cons");
        exit(1);
    }

    // Initialize and return
    result->car = first;
    result->cdr = rest;
    return result;
}

bool is_empty(list_t lst)
{
    return lst == NULL;
}

bool is_cons(list_t lst)
{
    return lst != NULL;
}

int first(list_t lst)
{
    // Checks our precondition unless -DNDEBUG is passed to cc.
    assert( lst );
    return lst->car;
}

list_t rest(list_t lst)
{
    assert( lst );
    return lst->cdr;
}

list_t uncons_one(list_t lst)
{
    if (!lst) return lst;

    list_t next = lst->cdr;
    free(lst);
    return next;

    // Why not this?:
    //
    //   free(lst);
    //   return lst->cdr;
}

void uncons_all(list_t lst)
{
    while (lst) lst = uncons_one(lst);
}

void uncons_all_111style(list_t lst)
{
    if (lst) {
        uncons_all_111style(lst->cdr);
        free(lst);
    }
}

list_t map(int (*f)(int), list_t lst)
{
    list_t result = empty;
    list_t* next = &result;

    while (lst) {
        *next = cons(f(lst->car), empty);
        next = &(*next)->cdr;
        lst = lst->cdr;
    }

    return result;
}

void for_each(void (*f)(int*), list_t lst)
{
    while (lst) {
        f(&lst->car);
        lst = lst->cdr;
    }
}

