# For building CS 211 Lab 4

### C compiler and flags
# The C compiler to use:
CC         ?= cc
# Extra options for catching bad stuff:
SANFLAGS   += -fsanitize=undefined,address
# Flags for compiling individual files:
CFLAGS     += -g -O1 -std=c11 -pedantic @.Wflags $(SANFLAGS)
# Flags for linking the final program:
LDFLAGS    += -l211 $(SANFLAGS)

all: infinite broken

infinite: src/infinite.o src/lab4_funs.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

broken: src/broken.o src/lab4_funs.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

# Dependencies:
# (All three object files depend on the header.)
src/infinite.o src/broken.o src/lab4_funs.o: src/lab4_funs.h

clean:
	$(RM) infinite broken */*.o

# Targets that are not actually files we can build:
.PHONY: all clean
