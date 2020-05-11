/* multi_client.c */ 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "socketprx.h"
#define BUF 1024  

int main (int argc, char **argv) {
  socket_t sock;
  char *buffer = (char *)malloc (BUF);

  if( argc < 2 ){
     printf("Usage: %s ServerAdresse\n", *argv);
     exit(EXIT_FAILURE);
  }

  sock = create_socket(AF_INET, SOCK_STREAM, 0);
  atexit(cleanup);
  connect_socket(&sock, argv[1], 15000);

  do {
      buffer[0] = '\0';
      printf ("Nachricht zum Versenden: ");
      fgets (buffer, BUF, stdin);
      TCP_send (&sock, buffer, strlen (buffer));
  } while (strcmp (buffer, "quit\n") != 0);
  close_socket (&sock);
  return EXIT_SUCCESS;
}

