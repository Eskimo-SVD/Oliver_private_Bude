/* mysql3.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mysql.h>
#define MAX 255

/* Verbindungsdaten für mysql_real_connect */
static char *connect_param[7];
/* globeler Hilfzähler für die Verbindungsdaten */
static int connect_param_count = 0;

/* Eigene fgets-Funktion, welche \n entfernt */
static void my_fgets( char *ptr, unsigned int max ) {
  char *help;
  fgets(ptr, max, stdin );
  if( ( help = strchr( ptr, '\n') ) != NULL )
    *help = '\0'; /* Newline durch \0 ersetzen */
}

/* Zusammenstellen der Verbindungsdaten in connect_param */
static void my_cat( char *ptr ) {
  connect_param[connect_param_count] = malloc( strlen (ptr) + 1);
  if (connect_param[connect_param_count] == NULL) {
    printf("Konnte keinen Speicher reservieren ...\n");
    exit (EXIT_FAILURE);
  }
  strcpy( connect_param[connect_param_count], ptr );
  connect_param_count++;
}

/* Einlesen der Verbindungsdaten - Ein Drücken von <ENTER> */
/* bezweckt, dass die Standard-Werte verwendet werden -    */
/* Garantiert allerdings kein Verbindungsaufbau.           */
static void get_connect_param( void ) {
  char puffer[MAX];

  printf("Host-Name (<ENTER> == default) : ");
  my_fgets( &puffer[0], MAX );
  if( puffer[0] == '\0' )
    connect_param[connect_param_count++] = NULL;
  else
    my_cat( &puffer[0] );
  printf("User-Name (<ENTER> == default) : ");
  my_fgets( &puffer[0], MAX );
  if( puffer[0] == '\0' )
    connect_param[connect_param_count++] = NULL;
  else
    my_cat( &puffer[0] );
  printf("Passwort (<ENTER> == default)  : ");
  my_fgets( &puffer[0], MAX );
  if( puffer[0] == '\0' )
    connect_param[connect_param_count++] = NULL;
  else
    my_cat( &puffer[0] );
  printf("Datenbank (<ENTER> == default) : ");
  my_fgets( &puffer[0], MAX );
  if( puffer[0] == '\0' )
    connect_param[connect_param_count++] = NULL;
  else
    my_cat( &puffer[0] );
  printf("Port (<ENTER> == default)      : ");
  my_fgets( &puffer[0], MAX );
  if( puffer[0] == '\0' ) {
    puffer[0] = '0';
    my_cat( &puffer[0] );
  }
  else
    my_cat( &puffer[0] );
  printf("Socket (<ENTER> == default)    : ");
  my_fgets( &puffer[0], MAX );
  if( puffer[0] == '\0' )
    connect_param[connect_param_count++] = NULL;
  else
    my_cat( &puffer[0] );
  printf("Flag (<ENTER> == default)      : ");
  my_fgets( &puffer[0], MAX );
  if( puffer[0] == '\0' ) {
    puffer[0] = '0';
    my_cat( &puffer[0] );
  }
  else
    my_cat( &puffer[0] );
}

/* Mit dem MySQL-Server und den entsprechenden */
/* Verbindungsdaten ein Verbindung herstellen  */
static int mein_connect( MYSQL *my ) {
  /* Mit dem Server verbinden */
  if( mysql_real_connect (
        my,                     /* Zeiger auf MYSQL-Handler*/
        connect_param[0],       /* Host-Name*/
        connect_param[1],       /* User-Name*/
        connect_param[2],       /* Passwort für user_name */
        connect_param[3],       /* Name der Datenbank*/
        strtoul(connect_param[4], NULL, 0),/* Port (default=0) */
        connect_param[5],       /* Socket (default=NULL)*/
        strtoul(connect_param[6], NULL, 0)  /* keine Flags */
      )  == NULL) {
    fprintf (stderr, "Fehler mysql_real_connect():"
             "%u (%s)\n",mysql_errno (my), mysql_error (my));
    return -1;
  }
  return 1;
}

/* Speicher freigeben und Verbindung beenden */
static void clean_up_shutdown( MYSQL * my ) {
  mysql_close (my);
}


int main (int argc, char **argv) {
  MYSQL *my;
  int auswahl;

  /* Handle initialisieren */
  my = mysql_init (NULL);
  if (my == NULL) {
    fprintf (stderr, " Initialisierung fehlgeschlagen\n");
    exit (EXIT_FAILURE);
  }
  /* Verbindungsdaten für die Datenbank abfragen */
  get_connect_param ();
  /* Mit dem Server verbinden */
  if (mein_connect (my) != -1)
    printf ("Erfolgreich mit dem MySQL-Server verbunden\n");
  do {
    printf ("Informationen zum MySQL-Server auf"
            " Ihrem System\n");
    printf ("-----------------------------------"
            "------------\n\n");
    printf ("- 1 - Aktiven Zeichensatz ausgeben \n");
    printf ("- 2 - Versionsnummer des Client\n");
    printf ("- 3 - Host-Informationen\n");
    printf ("- 4 - Protokoll-Version\n");
    printf ("- 5 - Versionsnummer des Servers\n");
    printf ("- 6 - Infos über die letzten MySQL-Abfragen\n");
    printf ("- 0 - Beenden\n\n");
    printf ("Ihre Auswahl : ");
    scanf ("%d", &auswahl);
    switch (auswahl) {
    case 1:
      printf ("\nZeichensatz auf Ihrem MySQL-System : %s\n\n",
         mysql_character_set_name (my));
      getchar ();
      break;
    case 2:
      printf ("\nVersionsnummer : %s\n\n",
         mysql_get_client_info ());
      getchar ();
      break;
    case 3:
      printf ("\nInfos zum Host : %s\n\n",
         mysql_get_host_info (my));
      getchar ();
      break;
    case 4:
      printf ("\nProtokoll-Version : %d\n\n",
         mysql_get_proto_info (my));
      getchar ();
      break;
    case 5:
      printf ("\nVersionsnummer : %s\n\n",
         mysql_get_server_info (my));
      getchar ();
      break;
    case 6:
      printf ("\nDie letzten Aktionen : %s\n\n",
         mysql_info (my));
      getchar ();
      break;
    case 0:
      printf ("Bye\n");
      break;
    default:
      printf ("Fehlerhafte Eingabe\n");
    }
  } while (auswahl != 0);
  /* Verbindung trennen */
  clean_up_shutdown (my);
  return EXIT_SUCCESS;
}