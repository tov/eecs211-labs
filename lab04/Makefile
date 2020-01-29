# For building CS 211 Lab 4

# C compiler options (language version & warnings):
CFLAGS     = -std=c11 -pedantic -Wall
# Extra C compiler options for debugging and catching errors:
CFLAGS    += -g -fsanitize=address,undefined -fno-omit-frame-pointer
# Linker options:
LDFLAGS   += -l211


# Plain C compiler command:
CC        ?= cc
# Command for compiling one C source file:
COMPILE.c  = $(CC) -c -o $@ $< $(CPPFLAGS) $(CFLAGS)
# Command for linking a C program:
LINK.c     = $(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)


TESTS = build/test_cons build/test_heap_string build/test_string_fun
ALL   = build/asan_example $(TESTS)

all: $(ALL)

test: $(TESTS)
	for i in $^; do \
	  echo "Running $$i:"; \
	  $$i; \
	  echo; \
	done

build/asan_example: build/src/asan_example.o
	$(LINK.c)

build/test_cons: build/test/test_cons.o build/src/cons.o
	$(LINK.c)

build/test_string_fun: build/test/test_string_fun.o \
                       build/src/string_fun.o \
                       build/src/heap_string.o \
		       build/src/ptr_string.o
	$(LINK.c)

build/test_heap_string: build/test/test_heap_string.o \
                        build/src/heap_string.o \
			build/src/ptr_string.o
	$(LINK.c)

build/%.o: %.c
	@mkdir -p "$$(dirname "$@")"
	$(COMPILE.c)

clean:
	rm -Rf build

# Targets that are not actually files we can build:
.PHONY: all test clean

# Dependencies:
build/src/ptr_string.o: src/ptr_string.h
build/src/heap_string.o: src/ptr_string.h src/heap_string.h
build/test/test_heap_string.o: src/ptr_string.h src/heap_string.h
build/src/string_fun.o: src/ptr_string.h src/heap_string.h src/string_fun.h
build/test/test_string_fun.o: src/ptr_string.h src/heap_string.h \
                              src/string_fun.h
build/test/test_cons.o: src/cons.h

# Ensure we have the correct C compiler version:
CSHOST = .northwestern.edu
ifeq ($(DEV211)$(CSHOST),$(findstring $(CSHOST),$(shell hostname)))
  $(error You need to run ‘dev’ first)
endif
