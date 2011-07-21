FILES=oo2c-v2

# Note: This makefile requires GNU make
DVIPS_OPTIONS="-D 600 -Z"

OUTPUT_SUFFIX=.html .pdf
#OUTPUT_SUFFIX=.info .html .pdf .ps 
TMP_SUFFIX=.aux .cp .fn .ky .log .pg .toc .tp .vr .dvi
.PHONY: all clean distclean %.all %.clean %.distclean


all: $(foreach SUFFIX,$(OUTPUT_SUFFIX),$(addsuffix $(SUFFIX),$(FILES)))

%.dvi: %.texi
	texi2dvi $<

%.ps: %.dvi
	dvips ${DVIPS_OPTIONS} -t letter -o $@ $<

%.pdf: %.texi
	texi2pdf $<

%.info: %.texi
	makeinfo $<

%.html: %.texi
	texi2html -monolithic $<

%.clean:
	rm -f $(addprefix $*,$(TMP_SUFFIX))

%.distclean:
	rm -f $(addprefix $*,$(OUTPUT_SUFFIX))

clean: $(addsuffix .clean, $(FILES))

distclean: clean $(addsuffix .distclean, $(FILES))
