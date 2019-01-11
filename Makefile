TEXS = $(wildcard eecs211-lab*.tex)
PDFS = $(TEXS:.tex=.pdf)
ZIPS = $(TEXS:.tex=.zip)

Publish: $(PDFS) $(ZIPS)
	echo index.html > $@
	ls $^ > $@

%.zip: %
	zip -r $@ $< \
	  -x '*/.idea/*' '*/build/*' '*/cmake-build-*/*' '*/.*.swp'

# The tufte-handout class we use works with pdflatex, but not
# xelatex/lualatex.
%.pdf: %.tex build/eecs211-lab.sty | build/
	( cd build; pdflatex -interaction=nonstopmode ../$< )
	cp build/$@ .

build/%: % | build/
	cp $< $@

build/:
	mkdir -p $@

clean:
	git clean -xf

.PHONY: clean
