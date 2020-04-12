# The default lab to build when running just `make`:
DEFAULT = lab02

TEXS    = $(wildcard lab*.tex)
PDFS    = $(TEXS:.tex=.pdf)
TEXOPTS = -interaction=errorstopmode

# Build just the lab PDF we're working on:
default: $(DEFAULT).pdf

hard: $(DEFAULT).pdf
	open $<

# Build everything:
all: $(PDFS)

# Update 211common.sty:
211common.sty: ../../lib/211common.sty
	cp $< $@

# To build a lab PDF, build it in the build/ directory and then
# copy it here:
%.pdf: build/%.pdf
	cp $< $@

# Build one lab PDF in the build directory:
build/%.pdf: %.tex build/%.cmd 211lab.sty 211common.sty
	`cat build/$*.cmd` $< </dev/null

# Figure out which version of LaTeX to use and save its
# name in a file:
build/%.cmd: %.tex Makefile
	@mkdir -p build
	@if fgrep -q tufte-handout $<; \
	  then printf pdflatex; \
	  else printf lualatex; \
	fi >| $@
	@printf " $(TEXOPTS)" >> $@
	@printf " --output-directory=`pwd`/build" >> $@

# Delete all build products:
clean:
	$(RM) *.pdf
	$(RM) -R build

.PHONY: default all clean
