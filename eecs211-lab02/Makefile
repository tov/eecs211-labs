# For building EECS 211 Lab 2

CFLAGS     = -std=c11 -pedantic -Wall
# CFLAGS    += -fsanitize=address -fsanitize=undefined

all: test build/lab2

test: build/lab2_test
	build/lab2_test

build/lab2: build/lab2.o build/lib211.o
	cc -o $@ $^ $(CFLAGS)

build/lab2_test: build/lab2_test.o
	cc -o $@ $^ $(CFLAGS)

build/%.o: src/%.c | build/
	cc -o $@ -c $< $(CFLAGS)

build/%.o: test/%.c | build/
	cc -o $@ -c $< $(CFLAGS)

build/:
	mkdir -p $@

clean:
	rm -Rf build

# Targets that are not actually files we can build:
.PHONY: all test clean

# Dependencies:
build/lab2.o: src/lib211.h
build/lib211.o: src/lib211.h
