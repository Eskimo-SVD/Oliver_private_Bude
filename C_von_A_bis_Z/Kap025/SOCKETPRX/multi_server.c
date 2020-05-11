/* multi_server.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "socketprx.h" 
#define BUF 1024    
 
int main (void) {
  socket_t sock1, sock2, sock3;
  int i, ready, sock_max, max=-1;
  int client_sock[FD_SETSIZE];
  fd_set gesamt_sock, lese_sock;
  char *buffer = (char*) malloc (BUF);

  sock_max = sock1 = create_socket(AF_INET, SOCK_STREAM, 0);
  atexit(cleanup);
  bind_socket( &sock1, INADDR_ANY, 15000 );
  listen_socket (&sock1);
  
  for( i=0; i<FD_SETSIZE; i++)
     client_sock[i] = -1;
  FD_ZERO(&gesamt_sock);
  FD_SET(sock1, &gesamt_sock);

  for (;;) {
    /* Immer Aktualisieren */
    lese_sock = gesamt_sock;
    /* Hier wird auf die Ankunft von Daten oder
     * neuer Verbindungen von Clients gewartet */
    ready = select( sock_max+1, &lese_sock, NULL, NULL, NULL );
    /* Eine neue Client-Verbindung ... ? */
    if( FD_ISSET(sock1, &lese_sock)) {
       accept_socket( &sock1, &sock2 );
       /* Freien Platz für (Socket)Deskriptor 
        * in client_sock suchen und vergeben */
       for( i=0; i< FD_SETSIZE; i++)
          if(client_sock[i] < 0) {
             client_sock[i] = sock2;
             break;
          }
       /* Mehr als FD_SETSIZE Clients sind nicht möglich */   
       if( i == FD_SETSIZE )
          error_exit("Server überlastet - zuviele Clients");
       /* Den neuen (Socket)Deskriptor zur
        * (Gesamt)Menge hinzufügen */   
       FD_SET(sock2, &gesamt_sock);
       /* select() benötigt die höchste 
        * (Socket)Deskriptor-Nummer */
       if( sock2 > sock_max )
          sock_max = sock2;
       /* höchster Index für client_sock
        * für die anschließende Schleife benötigt */
       if( i > max )
          max = i;
       /* ... weitere (Lese)Deskriptoren bereit ? */   
       if( --ready <= 0 )
          continue; //Nein ...
    } //if(FD_ISSET ...
    
    /* Ab hier werden alle Verbindungen von Clients auf
     * die Ankunft von neuen Daten überprüft */
    for(i=0; i<=max; i++) {
       if((sock3 = client_sock[i]) < 0)
          continue;
       /* (Socket)Deskriptor gesetzt ... */   
       if(FD_ISSET(sock3, &lese_sock)){
          /* ... dann die Daten lesen */
          TCP_recv (&sock3, buffer, BUF-1);
          printf ("Nachricht empfangen: %s\n", buffer);
          /* Wenn quit erhalten wurde ... */
          if (strcmp (buffer, "quit\n") == 0) {
             /* ... hat sich der Client beendet */
             close_socket (&sock3);        //Socket schließen
             FD_CLR(sock3, &gesamt_sock);  //aus Menge löschen
             client_sock[i] = -1;          //auf -1 setzen
             printf("Ein Client hat sich beendet\n");
          }
          /* Noch lesbare Deskriptoren vorhanden ... ? */
          if( --ready <= 0 )
             break; //Nein ...
       }
    }
  } // for(;;)
  return EXIT_SUCCESS;
}

