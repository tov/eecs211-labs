CFLAGS    = -std=c11 -pedantic -Wall
# CFLAGS    += -fsanitize=address -fsanitize=undefined
LDFLAGS   =

EXES      = build/test_cons
ALL       = $(EXES)

CC        = cc
LINK.c    = $(CC) -o $@ $(CFLAGS) $(LDFLAGS)
COMPILE.c = $(CC) -o $@ $(CFLAGS) -c

all: $(ALL)

test: build/test_cons
	@for prog in $^; do \
	    echo "*** Running $$prog ***"; \
	    $$prog; \
	done

build/test_cons: build/cons.o build/lib211.o build/test_cons.o
	$(LINK.c) $^

build/%.o: src/%.c
	@mkdir -p build
	$(COMPILE.c) $<

build/%.o: tests/%.c
	@mkdir -p build
	$(COMPILE.c) $<

clean:
	rm -Rf build

# Targets that are not actually files we can build:
.PHONY: all clean test

# Dependencies:
build/cons.o: src/cons.h
build/lib211.o: src/lib211.h
build/test_cons.o: src/cons.h src/lib211.h
