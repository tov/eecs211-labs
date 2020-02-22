# The default lab to build when running just `make`:
DEFAULT = lab06

TEXS    = $(wildcard lab*.tex)
PDFS    = $(TEXS:.tex=.pdf)
TEXOPTS = -interaction=nonstopmode

# Build just the lab PDF we're working on:
default: $(DEFAULT).pdf

# Build everything:
all: $(PDFS)

# To build a lab PDF, build it in the build/ directory and then
# copy it here:
%.pdf: build/%.pdf
	cp $< $@

# Build one lab PDF in the build directory:
build/%.pdf: build/%.tex build/%.cmd build/211lab.sty
	cd build && `cat $*.cmd` $(TEXOPTS) ../$<

# Copy LaTeX source files to the build directory:
build/%.tex: %.tex
	@mkdir -p build
	cp $< $@

# Copy LaTeX style files to the build directory:
build/%.sty: %.sty
	@mkdir -p build
	cp $< $@

# Figure out which version of LaTeX to use and save its
# name in a file:
build/%.cmd: %.tex
	@mkdir -p build
	@if fgrep -q tufte-handout $<; \
	  then echo pdflatex; \
	  else echo lualatex; \
	fi >| $@

# Delete all build products:
clean:
	$(RM) *.pdf
	$(RM) -R build

.PHONY: default all clean
