# Ein simples Makefile mit zwei Zielen (targets)

# Ziel 1:
testprogramm: 
#	Datei "test" wird erzeugt ...
	gcc -o test main.c test1.c test2.c -lm
#	... fertig

# Ziel 2:
debugprogramm:
#	Debugversion wird erstellt
	gcc -DDEBUG -ggdb3 -o test.db main.c test1.c test2.c -lm
#	... fertig mit Debugversion


