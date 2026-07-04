# The recipe below converts everything to CMYK using the "ISO Coated v2 300%
# (ECI)" profile supplied by wirmachendruck.de
ICC_PROFILE = color/ISOcoated_v2_300_eci.icc
PDFX_DEF    = pdfx_warp.ps

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

warp4-web:
	pdflatex manual_warp4.tex
	pdflatex manual_warp4.tex
	@# This breaks hyperref links!
	@#ps2pdf14 -dPDFSETTINGS=/prepress manual_warp2.pdf manual_warp2_web.pdf
	cp manual_warp4.pdf ../documents/WARP4_Betriebsanleitung.pdf

warp4-print:
	pdflatex "\def\forprint{1} \input{manual_warp4.tex}"
	pdflatex "\def\forprint{1} \input{manual_warp4.tex}"
	$(call to_cmyk_print,manual_warp4.pdf,manual_warp4_print.pdf)

warp3-web:
	pdflatex manual_warp3.tex
	pdflatex manual_warp3.tex
	@# This breaks hyperref links!
	@#ps2pdf14 -dPDFSETTINGS=/prepress manual_warp2.pdf manual_warp2_web.pdf
	cp manual_warp3.pdf ../documents/WARP3_Betriebsanleitung.pdf

warp3-print:
	pdflatex "\def\forprint{1} \input{manual_warp3.tex}"
	pdflatex "\def\forprint{1} \input{manual_warp3.tex}"
	$(call to_cmyk_print,manual_warp3.pdf,manual_warp3_print.pdf)


warp2-web:
	pdflatex manual_warp2.tex
	pdflatex manual_warp2.tex
	@# This breaks hyperref links!
	@#ps2pdf14 -dPDFSETTINGS=/prepress manual_warp2.pdf manual_warp2_web.pdf
	cp manual_warp2.pdf ../documents/WARP2_Betriebsanleitung.pdf

warp2-print:
	pdflatex "\def\forprint{1} \input{manual_warp2.tex}"
	pdflatex "\def\forprint{1} \input{manual_warp2.tex}"
	$(call to_cmyk_print,manual_warp2.pdf,manual_warp2_print.pdf)

warp-web:
	pdflatex manual.tex
	pdflatex manual.tex
	ps2pdf14 -dPDFSETTINGS=/prepress manual.pdf manual_warp_web.pdf
	cp manual_warp_web.pdf ../documents/WARP_Betriebsanleitung.pdf
