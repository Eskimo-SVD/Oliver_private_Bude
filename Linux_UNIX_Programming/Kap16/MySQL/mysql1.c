/* mysql1.c */
#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

/* Bitte Daten anpassen */
#define HOST     "localhost"
#define USER     "root"
#define PASSWORT "k4p6m3o3"
#define DBNAME   NULL
#define PORT     0
#define SOCKET   NULL
#define FLAG     0

int main (int argc, char **argv) {
  MYSQL *my;
  /* Handle initialisieren */
  my = mysql_init (NULL);
  if (my == NULL) {
    fprintf (stderr, " Initialisierung fehlgeschlagen\n");
    exit (EXIT_FAILURE);
  }
  /* Mit dem Server verbinden */
  if (mysql_real_connect (my,     /* Zeiger auf MYSQL-Handler */
                          HOST,     /* Host-Name */
                          USER,     /* User-Name */
                          PASSWORT, /* Passwort f�r user_name */
                          DBNAME,   /* Name der Datenbank */
                          PORT,     /* Port (default=0) */
                          SOCKET,   /* Socket (default=NULL) */
                          FLAG      /* keine Flags */
                         ) == NULL) {
    fprintf (stderr, "Fehler mysql_real_connect():"
             "%u (%s)\n", mysql_errno (my), mysql_error (my));
  }
  else
      printf ("Erfolgreich mit dem MySQL-Server verbunden\n");

  /* Hier befindet sich der Code f�r die Arbeit mit MySQL */

  /* Verbindung trennen */
  mysql_close (my);
  return EXIT_SUCCESS;
}
