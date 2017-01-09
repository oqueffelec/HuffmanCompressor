EXEC=huffman
EXECTEST=testHuffman
SRCTESTDIR=testsrc
SRCDIR=src
LIBDIR=lib
TESTDIR=tests
BINDIR=bin
INCLUDEDIR=include
DOCDIR=doc
CC=gcc
CREATE=mkdir

CFLAGS=-Wall -pedantic -g -std=gnu99 -I$(INCLUDEDIR)
LDFLAGS=-L$(LIBDIR) -lhuffman

# $@ nom de la cible
# $< nom de la première dépendance
# $^ liste de toutes les dépendances
# $? liste des dépendances plus récentes que la cible
# $* nom du fichier sans suffixe

all:  exec

exec: $(BINDIR)/$(EXEC)

doc: $(DOCDIR)/html/index.html $(DOCDIR)/latex/refman.pdf

$(DOCDIR)/html/index.html:
	doxygen

$(DOCDIR)/latex/refman.pdf: $(DOCDIR)/latex/refman.tex
	cd $(DOCDIR)/latex/; make; cd ../..

$(DOCDIR)/latex/refman.tex:
	doxygen





tests: $(TESTDIR)/testTADArbreDeHuffman $(TESTDIR)/testTADCodeBinaire $(TESTDIR)/testTADFileDePriorite $(TESTDIR)/testTADOctet $(TESTDIR)/testTADStatistiques $(TESTDIR)/testTADTableDeCodage $(TESTDIR)/testCreerFileDePriorite $(TESTDIR)/testCreerTableDeCodage

$(TESTDIR)/% : $(SRCTESTDIR)/%.o $(LIBDIR)/libhuffman.a
	$(CC) -o $@ $< $(LDFLAGS) -lcunit

$(LIBDIR)/libhuffman.a: $(SRCDIR)/ArbreDeHuffman.o $(SRCDIR)/CodeBinaire.o $(SRCDIR)/FichierBinaire.o $(SRCDIR)/FileDePriorite.o $(SRCDIR)/Octet.o $(SRCDIR)/Statistiques.o $(SRCDIR)/TableDeCodage.o $(SRCDIR)/creerFileDePriorite.o $(SRCDIR)/creerTableDeCodage.o
	ar -r $@ $^

$(BINDIR)/$(EXEC): $(LIBDIR)/libhuffman.a $(SRCDIR)/main.o $(SRCDIR)/codage.o $(SRCDIR)/compression.o $(SRCDIR)/creerFileDePriorite.o $(SRCDIR)/creerStatistiques.o $(SRCDIR)/creerTableDeCodage.o $(SRCDIR)/decodage.o $(SRCDIR)/decodageCodeBinaire.o $(SRCDIR)/decompression.o $(SRCDIR)/enTete.o $(SRCDIR)/recupererDonnees.o
	$(CC) -o $@ $(SRCDIR)/main.o $(SRCDIR)/codage.o $(SRCDIR)/compression.o $(SRCDIR)/creerFileDePriorite.o $(SRCDIR)/creerStatistiques.o $(SRCDIR)/creerTableDeCodage.o $(SRCDIR)/decodage.o $(SRCDIR)/decodageCodeBinaire.o $(SRCDIR)/decompression.o $(SRCDIR)/enTete.o $(SRCDIR)/recupererDonnees.o $(LDFLAGS)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(SRCTESTDIR)/%.o: $(SRCTESTDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*.a
	rm -rf $(SRCDIR)/*.o
	rm -rf $(SRCTESTDIR)/*.o
	rm -rf $(TESTDIR)/*
	rm -rf $(DOCDIR)/html
	rm -rf $(DOCDIR)/rapport/*.pdf
	rm -rf $(DOCDIR)/latex/*.pdf
