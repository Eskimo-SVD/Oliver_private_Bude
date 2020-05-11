/* client.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef _WIN32
/* Headerfiles für Windows */
#include <winsock.h>
#include <io.h>

#else
/* Headerfiles für Unix/Linux */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

#define PORT 1234
#define RCVBUFSIZE 8192

/* Funktion gibt aufgetrenene Fehler aus und 
 * beendet die Anwendung */
static void error_exit(char *errorMessage) {
#ifdef _WIN32
    fprintf(stderr,"%s: %d\n", errorMessage, WSAGetLastError());
#else
    fprintf(stderr, "%s: %s\n", errorMessage, strerror(errno));
#endif
    exit(EXIT_FAILURE);
}

int main( int argc, char **argv) {
    struct sockaddr_in server;
    struct hostent *host_info;
    unsigned long addr;

#ifdef _WIN32
    SOCKET sock;
#else
    int sock;
#endif

    char *echo_string;
    int echo_len;    
    
#ifdef _WIN32  
    /* Initialisiere TCP für Windows ("winsock") */
    WORD wVersionRequested;
    WSADATA wsaData;
    wVersionRequested = MAKEWORD (1, 1);
    if (WSAStartup (wVersionRequested, &wsaData) != 0)
        error_exit( "Fehler beim Initialisieren von Winsock");
    else
        printf("Winsock initialisiert\n");
#endif

 /* Sind die erforderlichen Kommandozeilenargumente vorhanden? */
    if (argc < 3) 
        error_exit("usage: client server-ip echo_word\n");

    /* Erzeuge das Socket */
    sock = socket( AF_INET, SOCK_STREAM, 0 );
    if (sock < 0)
        error_exit( "Fehler beim Anlegen eines Sockets");

    /* Erzeuge die Socketadresse des Servers 
     * Sie besteht aus Typ, IP-Adresse und Portnummer */
    memset( &server, 0, sizeof (server));
    if ((addr = inet_addr( argv[1])) != INADDR_NONE) {
        /* argv[1] ist eine numerische IP-Adresse */
        memcpy( (char *)&server.sin_addr, &addr, sizeof(addr));
    }
    else {
        /* Für den Fall der Fälle: Wandle den 
         * Servernamen bspw. "localhost" in eine IP-Adresse um */
        host_info = gethostbyname(argv[1]);
        if (NULL == host_info) 
            error_exit("Unbekannter Server");
        /* Server-IP-Adresse */    
        memcpy( (char *)&server.sin_addr,
                host_info->h_addr, host_info->h_length );
    }
    /* IPv4-Verbindung */
    server.sin_family = AF_INET;
    /* Portnummer */
    server.sin_port = htons( PORT );

    /* Baue die Verbindung zum Server auf */
    if(connect(sock,(struct sockaddr*)&server,sizeof(server)) <0)
        error_exit("Kann keine Verbindung zum "
                   "Server herstellen");

    /* Zweites Argument wird als "echo" beim Server verwendet */
    echo_string = argv[2];  
    /* Länge der Eingabe */  
    echo_len = strlen(echo_string); 
  
    /* Denn String inskl. Nullterminator an den Server senden */ 
    if (send(sock, echo_string, echo_len, 0) != echo_len)
        error_exit("send() hat eine unterschiedliche Anzahl"
                   " von Bytes versendet, als erwartet !!!!");        

    /* Schließe Verbindung und Socket */
#ifdef _WIN32
    closesocket(sock);
    /* Cleanup Winsock */
    WSACleanup();  
#else
   close(sock);    
#endif

    return EXIT_SUCCESS;
}

