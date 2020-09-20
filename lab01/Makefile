# For building CS 211 Lab 1

### C compiler and flags
# The C compiler to use:
CC         ?= cc
# Extra options for catching bad stuff:
SANFLAGS   += -fsanitize=undefined,address
# Flags for compiling individual files:
CFLAGS     += -g -O1 -std=c11 -pedantic-errors @.Wflags $(SANFLAGS)
# Flags for linking the final program:
LDFLAGS    += $(SANFLAGS) @.Wflags

all: hello

hello: src/hello.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

clean:
	rm -f hello src/*.o

# Targets that are not actually files we can build:
.PHONY: all clean
