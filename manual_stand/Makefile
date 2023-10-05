clean:
	latexmk -c

stand-web:
	pdflatex manual_stand.tex
	pdflatex manual_stand.tex
	@# This breaks hyperref links!
	@#ps2pdf14 -dPDFSETTINGS=/prepress manual_stand.pdf manual_stand_web.pdf
	cp manual_stand.pdf ../documents/WARP_Ladesaeule_Betriebsanleitung.pdf

stand-print:
	pdflatex "\def\forprint{1} \input{manual_stand.tex}"
	pdflatex "\def\forprint{1} \input{manual_stand.tex}"
	ps2pdf14 -dPDFSETTINGS=/prepress -dSubsetFonts=false -dCompressFonts=true manual_stand.pdf manual_stand_print.pdf

