clean:
	latexmk -c

warp2-web:
	pdflatex manual_warp2.tex
	pdflatex manual_warp2.tex
	@# This breaks hyperref links!
	@#ps2pdf14 -dPDFSETTINGS=/prepress manual_warp2.pdf manual_warp2_web.pdf
	cp manual_warp2.pdf ../documents/WARP2_Betriebsanleitung.pdf

warp2-print:
	pdflatex "\def\forprint{1} \input{manual_warp2.tex}"
	pdflatex "\def\forprint{1} \input{manual_warp2.tex}"
	ps2pdf14 -dPDFSETTINGS=/prepress -dSubsetFonts=false -dCompressFonts=true manual_warp2.pdf manual_warp2_print.pdf

warp-web:
	pdflatex manual.tex
	pdflatex manual.tex
	ps2pdf14 -dPDFSETTINGS=/prepress manual.pdf manual_warp_web.pdf
	cp manual_warp_web.pdf ../documents/WARP_Betriebsanleitung.pdf
