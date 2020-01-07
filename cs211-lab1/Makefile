# For building EECS 211 Lab 1

CFLAGS     = -std=c11 -pedantic -Wall
CFLAGS    += -fsanitize=address,undefined
LDFLAGS    =

all: build/hello

build/hello: build/hello.o
	cc -o $@ $^ $(CFLAGS) $(LDFLAGS)

build/%.o: src/%.c
	@mkdir -p build
	cc -o $@ -c $< $(CFLAGS)

clean:
	rm -Rf build

.PHONY: all clean
