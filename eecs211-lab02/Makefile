# For building EECS 211 Lab 2

CFLAGS     = -std=c11 -pedantic -Wall
# CFLAGS    += -fsanitize=address -fsanitize=undefined
LDFLAGS    =

all: test build/lab2

test: build/lab2_test
	build/lab2_test

build/lab2: build/lab2.o
	cc -o $@ $^ $(CFLAGS) $(LDFLAGS)

build/lab2_test: build/lab2_test.o
	cc -o $@ $^ $(CFLAGS) $(LDFLAGS)

build/%.o: src/%.c
	@mkdir -p build
	cc -o $@ -c $< $(CFLAGS)

build/%.o: test/%.c
	@mkdir -p build
	cc -o $@ -c $< $(CFLAGS)

clean:
	rm -Rf build

# Targets that are not actually files we can build:
.PHONY: all test clean
