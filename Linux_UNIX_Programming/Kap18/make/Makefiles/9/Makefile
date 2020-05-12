CC      = gcc
OBJECTS = main.o test1.o test2.o
LIBS    = -lm
CFLAGS  = -O2

PREFIX := /usr

my_test: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

install: my_test
	install my_test ${PREFIX}/bin/

clean:
	rm -f *.o my_test






