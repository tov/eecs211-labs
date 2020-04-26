# The default lab to build when running just `make`:
DEFAULT = lab03

TEXS      = $(wildcard lab*.tex)
PDFS      = $(TEXS:.tex=.pdf)
STYS      = 211lang.sty 211common.sty 211lab.sty
STY_DEPS  = $(STYS:%=latex/%)
TEXOPTS   = -output-directory=build -interaction=errorstopmode
TEXINPUTS = .:./latex:

# Build just the lab PDF we're working on:
default: $(DEFAULT).pdf

hard: $(DEFAULT).pdf
	open $<

# Build everything:
all: $(PDFS)

# To build a lab PDF, build it in the build/ directory and then
# copy it here:
%.pdf: build/%.pdf
	cp $< $@

# Build one lab PDF in the build directory:
build/%.pdf: build/%.cmd $(STY_DEPS)
	sh $<

# Figure out which version of LaTeX to use and save its
# name in a file:
build/%.cmd: %.tex Makefile | build
	@(                                                 \
	    if fgrep -q tufte-handout $<;                  \
	        then LATEX=pdflatex;                       \
	        else LATEX=lualatex;                       \
	    fi;                                            \
	    printf 'TEXINPUTS="%s" %s %s $< </dev/null\n'  \
	           "$(TEXINPUTS)" "$$LATEX" "$(TEXOPTS)";  \
	) > $@

build:
	mkdir -p $@

# Delete all build products:
clean:
	$(RM) -R build *.pdf

.PHONY: default hard all clean
