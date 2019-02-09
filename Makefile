TEXS = $(wildcard eecs211-lab*.tex)
PDFS = $(TEXS:.tex=.pdf)
ZIPS = $(TEXS:.tex=.zip)
TGZS = $(TEXS:.tex=.tgz)

Publish: $(PDFS) $(ZIPS) $(TGZS)
	echo index.html > $@
	ls $^ > $@

# The tufte-handout class we use works with pdflatex, but not
# xelatex/lualatex.
%.pdf: %.tex build/eecs211-lab.sty
	@mkdir -p build
	( cd build; pdflatex -interaction=nonstopmode ../$< )
	cp build/$@ .

include ../../lib/Makefile
