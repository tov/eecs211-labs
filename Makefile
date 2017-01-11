TEXS = $(wildcard eecs211-lab*.tex)
PDFS = $(TEXS:.tex=.pdf)

all: $(PDFS)

Publish: $(PDFS) $(ZIPS)
	ls $^ > $@

%.zip: %
	zip -r $@ $<

# The tufte-handout class we use works with pdflatex, but not
# xelatex/lualatex.
%.pdf: %.tex
	pdflatex -interaction=nonstopmode $<

latex-cleanup:
	rm -f eecs211-lab*.log eecs211-lab*.aux eecs211-lab*.synctex.gz

clean:
	rm -f eecs211-lab*.zip eecs211-lab*.pdf

.PHONY: latex-cleanup clean
