TEXS = $(wildcard eecs211-lab*.tex)
PDFS = $(TEXS:.tex=.pdf)
ZIPS = $(TEXS:.tex=.zip)

Publish: $(PDFS) $(ZIPS)
	ls $^ > $@

%.zip: %
	zip -r $@ $<

# The tufte-handout class we use works with pdflatex, but not
# xelatex/lualatex.
%.pdf: %.tex eecs211-lab.sty
	pdflatex -interaction=nonstopmode $<

clean:
	git clean -fX

.PHONY: clean
