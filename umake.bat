rem typesetting with UTF8 bibtex tool
rem copy umake.bat to ..\miktex\bin\x64\
rem TeXworks->Edit->Preferences->Typesetting->Processing tool->'+'
rem Name: PdfLaTeX+BibtexU, Program: umake.bat, Arguments: $fullname
rem or make manually calling umake.bat *.tex from command line

pdflatex %1
bibtexu %~n1.aux
pdflatex %1
pdflatex %1
del *.aux
del *.bbl
del *.blg
del *.cpc
del *.toc
del *.out
