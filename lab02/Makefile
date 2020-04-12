# For building CS 211 Lab 2

CFLAGS     = -std=c11 -pedantic -Wall -fsanitize=address,undefined
LDFLAGS    =
CC        ?= cc

all: lab2

lab2: src/lab2.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

clean:
	rm -f lab2 src/*.o

# Targets that are not actually files we can build:
.PHONY: all clean

# Ensure we have the correct C compiler version:
CSHOST = .northwestern.edu
ifeq ($(DEV211)$(CSHOST),$(findstring $(CSHOST),$(shell hostname)))
  $(error You need to run ‘dev’ first)
endif
