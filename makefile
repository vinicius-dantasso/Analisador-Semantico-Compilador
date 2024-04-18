all: project

# Compiladores
CPP=g++
FLEX=flex 
BISON=bison

project: lex.yy.c project.tab.c semantic.o
	$(CPP) lex.yy.c project.tab.c semantic.o -std=c++17 -o project

lex.yy.c: project.l
	$(FLEX) project.l

project.tab.c: project.y
	$(BISON) -d -Wcounterexamples project.y

semantic.o: semantic.cpp
	$(CPP) -c semantic.cpp -std=c++17 -o semantic.o

clean:
	rm project lex.yy.c project.tab.c project.tab.h
