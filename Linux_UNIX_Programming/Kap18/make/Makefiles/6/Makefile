CC      = gcc
OBJECTS = main.o test1.o test2.o
LIBS    = -lm
CFLAGS  = -c

test: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LIBS)

main.o: main.c
	$(CC) $(CFLAGS) $*.c
test1.o: test1.c
	$(CC) $(CFLAGS) $*.c
test2.o: test2.c test.h
	$(CC) $(CFLAGS) $*.c
	
clean:
	rm *.o test




