clean:
	latexmk -c

em-web:
	pdflatex manual_energy_manager.tex
	pdflatex manual_energy_manager.tex
	@# This breaks hyperref links!
	@#ps2pdf14 -dPDFSETTINGS=/prepress manual_energy_manager.pdf manual_energy_manager_web.pdf
	cp manual_energy_manager.pdf ../documents/WARP_Energy_Manager_Betriebsanleitung.pdf

em-print:
	pdflatex "\def\forprint{1} \input{manual_energy_manager.tex}"
	pdflatex "\def\forprint{1} \input{manual_energy_manager.tex}"
	ps2pdf14 -dPDFSETTINGS=/prepress -dSubsetFonts=false -dCompressFonts=true manual_energy_manager.pdf manual_energy_manager_print.pdf

