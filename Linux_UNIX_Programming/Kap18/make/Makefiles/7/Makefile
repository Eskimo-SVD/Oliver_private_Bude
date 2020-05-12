.SUFFIXES:
.SUFFIXES: .c .o

CC      = gcc
OBJECTS = main.o test1.o test2.o
LIBS    = -lm
CFLAGS  = -c -O

test: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $<
	
clean:
	rm *.o test





