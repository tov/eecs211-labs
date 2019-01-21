# For building EECS 211 Lab 3

CFLAGS     = -std=c11 -pedantic -Wall
# CFLAGS    += -fsanitize=address -fsanitize=undefined
LDFLAGS    =

all: build/lab3 build/lab3_test

test: build/lab3_test
	build/lab3_test

LINK.c  = cc -o $@ $^ $(CFLAGS) $(LDFLAGS)
CC.c    = cc -o $@ -c $< $(CFLAGS)

build/lab3: src/lab3.c
	@mkdir -p build
	$(LINK.c)

build/lab3_test: src/lab3.c test/lab3_test.c
	@mkdir -p build
	$(LINK.c) -DUSE_TEST_MAIN

clean:
	rm -Rf build

# Targets that are not actually files we can build:
.PHONY: all test clean
