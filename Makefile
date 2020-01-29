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
	fgrep -q tufte-handout $< && LA=pdf || LA=lua; \
	cd build && $${LA}latex -interaction=nonstopmode ../$<
	cp build/$@ .

include ../../lib/Makefile
