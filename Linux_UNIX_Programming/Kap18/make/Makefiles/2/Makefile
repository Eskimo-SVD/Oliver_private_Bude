# Ein simples Makefile 

# Ziel test
test: main.o test1.o test2.o
#	Datei "test" wird erzeugt ...
	gcc -o test main.o test1.o test2.o -lm

main.o: main.c
	gcc -c main.c
test1.o: test1.c
	gcc -c test1.c
test2.o: test2.c
	gcc -c test2.c



