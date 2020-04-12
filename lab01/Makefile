# For building CS 211 Lab 1

CFLAGS     = -std=c11 -pedantic -Wall -fsanitize=address,undefined
LDFLAGS    =
CC        ?= cc

all: hello

hello: src/hello.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)

clean:
	rm -f hello src/*.o

# Targets that are not actually files we can build:
.PHONY: all clean

# Ensure we have the correct C compiler version:
CSHOST = .northwestern.edu
ifeq ($(DEV211)$(CSHOST),$(findstring $(CSHOST),$(shell hostname)))
  $(error You need to run ‘dev’ first)
endif
