# Convert print PDFs to CMYK with the wirmachendruck.de profile
ICC_PROFILE = ../manual/color/ISOcoated_v2_300_eci.icc
PDFX_DEF = pdfx_stand.ps
LATEXMK = latexmk -pdf -interaction=nonstopmode -halt-on-error

.PHONY: clean stand-web stand-print stand4-web stand4-print

define to_cmyk_print
	gs -dBATCH -dNOPAUSE -dNOOUTERSAVE \
	  --permit-file-read=$(PDFX_DEF) --permit-file-read=$(ICC_PROFILE) \
	  -sDEVICE=pdfwrite -dCompatibilityLevel=1.6 \
	  -dPDFSETTINGS=/prepress \
	  -sColorConversionStrategy=CMYK -sProcessColorModel=DeviceCMYK \
	  -dSubsetFonts=false -dCompressFonts=true \
	  -sOutputICCProfile=$(ICC_PROFILE) \
	  -sOutputFile=$(2) \
	  $(PDFX_DEF) $(1)
endef

clean:
	latexmk -c
	latexmk -c -jobname=manual_stand4_print_source manual_stand4.tex

stand-web:
	pdflatex manual_stand.tex
	pdflatex manual_stand.tex
	@# This breaks hyperref links!
	@#ps2pdf14 -dPDFSETTINGS=/prepress manual_stand.pdf manual_stand_web.pdf
	cp manual_stand.pdf ../documents/WARP_Ladesaeule_Betriebsanleitung.pdf

stand-print:
	pdflatex "\def\forprint{1} \input{manual_stand.tex}"
	pdflatex "\def\forprint{1} \input{manual_stand.tex}"
	$(call to_cmyk_print,manual_stand.pdf,manual_stand_print.pdf)

stand4-web:
	$(LATEXMK) manual_stand4.tex
	cp manual_stand4.pdf ../documents/WARP4_Ladesaeule_Betriebsanleitung.pdf

stand4-print:
	$(LATEXMK) -jobname=manual_stand4_print_source -usepretex='\def\forprint{1}' manual_stand4.tex
	$(call to_cmyk_print,manual_stand4_print_source.pdf,manual_stand4_print.pdf)
