CC      = gcc
OBJECTS = main.o test1.o test2.o
LIBS    = -lm
CFLAGS  = -c -O

mein_projekt: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm *.o mein_projekt






