# The default lab to build when running just `make`:
DEFAULT   = lab05

TEXS     ?= $(wildcard lab*.tex)
LAB_DIRS ?= $(wildcard lab??)
STYS      = 211base.sty 211lang.sty 211common.sty 211lab.sty

TEX_DIR   = latex
BUILD_DIR = build
DIST_DIR  = dist
DEP_DIR   = $(BUILD_DIR)/depend

TEXINPUTS = .:./$(TEX_DIR):
TEXOPTS   = -output-directory=$(BUILD_DIR) \
            -interaction=errorstopmode

PDFS      = $(TEXS:.tex=.pdf)
STY_DEPS  = $(STYS:%=$(TEX_DIR)/%)
LAB_DEPS  = $(LAB_DIRS:%=$(DEP_DIR)/%.d)

# Build just the lab PDF we're working on:
pdf: $(DEFAULT).pdf

# Build all PDFs:
pdfs: $(PDFS)

# Build and open:
hard: $(DEFAULT).pdf
	open $<

# Build archives for distribution
zip: $(DEFAULT).zip
tgz: $(DEFAULT).tgz

thisclean: $(DEFAULT).clean

%.clean:
	$(RM) -R $(DIST_DIR)/$*
	$(RM) $*.zip $*.pdf $*.tgz

# To build a lab PDF, build it in the $(BUILD_DIR)/ directory and then
# copy it here:
%.pdf: $(BUILD_DIR)/%.pdf
	cp $< $@

# Build one lab PDF in the $(BUILD_DIR) directory:
$(BUILD_DIR)/%.pdf: $(BUILD_DIR)/%.cmd $(STY_DEPS)
	sh $<

%.zip: $(DIST_DIR)/%
	cd $(DIST_DIR) && zip -r ../$@ $*

%.tgz: $(DIST_DIR)/%
	cd $(DIST_DIR) && tar -czvf ../$@ $*

QUIET_GIT  ?= --quiet
FOR_SUBS    = git -C dot-cs211 submodule $(QUIET_GIT) foreach
STASH_CMD   = git stash push $(QUIET_GIT) --all --message="for make $@"
UNSTASH_CMD = git stash pop $(QUIET_GIT)
STS         = something-to-stash
FIND_DEPS   = ( cd $(@D) && \
                find $(@F) | \
                sed 's@ @\\&@g; h; s@$$@:@; p; g; s@^@$@: @' )

$(DIST_DIR)/%: | $(DEP_DIR) $(DIST_DIR)
	$(RM) -R $@
	@$(FOR_SUBS) touch $(STS) && touch $*/$(STS)
	@$(FOR_SUBS) $(STASH_CMD) && $(STASH_CMD) '${*}/*'
	rsync -rvL $*/ $@
	@$(FIND_DEPS) > $(DEP_DIR)/$*.d
	@$(RM) $*/$(STS) && $(FOR_SUBS) $(RM) $(STS)
	@$(UNSTASH_CMD)  && $(FOR_SUBS) $(UNSTASH_CMD)
	@$(RM) $*/$(STS) && $(FOR_SUBS) $(RM) $(STS)
	touch $@

-include $(LAB_DEPS)

# Figure out which version of LaTeX to use and save its
# name in a file:
$(BUILD_DIR)/%.cmd: %.tex Makefile | $(BUILD_DIR)
	@(                                                 \
	    if fgrep -q tufte-handout $<;                  \
	        then LATEX=pdflatex;                       \
	        else LATEX=xelatex;                       \
	    fi;                                            \
	    printf 'TEXINPUTS="%s" %s %s $< </dev/null\n'  \
	           "$(TEXINPUTS)" "$$LATEX" "$(TEXOPTS)";  \
	) > $@

$(BUILD_DIR):
	mkdir -p $@

$(DIST_DIR):
	mkdir -p $@

$(DEP_DIR):
	mkdir -p $@

# Delete all build products:
clean:
	$(RM) *.pdf *.zip *.tgz
	$(RM) -R $(BUILD_DIR) $(DIST_DIR) $(DEP_DIR)

watch:
	fswatch $(TEXS) | $(MAKE) watch-stdin

watch1:
	(printf '%s\n' $(TEXS); fswatch $(TEXS)) | $(MAKE) watch-stdin

watch-stdin:
	@while read tex; do \
	  pdf=$$(basename $$tex .tex).pdf; \
	  clear; \
	  echo "=== Building $$pdf ==="; \
	  $(MAKE) $$(basename $$pdf); \
	  echo "=== Done: $$? ==="; \
	done

.PRECIOUS: $(DIST_DIR)/%

.PHONY: pdf pdfs hard zip tgz
.PHONY: clean %.clean thisclean watch watch1 watch-stdin
