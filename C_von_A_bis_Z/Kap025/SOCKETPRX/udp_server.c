/* udp_server.c */
#include <string.h>
#include <time.h>
#include "socketprx.h"

#define LOCAL_SERVER_PORT 1234
#define BUF 255

int main (int argc, char **argv) {
  socket_t sock;
  char puffer[BUF];
  time_t time1;
  char loctime[BUF];
  char *ptr;

  /* Socket erzeugen */
  sock = create_socket( AF_INET, SOCK_DGRAM, 0); 
  atexit(cleanup);
  bind_socket(&sock, INADDR_ANY, LOCAL_SERVER_PORT);
  printf ("Warte auf Daten am Port (UDP) %u\n",
     LOCAL_SERVER_PORT);
  /* Server-Schleife */
  while (1) {
    memset (puffer, 0, BUF);
    UDP_recv( &sock, puffer, BUF ); 
    /* Zeitangaben präparieren */
    time(&time1);
    strncpy(loctime, ctime(&time1), BUF);
    ptr = strchr(loctime, '\n' );
    *ptr = '\0';

    /* Erhaltene Nachricht ausgeben */
    printf ("%s: Daten erhalten: %s\n",
            loctime, puffer);
  }
  return EXIT_SUCCESS;
}

