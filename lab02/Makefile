# For building CS 211 Lab 2

### C compiler and flags
# The C compiler to use:
CC         ?= cc
# Extra options for catching bad stuff:
SANFLAGS    = -fsanitize=undefined,address
# Flags for compiling individual files:
CFLAGS      = -g -O1 -std=c11 -pedantic @.Wflags $(SANFLAGS)
# Flags for linking the final program:
LDFLAGS     = $(SANFLAGS)

all: lab

lab: src/lab.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

clean:
	rm -f lab src/*.o

# Targets that are not actually files we can build:
.PHONY: all clean
