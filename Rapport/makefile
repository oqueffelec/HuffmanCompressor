all: RapportCompresseurHuffman.pdf

pdf: RapportCompresseurHuffman.pdf

RapportCompresseurHuffman.pdf: clean RapportCompresseurHuffman.tex
	pdflatex RapportCompresseurHuffman
	pdflatex RapportCompresseurHuffman
	latex_count=8 ; \
	while egrep -s 'Rerun (LaTeX|to get cross-references right)' RapportCompresseurHuffman.log && [ $$latex_count -gt 0 ] ;\
	    do \
	      echo "Rerunning latex...." ;\
	      pdflatex RapportCompresseurHuffman ;\
	      latex_count=`expr $$latex_count - 1` ;\
	    done
	pdflatex RapportCompresseurHuffman


clean:
	rm -f *.ps *.dvi *.aux *.toc *.idx *.ind *.ilg *.log *.out *.brf *.blg *.bbl RapportCompresseurHuffman.pdf
