#include "cons.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

// LAB 4 CODE HERE:

int sum_list(list_t lst)
{
    int result = 0;
    while (is_cons(lst))
    {
        result += first(lst);
        lst = rest(lst);
    }
    return result;
}

void append(list_t lst, int new_car)
{
    list_t to_append = cons(new_car, empty);
    while (is_cons(lst)) lst = rest(lst);
    (*lst).cdr = to_append; // == lst->cdr
}


list_t copy(list_t lst)
{
    list_t clone = empty;
    list_t* temp = &clone;

    while (is_cons(lst)) {
        *temp = cons(first(lst), empty);
        // Which to use: (either way need &, i.e. can't use rest())
        // (*temp)->cdr == (**temp).cdr
        temp = &(**temp).cdr;
        lst = rest(lst);
    }

    return clone;
}

list_t map(int (*f)(int), list_t lst)
{
    list_t result = empty;
    list_t* temp = &result;

    while (is_cons(lst)) {
        *temp = cons(f(first(lst)), empty);
        temp = &(**temp).cdr;
        lst = rest(lst);
    }

    return result;
}

list_t filter(bool (*keep)(int), list_t lst)
{
    list_t result = empty;
    list_t* temp = &result;

    while (is_cons(lst)) {
        if (keep(first(lst))) {
            *temp = cons(first(lst), empty);
            temp = &(**temp).cdr;
        }
        lst = rest(lst);
    }

    return result;
}
