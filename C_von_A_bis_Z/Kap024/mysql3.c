/* mysql3.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined __WIN32__ || _MSC_VER
   #include "my_global.h"
   #include "mysql.h"
   //#pragma comment(lib,"libmysql.lib")
#else
   #include <mysql.h>   
#endif

/* Wegen sehr vielen malloc()-Aufrufen im Listing
 * wurde hier zur Verkürzung des Listings ein Makro
 * geschrieben, welches aber keine Schule machen soll!! 
 */
#define malloc(size) \
        malloc(size);\
        if( (size) == NULL)\
           {\
              printf("Kein Speicher mehr ...\n");\
              return;\
           }

/* Funktionsprototypen */
void check_error(void);
void verbinden(void);
void verbindung_schliessen(void);
void db_waehlen(char *);
void filmdaten_anfuegen(void);
void filmdaten_loeschen(void);
void filmdaten_aendern(void);
void alle_daten_ausgeben(void);
void schauspieler_suchen(char *);
void print_line(MYSQL_RES *);

MYSQL *mysql;

/* Bricht bei Fehler (mysql_error != 0) das Programm ab */
void check_error(void)  {
   if (mysql_errno(mysql) != 0) {
      fprintf(stderr, "Fehler: %s\n", mysql_error(mysql));
      exit(EXIT_FAILURE);
   }
}

/* Baut eine Verbindung zum Datenbankserver auf.
 * Passen Sie ggf. Usernamen und Passwort und, sofern
 * andere Parameter benötigt werden, diese Ihren
 * Umständen selbst an
 */
void verbinden(void)  {
   mysql=mysql_init(mysql);
   check_error();
   mysql_real_connect(mysql, "localhost", "root", 
                      NULL, NULL, 0, NULL, 0);
   check_error();
}

/* Serververbindung wieder schließen und den Speicher für die 
 * Struktur MYSQL wieder freigeben */
void verbindung_schliessen(void)  {
   mysql_close(mysql);
}

/* Falls Datenbank bei der Funktion verbinden() nicht angegeben
 * wurde oder Sie die Datenbank wechseln wollen, dann verwenden
 * Sie diese Funktion */
void db_waehlen(char *db) {
   mysql_select_db(mysql, db);
   check_error();
}

/* Daten mit mysql_real_query() in die Datenbank schreiben */
void filmdaten_anfuegen(void) {
   char titel[255], hauptrolle[255], temp[6];
   unsigned int fsk, gedreht;
   int i,  size=0;
   char *str[9], *query;
   char *ptr;

   printf("\n\nFilmtitel  : ");
   fgets(titel, 254, stdin);
   if( (ptr = strchr(titel, '\n')) != NULL)
      *ptr = '\0';  /* newline durch \0 ersetzen */

   printf("Hauptrolle : ");
   fgets(hauptrolle, 254, stdin);
   if( (ptr = strchr(hauptrolle, '\n')) != NULL)
      *ptr = '\0';  /* newline durch \0 ersetzen */  

   printf("FSK        : ");
   fgets(temp, 4, stdin);
   if( (ptr = strchr(temp, '\n')) != NULL)
      *ptr = '\0';  /* newline durch \0 ersetzen */ 
   sscanf(temp, "%u", &fsk);   

   printf("Gedreht    : ");
   fgets(temp, 5, stdin);
   if( (ptr = strchr(temp, '\n')) != NULL)
      *ptr = '\0';  /* newline durch \0 ersetzen */ 
   sscanf(temp, "%u", &gedreht); 

   /* Jetzt wird der Anfragestring erstellt */
   str[0] = "INSERT INTO filmdaten (titel, hauptrolle, fsk, "
            "gedreht) VALUES ('";
   str[1] = malloc(strlen(titel)+1); 
   strcpy(str[1], titel);
   str[2] = "','";
   str[3] = malloc(strlen(hauptrolle)+1); 
   strcpy(str[3], hauptrolle);
   str[4] = "',";
   str[5] = malloc(3);
   sprintf(str[5], "%2u", fsk);
   str[6] = ",";
   str[7] = malloc(5);
   sprintf(str[7], "%4u", gedreht);
   str[8] = ")";

   for (i=0; i < 9; i++)
      size+=strlen(str[i]);
   /* Speicherplatz für den Anfragestring reservieren */  
   query = malloc(size + 1);
   strcpy(query, str[0]);
   for(i = 1; i < 9; i++)
      strcat(query, str[i]);
   /* Zum Testen für die Konsole  */
   /* printf("%s",query);         */

   /* Jetzt die Anfrage an den Datenbankserver */
   mysql_real_query(mysql, query, strlen(query));
   check_error();
   free(query);
}

void filmdaten_loeschen(void) {
   char del[255], temp[4];
   char *item[] = {"titel", "hauptrolle", "fsk", "gedreht" };
   char *ptr;
   char *str[5], *query='\0';
   int auswahl, i, size=0;
   unsigned long affected;

   printf("Nach welchem Kriterium wollen Sie Daten loeschen\n");
   printf("[1]=Titel  [2]=Hauptrolle  [3]=FSK  "
          "[4]=Datum  : [ ]\b\b");

   fgets(temp, 3, stdin);
   if( (ptr = strchr(temp, '\n')) != NULL)
      *ptr = '\0';  /* newline durch \0 ersetzen */ 
   sscanf(temp, "%d", &auswahl);  

   str[0] = "DELETE FROM filmdaten WHERE "; 
   if(auswahl > 0 && auswahl < 5) {
      str[1] = malloc(strlen(item[auswahl-1])+1);
      strcpy(str[1], item[auswahl-1]);
   }
   else {
      printf("Kein solches Kriterium vorhanden!!!\n\n");
      return;
   }
   str[2] = " = '";

   printf("Bitte angaben fuer \'%s\' machen: ", item[auswahl-1]);
   fgets(del, 254, stdin);
   if( (ptr = strchr(del, '\n')) != NULL)
      *ptr = '\0';  /* newline durch \0 ersetzen */ 
   str[3] = malloc(strlen(del)+1); 
   strcpy(str[3], del); 
   str[4] = "'";

   for (i=0; i < 5; i++)
      size+=strlen(str[i]);
   /* Speicherplatz für den Anfragestring reservieren */  
   query = malloc(size + 1);
   strcpy(query, str[0]);
   for(i = 1; i < 5; i++)
      strcat(query, str[i]);
   /* Als Test für die Konsole */
   /* printf("%s",query);      */

   /* Jetzt die Anfrage an den Datenbankserver */
   mysql_real_query(mysql, query, strlen(query));
   check_error();
   if((affected=(unsigned long)mysql_affected_rows(mysql))<= 0 ){ 
      printf("Kein Datensatz von dieser Anfrage betroffen\n");
      check_error();
   }
   else
       printf("%ld %s von dieser Anfrage betroffen\n\n",
        affected, (affected == 1) ? "Datensatz war" :
        "Datensaetze waren" );
   free(query);
}


void filmdaten_aendern(void) {
   char change[255],replace[255], temp[4];
   char *item[] = {"titel", "hauptrolle", "fsk", "gedreht" };
   char *ptr;
   char *str[8], *query;
   int auswahl1, auswahl2, i, size=0;
   unsigned int integer;
   unsigned long affected;

   printf("Welche Daten wollen Sie aendern (Suchkriterium)\n");
   printf("[1]=Titel  [2]=Hauptrolle  "
          "[3]=FSK  [4]=Datum  : [ ]\b\b");

   fgets(temp, 3, stdin);
   if( (ptr = strchr(temp, '\n')) != NULL)
      *ptr = '\0';  /* newline durch \0 ersetzen */ 
   sscanf(temp, "%1d", &auswahl1); 

   printf("Welchen Inhalt suchen Sie fuer %s:",item[auswahl1-1]);
   fgets(change, 254, stdin);
   if( (ptr = strchr(change, '\n')) != NULL)
      *ptr = '\0';  /* newline durch \0 ersetzen */ 

   printf("Welche Daten sollen ersetzt werden"
          " (Ersetzkriterium)\n");
   printf("[1]=Titel  [2]=Hauptrolle  "
          "[3]=FSK  [4]=Datum  : [ ]\b\b");

   fgets(temp, 3, stdin);
   if( (ptr = strchr(temp, '\n')) != NULL)
      *ptr = '\0';  /* newline durch \0 ersetzen */ 
   sscanf(temp, "%1d", &auswahl2); 

   printf("Welchen Inhalt soll %s haben: ",item[auswahl2-1]);
   fgets(replace, 254, stdin);
   if( (ptr = strchr(replace, '\n')) != NULL)
      *ptr = '\0';  /* newline durch \0 ersetzen */ 

   /* Alle Daten vorhanden, um Querystr zu erzeugen */ 

   str[0] = "UPDATE filmdaten SET "; 
   if(auswahl2 > 0 && auswahl2 < 5) {
      str[1] = malloc(strlen(item[auswahl2-1])+1); 
      strcpy(str[1], item[auswahl2-1]);
   }
   else {
      printf("Kein solches Kriterium vorhanden!!!\n\n");
      return;
   }
   str[2] = "=";

   /* Integerwerte ? */  
   if(auswahl2==3 || auswahl2==4) {
      sscanf(replace, "%u", &integer);
      str[3] = malloc(5);
      sprintf(str[3], "%4d", integer);
   }
   else { /* ... dann ist es ein str */
      str[3] = malloc(strlen(replace)+3); 
      strcpy(str[3], "'");
      strcat(str[3], replace);
      strcat(str[3], "'");
   }
   str[4] = " WHERE ";
   if(auswahl1 > 0 && auswahl1 < 5) {
      str[5] = malloc(strlen(item[auswahl1-1])+1); 
      strcpy(str[5], item[auswahl1-1]);
   }
   else {
      printf("Kein solches Kriterium vorhanden!!!\n\n");
      return;
   }
   str[6] = "=";

   /* Integerwerte ? */  
   if(auswahl1==3 || auswahl1==4) {
      sscanf(change, "%u", &integer);
      str[7] = malloc(5);
      sprintf(str[7], "%4d", integer);
   }
   else { /* ... dann ist es ein str */
      str[7] = malloc(strlen(change)+3); 
      strcpy(str[7], "'");
      strcat(str[7], change);
      strcat(str[7], "'");
   }
   for (i=0; i < 8; i++)
      size+=strlen(str[i]);
   /* Speicherplatz für den Anfragestr reservieren */  
   query = malloc(size + 1);
   strcpy(query, str[0]);
   for(i = 1; i < 8; i++)
      strcat(query, str[i]);

   /* printf("%s",query); */

   /* Jetzt die Anfrage an den Datenbankserver */
   mysql_real_query(mysql, query, strlen(query));
   check_error();
   if((affected=(unsigned long)mysql_affected_rows(mysql))<=0) {
      printf("Kein Datensatz von dieser Anfrage betroffen\n");
      check_error();
   }
   else
      printf("%ld %s von dieser Anfrage betroffen\n\n",
        affected, (affected == 1) ?"Datensatz war" : 
        "Datensaetze waren");
   free(query);
}

void schauspieler_suchen(char *name) {
   unsigned long  anzahl_reihen;
   unsigned int i;
   MYSQL_ROW  row;  
   MYSQL_RES  *mysql_res;

   char *query, *string;
   char *select = "SELECT * FROM filmdaten WHERE hauptrolle='";
   string = malloc(strlen(name)+2);
   strcpy(string,name);
   strcat(string, "'");
   query =(char *) malloc(strlen(select)+strlen(string)+1);
   strcpy(query, select);
   strcat(query, string);

   /* Jetzt die Anfrage an den Datenbankserver */
   mysql_real_query(mysql, query, strlen(query));
   check_error();
   /* Daten der Anfrage abholen */
   mysql_res = mysql_store_result(mysql);
   check_error();
   /* Anzahl der gefundenen Datensätze ermitteln */
   anzahl_reihen = (unsigned long) mysql_num_rows (mysql_res);
   printf ("Anzahl gefunden: %lu\n\n", anzahl_reihen);
   /* Gefundenen Datensatz bzw. Datensätze ausgeben */
   while ((row = mysql_fetch_row (mysql_res)) != NULL) {
      /* Einzelne Spalten der Zeile ausgeben */
      for (i = 0;  i < mysql_num_fields(mysql_res);  i ++)
         printf ("%s ",row[i]);
      printf("\n");
   }
   /* Speicherplatz wieder freigeben */
   mysql_free_result(mysql_res);
   free(string);
   free(query);
}
void alle_daten_ausgeben(void) {
   unsigned int  i, col_len;
   MYSQL_ROW  row;  
   MYSQL_RES  *res;
   MYSQL_FIELD  *field;

   /* Jetzt die Anfrage an den Datenbankserver */
   mysql_real_query(mysql, "SELECT * FROM filmdaten",
      strlen("SELECT * FROM filmdaten"));
   check_error();
   /* Anfrage vom Server in die Struktur MYSQL_RES laden */
   res = mysql_store_result(mysql);
   check_error();

   /* offset = 0 bedeutet auf den Anfang der Zeile setzen */
   mysql_field_seek (res, 0);

   /* Damit bei der Ausgabe ein einheitliches Bild entsteht,
    * sollen die Daten für die max. Länge einer Spalte bei jeder
    * einzelnen (MYSQL_FIELD)-Spalte verändert werden */
   for (i = 0; i < mysql_num_fields(res); i++) {
      field = mysql_fetch_field (res);
      /* Länge des Namens in der Spalte ermitteln */
      col_len = strlen (field->name);
      /* Ist die Länge des Elements in der Spalte kleiner als
         die max. Länge ... */
      if (col_len < field->max_length)
      /* ... dann bekommt col_len den Wert der max. erl. Länge
             der Spalte */
         col_len = field->max_length;
      /* Für den Fall, dass eine Spalte keine Daten
         beinhaltet ... */  
      if (col_len < 4 && !IS_NOT_NULL (field->flags))
      /* col_len bekommt den Wert 4 für den String 
         "NULL" ->kein Daten */
         col_len = 4;
      /* max. Länge von Spalten-Info verändern */
      field->max_length = col_len;  
   }
   /* Namen der Tabelle ausgeben */
   printf("Daten der Tabelle: [ %s ]\n", field->table);
   print_line(res);
   printf("|");
   /* Alles wieder auf den Anfang stellen */
   mysql_field_seek (res, 0);
   /* Jetzt den Tabellenkopf ausgeben (titel, hauptrolle, fsk,
    * gedreht) */
   for (i = 0; i < mysql_num_fields (res); i++)  {
      field = mysql_fetch_field (res);
      printf (" %-*s |", field->max_length, field->name);
   }
   printf("\n");
   print_line(res);

   /* Jetzt die Daten aus der Struktur MYSQL_RES zeilenweise 
    * einlesen  */
   while ((row = mysql_fetch_row (res)) != NULL) {
      mysql_field_seek (res, 0);
      printf("|");
      for (i = 0; i < mysql_num_fields (res); i++) {
         /* Spalte für Spalte abarbeiten */
         field = mysql_fetch_field (res);
         /* Keine Daten in dieser Spalte */
         if (row[i] == NULL)
            printf (" %-*s |", field->max_length, "NULL");
         /* Handelt es sich um ein numerisches Feld */
         else if (IS_NUM (field->type))
            /* Dann wird der Inhalt rechtsbündig formatiert
             * ausgegeben */
            printf (" %*s |", field->max_length, row[i]);
         else
            /* Der Wert der Spalte ist ein String, also
             * linksbündige Ausgabe */
            printf (" %-*s |", field->max_length, row[i]);
      }
      printf("\n");
   }
   print_line(res);
   mysql_free_result(res);
}

void print_line(MYSQL_RES *res) {
   MYSQL_FIELD   *field;
   unsigned int  i, j;

   mysql_field_seek (res, 0);
   /* Erstes Zeichen der Linie */
   printf("+");
   for (i = 0; i < mysql_num_fields(res); i++) {
      field = mysql_fetch_field(res);
      /* max_length '-' Zeichen jeder Spalte ausgeben */
      for (j = 0; j < field->max_length + 2; j++)
         printf("-");
      /* Am Ende der Spalte '+' ausgeben */
      printf("+");
   }
   printf("\n");
}


int main (int argc, char **argv) {
  int auswahl;
  char darsteller[255];
  char *ptr;
  
  printf("Baue verbindung zur Datenbank auf ...\n\n");
  verbinden();
  db_waehlen("dvd_archiv"); 
  
  do {
     printf("\n-1- Filmdaten hinzufuegen\n");
     printf("-2- Filmdaten loeschen\n");
     printf("-3- Filmdaten aendern\n");
     printf("-4- Alle Filmdaten ausgeben\n");
     printf("-5- Film suchen\n");
     printf("-6- Programm beenden\n\n");
     printf("Ihre Auswahl : ");
     scanf("%d",&auswahl);
     getchar();

     switch(auswahl) {
        case 1: filmdaten_anfuegen();
                break;
        case 2: filmdaten_loeschen();
                break;
        case 3: filmdaten_aendern();
                break;
        case 4: alle_daten_ausgeben();
                break;
        case 5: printf("Suchkriterium Schauspieler " 
                   "(Name eingeben): ");
                fgets(darsteller, 254, stdin);
                if((ptr=(char *)strchr(darsteller, '\n'))!= NULL)
                   /* newline durch \0 ersetzen */
                   *ptr = '\0';  
                schauspieler_suchen(darsteller);
                break;
        case 6: printf("...beende Verbindung zur Datenbank\n");
                break;
        default:printf("Falsche Eingabe\n\n");
     }
  } while(auswahl != 6);
  verbindung_schliessen(); 
  return EXIT_SUCCESS;
}

