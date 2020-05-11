/* server.c */
#include <string.h>
#include "socketprx.h" 
#define BUF 1024    
 
int main (void) {
  socket_t sock1, sock2;
  int addrlen;
  char *buffer = (char*) malloc (BUF);

  sock1 = create_socket(AF_INET, SOCK_STREAM, 0);
  atexit(cleanup);
  bind_socket( &sock1, INADDR_ANY, 15000 );
  listen_socket (&sock1);
  addrlen = sizeof (struct sockaddr_in);

  while (1) {
     accept_socket( &sock1, &sock2 );
     do {
        printf ("Nachricht zum Versenden: ");
        fgets (buffer, BUF, stdin);
        TCP_send (&sock2, buffer, strlen (buffer));
        TCP_recv (&sock2, buffer, BUF-1);
        printf ("Nachricht empfangen: %s\n", buffer);
     } while (strcmp (buffer, "quit\n") != 0);
     close_socket (&sock2);
  }
  close_socket (&sock1);
  return EXIT_SUCCESS;
}

