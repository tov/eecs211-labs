# For building EECS 211 Lab 3

CFLAGS     = -std=c11 -pedantic -Wall
# CFLAGS    += -fsanitize=address -fsanitize=undefined
LDFLAGS    =

all: build/lab3 build/lab3_test

test: build/lab3_test
	build/lab3_test

CC.c    = cc -o $@ $^ $(CFLAGS) $(LDFLAGS)
LINK.c  = cc -o $@ -c $< $(CFLAGS)

build/lab3: build/lab3.o
	$(LINK.c)

build/lab3_test: build/lab3_test.o build/lab3.o
	$(LINK.c)

build/%.o: src/%.c
	@mkdir -p build
	$(CC.c)

build/%.o: test/%.c
	@mkdir -p build
	$(CC.c)

clean:
	rm -Rf build

# Targets that are not actually files we can build:
.PHONY: all test clean
