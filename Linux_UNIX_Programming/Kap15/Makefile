CFLAGS=-g -Wall
LDFLAGS=
LIBS=-lssl -lcrypto


all: https_client https_server

https_client: https_client.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o https_client https_client.c $(LIBS)

https_server: https_server.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o https_server https_server.c $(LIBS)


clean:
	rm -f *.o


ci:
	git add *.c *.sh Makefile
	git commit
