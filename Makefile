all: build clean

build:
	pdflatex bdr.tex ; \
	bibtex bdr.aux ; \
	pdflatex bdr.tex

clean:
	rm *.aux \
	*.bbl \
	*.blg \
	*.cpc \
	*.toc \
	*.out
