# Datei makefile
CC     = gcc
CFLAGS = -I .

INCL = func1.h func2.h
OBJ  = func1.o func2.o main.o

myprog: $(OBJ)
	$(CC) $(CFLAGS) -o myprog $(OBJ)

%.o: %.c $(INCL)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm *.o myprog
