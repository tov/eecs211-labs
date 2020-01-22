# For building EECS 211 Lab 2

CFLAGS     = -std=c11 -pedantic -Wall
# CFLAGS    += -fsanitize=address -fsanitize=undefined
LDFLAGS    =

all: build/lab2

build/lab2: build/lab2.o
	cc -o $@ $^ $(CFLAGS) $(LDFLAGS)

build/%.o: src/%.c
	@mkdir -p build
	cc -o $@ -c $< $(CFLAGS)

clean:
	rm -Rf build

# Targets that are not actually files we can build:
.PHONY: all clean

# Ensure we have the correct C compiler version:
CSHOST = .northwestern.edu
ifeq ($(DEV211)$(CSHOST),$(findstring $(CSHOST),$(shell hostname)))
  $(error You need to run ‘dev’ first)
endif
