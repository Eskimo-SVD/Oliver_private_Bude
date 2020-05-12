# Ziel test
test: main.o test1.o test2.o
#	Datei "test" wird erzeugt ...
	gcc -o $@ main.o test1.o test2.o -lm

#	Abhängigkeitsliste
main.o: main.c
	gcc -c $*.c
test1.o: test1.c
	gcc -c $*.c
test2.o: test2.c test.h
	gcc -c $*.c
	
#	...sauber machen ...
clean:
	rm *.o test




