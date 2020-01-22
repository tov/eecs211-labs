# For building CS 211 Lab 3

# C compiler options:
CFLAGS     = -std=c11 -pedantic -Wall
# Extra C compiler options for catching errors:
CFLAGS    += -fsanitize=address,undefined
# Linker options:
LDFLAGS   +=

# Plain C compiler command:
CC        ?= cc
# Command for compiling one C source file:
COMPILE.c  = $(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)
# Command for linking a C program:
LINK.c     = $(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

all: build/lab3 build/lab3_test

test: build/lab3_test
	build/lab3_test

build/lab3: build/src/lab3.o build/src/lab3_funs.o
	$(LINK.c)

build/lab3_test: build/src/lab3_funs.o build/test/lab3_test.o
	$(LINK.c)

build/%.o: %.c
	@mkdir -p "$$(dirname "$@")"
	$(COMPILE.c)

clean:
	rm -Rf build

# Targets that are not actually files we can build:
.PHONY: all test clean

# Dependencies:
build/src/lab3.o: src/lab3_funs.h
build/src/lab3_funs.o: src/lab3_funs.h
build/test/lab3_test.o: src/lab3_funs.h

# Ensure we have the correct C compiler version:
CSHOST = .northwestern.edu
ifeq ($(DEV211)$(CSHOST),$(findstring $(CSHOST),$(shell hostname)))
  $(error You need to run ‘dev’ first)
endif
