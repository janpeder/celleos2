OUTFILE=celleos2_brukermanual

default: $(OUTFILE).pdf
clean:
	rm -f $(OUTFILE).dvi
	rm -f $(OUTFILE).ps*
	rm -f $(OUTFILE).p1*
	rm -f $(OUTFILE).p2*
	rm -f $(OUTFILE).log
	rm -f $(OUTFILE).pdf

$(OUTFILE).dvi: $(OUTFILE).tex
	tex $(OUTFILE).tex

$(OUTFILE).ps: $(OUTFILE).dvi
	dvips $(OUTFILE).dvi

$(OUTFILE).pdf: $(OUTFILE).ps
	ps2pdf $(OUTFILE).ps
