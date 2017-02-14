TEXS = $(wildcard eecs211-lab*.tex)
PDFS = $(TEXS:.tex=.pdf)
ZIPS = $(TEXS:.tex=.zip)

Publish: $(PDFS) $(ZIPS)
	echo index.html > $@
	ls $^ > $@

%.zip: %
	zip -r $@ $< -x '*/.idea/*' '*/cmake-debug-*'

# The tufte-handout class we use works with pdflatex, but not
# xelatex/lualatex.
%.pdf: %.tex eecs211-lab.sty
	mkdir -p build
	cp eecs211-lab.sty build
	( cd build; pdflatex -interaction=nonstopmode ../$< )
	cp build/$@ .

clean:
	git clean -fX

.PHONY: clean
