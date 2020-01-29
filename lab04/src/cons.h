/*
 * Linked lists API.
 *
 * In particular, these are immutable linked lists of `int`s. They are
 * heap allocated using the `cons` function and must be explicitly freed
 * using either of the `uncons_one` or `uncons_all` functions.
 */

#pragma once

#include <stdbool.h>

// This is a declaration of `struct cons_pair` as an “incomplete type.”
// This means that we are telling C that the type exists, but we aren’t
// telling it what the definition of the type is. What is it good for?
// Well, you can’t have a variable with an incomplete type because
// without the definition C doesn’t know it size. But you *can* have a
// pointer to an incomplete type...
struct cons_pair;

// A pointer to an incomplete type is how you do an abstract type in C.
// Whoever #includes this file will know that some `struct cons_pair`
// exists, but they won’t know its size or its fields. So they can’t
// create one! But they can still access one if given a pointer to it.
typedef struct cons_pair* list_t;

// This declares a variable `empty` without defining it. It tells
// #includers of this file that some .c file will define it (and in fact
// cons.c does), but does not actually do the defining. Because if a
// header defines a constant, that causes every .c file that includes it
// to define that constant, and you aren’t allowed to have multiple
// definitions of the same thing.
extern const list_t empty;

// Constructs a new list from a first `int` element and remaining list.
// The client is responsible for freeing the resulting list using either
// `uncons_one` or `uncons_all` (below).
//
// Additionally, this function *takes ownership* of `rest`, in the sense
// that the client is no longer responsible for freeing `rest`, and in
// fact is not allowed to.
//
// ERRORS: exits if memory cannot be allocated.
list_t cons(int first, list_t rest);

// Determines whether the given list is the empty list or the result of
// a call to cons.
bool is_empty(list_t lst), is_cons(list_t lst);

// Returns the first element of list `lst`.
//
// PRECONDITION (asserted): is_cons(lst)
int first(list_t lst);

// *Borrows* the rest of list `lst`. Borrowing means that you must not
// free the list_t that is returned by this function, as it will be
// someone else’s responsibility to free later.
//
// PRECONDITION (asserted): is_cons(lst)
list_t rest(list_t lst);

// Takes ownership of `lst`, frees the first link, and returns ownership
// of the rest. If given `empty`, returns `empty`.
//
// This means that after this is called, neither the caller nor anyone
// else may use `lst` again (nor free it again). However, if the
// result is not `empty` then the caller becomes responsible for freeing
// the result.
list_t uncons_one(list_t lst);

// Frees `lst` and all the memory it points to. This means it takes
// ownership of `lst`, and it is an error to access `lst` (or free it
// again) after calling this function.
void uncons_all(list_t lst);

// Recursive version of `uncons_all`. Not a great idea.
void uncons_all_111style(list_t lst);

// Maps function `f` over the elements of `lst`, returning a new
// list_t of the same length. Borrows `lst`, and the caller takes
// ownership of the result.
list_t map(int (*f)(int), list_t lst);

// Applies function `f` to the pointer to each element of the list.
// This is like `map`, but lets you modify the list in-place.
void for_each(void (*f)(int*), list_t lst);

