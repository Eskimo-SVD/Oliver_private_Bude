/* server.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#define  MAX_ZEICHEN  16384
#define  PORT_NUMMER  1234

int main (void) {
  int sockfd, connfd, fd, j, n, ngesamt;
  struct sockaddr_in adresse;
  socklen_t adrlaenge = sizeof (struct sockaddr_in);
  char puffer[MAX_ZEICHEN];
  char path_file[MAX_ZEICHEN];
  const int y = 1;

  if ((sockfd = socket (PF_INET, SOCK_STREAM, 0)) < 0) {
     printf ("Fehler bei socket() ... (%s)\n", strerror(errno));
     exit (EXIT_FAILURE);
  }
  printf("Socket erfolgreich angelegt\n");
  adresse.sin_family = AF_INET;
  adresse.sin_port = htons (PORT_NUMMER);
  memset (&adresse.sin_addr, 0, sizeof (adresse.sin_addr));

  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &y, sizeof(int));

  if (bind ( sockfd,
             (struct sockaddr *) &adresse,
             sizeof (adresse) ) ) {
     printf ("Fehler bei bind() ... (%s)\n", strerror(errno));
     exit (EXIT_FAILURE);
  }

  printf("Server ist bereit und wartet ...\n");
  if (listen (sockfd, SOMAXCONN) != 0) {
     printf ("Fehler bei listen() ... (%s)\n", strerror(errno));
     exit (EXIT_FAILURE);
  }
  while ((connfd = accept ( sockfd,
                            (struct sockaddr *) &adresse,
                            &adrlaenge)) >= 0) {
     printf (" ...Daten empfangen\n");
     /* Dateiname */
     j = 0;
     while ((n = read (connfd, &puffer[j], 1)) > 0) {
        if (puffer[j] == '\n') {
           puffer[j] = 0;
           break;
        }
        j++;
     }
     if (n < 0) {
        printf ("Fehler bei read() ...\n");
        exit (EXIT_FAILURE);
     }
     printf ("Dateiname \"%s\"  wird kopiert nach ", puffer);
     strcpy( path_file, getenv("HOME"));
     strcat( path_file, "/tmp/");
     strcat( path_file, puffer );
     printf("%s\n",path_file);

     /* Datei zum lesen �ffnen */
     if ((fd=open(path_file,O_WRONLY|O_CREAT|O_TRUNC,0644)) < 0){
        printf ("... kann %s nicht �ffnen (%s)\n",
           puffer, strerror(errno));
        close (connfd);
        continue;
     }
     /* Datei aus dem Socket lesen und in lokale */
     /* Kopie schreiben                          */
     ngesamt = 0;
     while ((n = read (connfd, puffer, sizeof (puffer))) > 0) {
        if (write (fd, puffer, n) != n) {
           printf("Fehler bei write()...(%s)\n",strerror(errno));
           exit (EXIT_FAILURE);
        }
        ngesamt += n;
     }
     if (n < 0) {
         printf ("Fehler bei read() ...\n");
         exit (EXIT_FAILURE);
     }
     printf ("..beendet (%d Bytes)\n", ngesamt);
     close (fd);
     close (connfd);
   }
   if (connfd < 0) {
       printf ("Fehler bei accept() ...\n");
       exit (1);
   }
   close (sockfd);
   exit (EXIT_SUCCESS);
}
