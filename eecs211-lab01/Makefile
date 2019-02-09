# For building EECS 211 Lab 1

CFLAGS     = -std=c11 -pedantic -Wall
# CFLAGS    += -fsanitize=address -fsanitize=undefined
LDFLAGS    =

all: build/hello

build/hello: build/hello.o
	cc -o $@ $^ $(CFLAGS) $(LDFLAGS)

build/%.o: src/%.c
	@mkdir -p build
	cc -o $@ -c $< $(CFLAGS)

build/:
	mkdir -p $@

clean:
	rm -Rf build

# Targets that are not actually files we can build:
.PHONY: all clean
