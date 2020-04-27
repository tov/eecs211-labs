# For building CS 211 Lab 4

### C compiler and flags
# The C compiler to use:
CC         ?= cc
# Extra options for catching bad stuff:
SANFLAGS    = -fsanitize=undefined,address
# Flags for compiling individual files:
CFLAGS      = -std=c11 -pedantic @.Wflags $(SANFLAGS)
# Flags for linking the final program:
LDFLAGS     = -l211 $(SANFLAGS)


### Uncommenting the next line will enable debugging:
# CFLAGS     += -g


TESTS       = test_cons test_heap_string test_string_fun
EXES        = asan_example $(TESTS)

all: $(EXES)

test: $(TESTS)
	for i in $^; do \
	  echo "*** Running $$i: ***"; \
	  ./$$i; \
	  echo; \
	done

asan_example: src/asan_example.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

test_cons: test/test_cons.o src/cons.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

test_string_fun: test/test_string_fun.o src/string_fun.o \
                 src/heap_string.o src/ptr_string.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

test_heap_string: test/test_heap_string.o src/heap_string.o src/ptr_string.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

clean:
	$(RM) $(EXES) */*.o

# Targets that are not actually files we can build:
.PHONY: all test clean

# Dependencies:
src/heap_string.o: src/ptr_string.h src/heap_string.h
src/ptr_string.o: src/ptr_string.h
src/string_fun.o: src/ptr_string.h src/heap_string.h src/string_fun.h
test/test_cons.o: src/cons.h
test/test_heap_string.o: src/ptr_string.h src/heap_string.h
test/test_string_fun.o: src/ptr_string.h src/heap_string.h src/string_fun.h

# Ensure we have the correct C compiler version:
CSHOST = .northwestern.edu
ifeq ($(DEV211)$(CSHOST),$(findstring $(CSHOST),$(shell hostname)))
  $(error You need to run ‘dev’ first)
endif
