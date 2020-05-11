/* udp_client.c */ 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "socketprx.h"
#define BUF 1024
#define SERVER_PORT 1234

int main (int argc, char **argv) {
  socket_t sock;
  /* Kommandozeile auswerten */
  if (argc < 3) {
    printf ("Usage: %s <server> <string>\n",argv[0]);
    exit (EXIT_FAILURE);
  }

  /* Socket erzeugen */
  sock = create_socket( AF_INET, SOCK_DGRAM, 0); 
  atexit(cleanup);
  bind_socket(&sock, INADDR_ANY, 0);  
  UDP_send(&sock,argv[2],strlen(argv[2]),argv[1], SERVER_PORT);

  return EXIT_SUCCESS;
}

