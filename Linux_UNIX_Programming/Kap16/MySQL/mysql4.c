/* mysql4.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#define MAX 255

/* Verbindungsdaten f�r mysql_real_connect */
static char *connect_param[7];
/* globeler Hilfz�hler f�r die Verbindungsdaten */
static int connect_param_count = 0;
static void print_line (MYSQL_RES * res);

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

/* Einlesen der Verbindungsdaten - Ein Dr�cken von <ENTER> */
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
        connect_param[2],       /* Passwort f�r user_name */
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
/* Listet alle vorhandenen Datenbanken auf */
static void list_DB (MYSQL * my) {
  MYSQL_RES *res;
  MYSQL_ROW row;
  int zeilen;
  unsigned int i;

  res = mysql_list_dbs (my, NULL);
  zeilen = (unsigned long) mysql_num_rows (res);
  printf ("Datenbanken gefunden : %d\n", zeilen);
  while ((row = mysql_fetch_row (res)) != NULL)
    /* mysql_num_flields() w�hre hier  nicht n�tig */
    for (i = 0; i < mysql_num_fields (res); i++)
      printf ("%s\n", row[i]);
  mysql_free_result (res);
  getchar ();
}

/* Listet alle Tabellen einer Datenbank auf */
static void list_table_DB (MYSQL * my) {
  MYSQL_RES *res;
  MYSQL_ROW row;
  int zeilen;
  unsigned int i;

  res = mysql_list_tables (my, NULL);
  if (res == NULL) {
    fprintf (stderr, "Fehler bei mysql_list_tables():"
             "%u (%s)\n", mysql_errno (my), mysql_error (my));
    return;
  }
  zeilen = (unsigned long) mysql_num_rows (res);
  printf ("Tabellen in der Datenbank : %d\n", zeilen);
  while ((row = mysql_fetch_row (res)) != NULL) {
    for (i = 0; i < mysql_num_fields (res); i++)
      printf ("%s", row[i]);
    printf ("\n");
  }
  mysql_free_result (res);
  getchar ();
}

/* Listet alle Felder einer Tabelle auf */
static void list_fields_DB (MYSQL * my) {
  unsigned int i, col_len;
  MYSQL_RES *res;
  MYSQL_FIELD *field;
  char buffer[MAX];

  printf ("Bitte ein Tabelle ausw�hlen : ");
  my_fgets (buffer, MAX);
  res = mysql_list_fields (my, buffer, NULL);
  if (res == NULL) {
    fprintf (stderr, "Fehler bei mysql_list_tables():"
             "%u (%s)\n", mysql_errno (my), mysql_error (my));
    return;
  }
  /* offset = 0 bedeutet auf den Anfang der Zeile setzen */
  mysql_field_seek (res, 0);
  /* Damit bei der Ausgabe ein einheitliches Bild entsteht,
   * sollen die Daten f�r die max. L�nge einer Spalte bei jeder
   * einzelnen (MYSQL_FIELD)-Spalte ver�ndert werden   */
  for (i = 0; i < mysql_num_fields (res); i++) {
     field = mysql_fetch_field (res);
     /* L�nge des Namens in der Spalte ermitteln */
     col_len = strlen (field->name);
     /* Ist die L�nge des Elements in der Spalte kleiner als
      * die max. L�nge ... */
     if (col_len < field->max_length)
        /* ... dann bekommt col_len den Wert der max. erl. L�nge
         * der Spalte */
        col_len = field->max_length;
     /* F�r den Fall, dass eine Spalte keine Daten
      * beinhaltet ... */
     if (col_len < 4 && !IS_NOT_NULL (field->flags))
        /* col_len bekommt den Wert 4 f�r den String
         * "NULL" ->kein Daten */
        col_len = 4;
     /* max. L�nge von Spalten-Info ver�ndern */
     field->max_length = col_len;
  }

  /* Namen der Tabelle ausgeben */
  printf ("Daten der Tabelle: [ %s ]\n", field->table);
  printf("Mit mysql_fetch_field()\n");
  /* Demonstriert mysql_fetch_field() */
  print_line (res);
  printf ("|");
  /* Alles wieder auf den Anfang stellen */
  mysql_field_seek (res, 0);

  /* Jetzt den Tabellenkopf ausgeben  */
  for (i = 0; i < mysql_num_fields (res); i++) {
     field = mysql_fetch_field (res);
     printf (" %-*s |", field->max_length, field->name);
  }
  printf ("\n");
  print_line (res);

  printf("Gleiches mit mysql_fetch_fields()\n");
  /* Dasselbe nochmals mit mysql_fetch_fields() */
  print_line (res);
  printf ("|");
  /* Alles wieder auf den Anfang stellen */
  mysql_field_seek (res, 0);
  field = mysql_fetch_fields (res);
  for (i = 0; i < mysql_num_fields (res); i++) {
     printf (" %-*s |", field[i].max_length, field[i].name);
  }
  printf ("\n");
  print_line (res);
  mysql_free_result (res);
}

static void print_line (MYSQL_RES * res) {
  MYSQL_FIELD *field;
  unsigned int i, j;

  mysql_field_seek (res, 0);
  /* Erstes Zeichen der Linie */
  printf ("+");
  for (i = 0; i < mysql_num_fields (res); i++) {
     field = mysql_fetch_field (res);
     /* max_length '-' Zeichen jeder Spalte ausgeben */
     for (j = 0; j < field->max_length + 2; j++)
        printf ("-");
     /* Am Ende der Spalte '+' ausgeben */
     printf ("+");
  }
  printf ("\n");
}

/* Listet alle vorhandenen Prozesse auf */
static void list_process (MYSQL * my) {
  MYSQL_RES *res;
  MYSQL_ROW row;
  int zeilen;
  unsigned int i, col_len;
  MYSQL_FIELD *field;

  res = mysql_list_processes (my);
  zeilen = (unsigned long) mysql_num_rows (res);
  printf ("Prozesse gefunden : %d\n", zeilen);
  /* offset = 0 bedeutet auf den Anfang der Zeile setzen */
  mysql_field_seek (res, 0);

  /* Damit bei der Ausgabe ein einheitliches Bild entsteht,
   * sollen die Daten f�r die max. L�nge einer Spalte bei jeder
   * einzelnen (MYSQL_FIELD)-Spalte ver�ndert werden */
  for (i = 0; i < mysql_num_fields (res); i++) {
     field = mysql_fetch_field (res);
     /* L�nge des Namens in der Spalte ermitteln */
     col_len = strlen (field->name);
     /* Ist die L�nge des Elements in der Spalte kleiner als
      * die max. L�nge ... */
     if (col_len < field->max_length)
        /* ... dann bekommt col_len den Wert der max. erl. L�nge
         * der Spalte */
        col_len = field->max_length;
     /* F�r den Fall, dass eine Spalte keine Daten
      * beinhaltet ... */
     if (col_len < 4 && !IS_NOT_NULL (field->flags))
        /* col_len bekommt den Wert 4 f�r den String
         * "NULL" ->kein Daten */
        col_len = 4;
     /* max. L�nge von Spalten-Info ver�ndern */
     field->max_length = col_len;
  }
  print_line (res);
  printf ("|");
  /* Alles wieder auf den Anfang stellen */
  mysql_field_seek (res, 0);

  /* Jetzt den Tabellenkopf ausgeben (titel, hauptrolle, fsk,
   * gedreht) */
  for (i = 0; i < mysql_num_fields (res); i++) {
      field = mysql_fetch_field (res);
      printf (" %-*s |", field->max_length, field->name);
  }
  printf ("\n");
  print_line (res);
  mysql_field_seek (res, 0);

  while ((row = mysql_fetch_row (res)) != NULL) {
     printf ("|");
     for (i = 0; i < mysql_num_fields (res); i++) {
        field = mysql_fetch_field (res);
        printf (" %-*s |",field->max_length, row[i]);
     }
     printf ("\n");
     mysql_field_seek (res, 0);
  }
  print_line (res);
  mysql_free_result (res);
}

int main (int argc, char *argv[]) {
  MYSQL *my;
  int auswahl;

  /* Handle initialisieren */
  my = mysql_init (NULL);
  if (my == NULL) {
    fprintf (stderr, " Initialisierung fehlgeschlagen\n");
    exit (EXIT_FAILURE);
  }
  /* Verbindungsdaten f�r die Datenbank abfragen */
  get_connect_param ();
  /* Mit dem Server verbinden */
  if (mein_connect (my) != -1)
    printf ("Erfolgreich mit dem MySQL-Server verbunden\n");
  do {
    printf ("\nInformationen zu den Datenbanken auf dem"
            " MySQL-Server\n\n");
    printf ("- 1 - Alle vorhandenen Datenbanken ausgeben \n");
    printf ("- 2 - Tabellen einer Datenbank auflisten\n");
    printf (" -3 - Spalten der Tabelle auflisten\n");
    printf ("- 4 - Prozessliste anzeigen\n");
    printf ("- 0 - Beenden\n\n");
    printf ("Ihre Auswahl : ");
    scanf ("%d", &auswahl);
    switch (auswahl) {
    case 1:
      list_DB (my);
      getchar ();
      break;
    case 2:
      getchar ();
      list_table_DB (my);
      break;
    case 3:
      getchar ();
      list_fields_DB (my);
      break;
    case 4:
      getchar ();
      list_process (my);
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