# For building CS 211 Lab 3

### C compiler and flags
# The C compiler to use:
CC         ?= cc
# Extra options for catching bad stuff:
SANFLAGS   += -fsanitize=undefined,address
# Flags for compiling individual files:
CFLAGS     += -g -O0 -std=c11 -pedantic @.Wflags $(SANFLAGS)
# Flags for linking the final program:
LDFLAGS    += -l211 $(SANFLAGS)

all: lab3 lab3_test

test: lab3_test
	./$<

lab3: src/lab3.o src/lab3_funs.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

lab3_test: src/lab3_funs.o test/lab3_test.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

# Dependencies:
# (All three object files depend on the header.)
src/lab3.o src/lab3_funs.o test/lab3_test.o: src/lab3_funs.h

clean:
	$(RM) lab3 lab3_test */*.o

# Targets that are not actually files we can build:
.PHONY: all test clean
