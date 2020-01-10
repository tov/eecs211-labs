TEXS = $(wildcard lab*.tex)
PDFS = $(TEXS:.tex=.pdf)
ZIPS = $(TEXS:.tex=.zip)
TGZS = $(TEXS:.tex=.tgz)

PUBLISH = $(PDFS) $(ZIPS) $(TGZS)

Publish: Publish.include $(PUBLISH)
	cp $< $@
	ls $(PUBLISH) >> $@

hard: Publish

# The tufte-handout class we use works with pdflatex, but not
# xelatex/lualatex.
%.pdf: %.tex build/211lab.sty
	@mkdir -p build
	( cd build; pdflatex -interaction=nonstopmode ../$< )
	cp build/$@ .

include ../../lib/Makefile
