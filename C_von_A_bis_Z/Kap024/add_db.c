/* add_db.c */
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

#define MAX_PAARE 255
#define BUF 255

struct CGI_DATEN {
   char *variable;
   char *wert;
   struct CGI_DATEN *next;
};

struct CGI_DATEN *ende = NULL;

MYSQL *mysql;

void print_html(void);
char *getdata(void);
char *Strdup(const char *);
void hex2ascii(char *);
char convert(char *);
void loeschen(struct CGI_DATEN *);
struct CGI_DATEN *erstellen(char *);
void check_error(void);
void verbinden(void);
void verbindung_schliessen(void);

/* Weiterleitung zu einer URL
 * url ist die URL, wo Sie den User weiterleiten
 */
void print_html(void) {
   printf("<html><head>\n");
   printf("<title>Eintragsbest�tigung</title>\n");
   printf("</head><body>\n");
   printf("Eintragung erfolgreich. Zur�ck gehts"
          " <a href=\"javascript:history.back()\">hier</a>");
   printf("</body></html>\n");
}

/*  Funktion liest Daten in der POST oder GET-Methode ein.
 *  R�ckgabewert: Stringpuffer mit den Daten
 *  bei Fehler  : NULL
*/
char *getdata(void) {
   unsigned long size;
   char *puffer = NULL;
   char *request = getenv("REQUEST_METHOD");
   char *cont_len;
   char *cgi_string;
 
   /* Zuerst die Request-Methode �berpr�fen */
   if(  NULL == request )
      return NULL;
   else if( strcmp(request, "GET") == 0 ) {
      /* Die Methode GET -> Query String abholen */
      cgi_string = getenv("QUERY_STRING");
      if( NULL == cgi_string )
         return NULL; 
      else {
         puffer = Strdup(cgi_string);
         return puffer; /* R�ckgabewert an den Aufrufer */
      }
   }
   else if( strcmp(request, "POST") == 0 ) {
      /* Die Methode POST -> L�nge des Strings 
       * ermitteln (CONTENT_LENGTH) */
      cont_len = getenv("CONTENT_LENGTH");
      if( NULL == cont_len)
         return NULL;
      else {  /* String CONTENT_LENGTH in 
               * unsigned long umwandeln */
         size = (unsigned long) atoi(cont_len);
         if(size <= 0)
            return NULL; /* Keine Eingabe!?!? */
      }
      /* Jetzt lesen wir die Daten von stdin ein */
      puffer = malloc(size+1);
      if( NULL == puffer )
         return NULL;
      else {
         if( NULL == fgets(puffer, size+1, stdin) ) {
            free(puffer);
            return NULL;
         }
         else   /* R�ckgabewerte an den Ausrufer */
            return puffer; 
      }
   }
   /* Weder GET-Methode noch die POST-Methode wurden verwendet */
   else
      return NULL; 
}

/*  Da die Funktion strdup() in der Headerdatei <string.h> keine
 *  ANSI C-Funktion ist, schreiben wir eine eigene 
 */
char *Strdup(const char *str) {
   char *p;
   if(NULL == str)
       return NULL;
   else {
      p = malloc(strlen(str)+1);
      if(NULL == p)
         return NULL;
      else
         strcpy(p, str);
   }
   return p;
}

/* Wandelt einzelne Hexzeichen (%xx) in ASCII-Zeichen
 * und kodierte Leerzeichen (+) in echte Leerzeichen um */
void hex2ascii(char *str) {
   int x, y;

   for(x=0,y=0; str[y] != '\0'; ++x,++y) {
      str[x] = str[y];
      /* Ein hexadezimales Zeichen ? */
      if(str[x] == '%') {
         str[x] = convert(&str[y+1]);
         y += 2;
      }
      /* Ein Leerzeichen ? */  
      else if( str[x] == '+')
         str[x]=' ';
   }
   /* Geparsten String sauber terminieren */
   str[x] = '\0';
}

/* Funktion konvertiert einen String von zwei hexadezimalen
 * Zeichen und gibt das einzelne daf�r stehende Zeichen zur�ck
 */
char convert(char *hex) {
   char ascii;

   /* erster Hexawert */
   ascii =
   (hex[0] >= 'A' ? ((hex[0] & 0xdf) - 'A')+10 : (hex[0] - '0'));
   ascii <<= 4; /* Bitverschiebung schneller als ascii*=16 */
   /* zweiter Hexawert */
   ascii +=
   (hex[1] >= 'A' ? ((hex[1] & 0xdf) - 'A')+10 : (hex[1] - '0'));
   return ascii;
}

/* Liste aus Variable/Wert-Paaren erstellen 
 * R�ckgabewert: Anfangsadresse der Liste
 * Bei Fehler: NULL
 */
struct CGI_DATEN *erstellen(char *str) {
   char* s;
   char* res;
   /* Irgendwo gibt es auch eine Grenze, hier sind
      MAX_PAARE erlaubt */
   char *paare[MAX_PAARE];
   struct CGI_DATEN *ptr_daten = NULL;
   struct CGI_DATEN *ptr_anfang = NULL;
   int i=0, j=0;

   /* Zuerst werden die Variablen/Werte-Paare anhand des Zeichens 
    * '&' getrennt, sofern es mehrere sind  */
   s=str;
   res=strtok(s,"&");
   while( res != NULL && i < MAX_PAARE) {
      /* Wert von res dynamisch in char **pair speichern */
      paare[i] = (char *)malloc(strlen(res)+1);
      if(paare[i] == NULL)
         return NULL;
      paare[i] = res;
      res=strtok(NULL,"&");
      i++;
   }
   /* Jetzt werden die Variablen von den Werten getrennt und 
    * an die Struktur CGI_DATEN �bergeben   */
   while ( i > j ) {  /* Das erste Element ? */
      if(ptr_anfang == NULL) {
         ptr_anfang = malloc(sizeof (struct CGI_DATEN));
         if( ptr_anfang == NULL )
            return NULL;
         res = strtok( paare[j], "=");
         if(res == NULL)
            return NULL;
         ptr_anfang->variable = malloc(strlen(res)+1);
         if( ptr_anfang->variable == NULL )
            return NULL;
         ptr_anfang->variable = res;
         res = strtok(NULL, "\0");
         if(res == NULL)
            return NULL;
         ptr_anfang->wert = malloc(strlen(res)+1);
         if( ptr_anfang->wert == NULL )
            return NULL;
         ptr_anfang->wert = res;
         /* printf("%s %s<br>",
          * ptr_anfang->variable, ptr_anfang->wert); */
         ptr_anfang->next = malloc(sizeof (struct CGI_DATEN)); 
         if(ptr_anfang->next == NULL)
            return NULL;
         ptr_daten = ptr_anfang->next; 
         j++;
      }
      else { /* Die restlichen Elemente */
         res = strtok( paare[j], "=");
         if(res == NULL)
            return NULL;
         ptr_daten->variable = malloc(strlen(res)+1);
         if(ptr_daten->variable == NULL)
            return NULL;
         ptr_daten->variable = res;
         res = strtok(NULL, "\0");
         if(res == NULL)
            return NULL;
         ptr_daten->wert = malloc(strlen(res)+1);
         if(ptr_daten->wert == NULL)
            return NULL;
         ptr_daten->wert = res;
         /* printf("%s %s<br>",
          * ptr_daten->variable, ptr_daten->wert); */
         ptr_daten->next = malloc(sizeof (struct CGI_DATEN));
         if( ptr_daten->next == NULL )
            return NULL;
         ptr_daten = ptr_daten->next; 
         j++;
      } 
   }
   ende = ptr_daten;
   /* Anfangsadresse der Liste struct CGI_DATEN zur�ckgeben */
   return ptr_anfang;
}

/* Bricht bei Fehler (mysql_error != 0) das Programm ab */
void check_error(void)  {
   if (mysql_errno(mysql) != 0) {
      fprintf(stderr, "Fehler: %s\n", mysql_error(mysql));
      exit(EXIT_FAILURE);
   }
}

/* Baut eine Verbindung zum Datenbankserver auf.
 * Passen Sie ggf. Usernamen und Passwort und, sofern
 * andere Parameter ben�tigt werden, diese Ihren Umst�nden
 * selbst an
*/
void verbinden(void)  {
   mysql= mysql_init(mysql);
   check_error();
   mysql_real_connect(mysql, "localhost", "root",
      NULL, NULL, 0, NULL, 0);
   check_error();
}

/* Serververbindung wieder schlie�en und den Speicher f�r die 
 * Struktur MYSQL wieder freigeben */
void verbindung_schliessen(void)  {
   mysql_close(mysql);
}

/* Falls Datenbank bei der Funktion verbinden() nicht angegeben
 * wurde oder Sie die Datenbank wechseln wollen, dann verwenden
 * Sie diese Funktion  */
void db_waehlen(char *db) {
   mysql_select_db(mysql, db);
   check_error();
}

/* Daten mit mysql_real_query() in die Datenbank schreiben */
void daten_anfuegen(struct CGI_DATEN *daten) {
   char buf[BUF] = "INSERT INTO daten (name, adresse) VALUES ('";

   strcat(buf, daten->wert);
   strcat(buf, "', '");
   daten = daten->next;
   strcat(buf, daten->wert);
   strcat(buf, "');");

   /* Jetzt die Anfrage an den Datenbankserver */
   mysql_real_query(mysql, buf, strlen(buf));
   check_error();
}

int main(void) {
   char *str;
   struct CGI_DATEN *cgi;
   struct CGI_DATEN *free_cgi;

   /* F�r Fehlermeldungen */
   printf("Content-Type: text/html\n\n");
   /* Eingabe einlesen */
   str = getdata();
   if(str == NULL) {
      printf("Fehler beim Einlesen von der Formulareingabe");
      return EXIT_FAILURE;
   }
   /* Hexzeichen in ASCII-Zeichen konvertieren und aus '+'
    * Leerzeichen machen */
   hex2ascii(str);
   /* Liste der Formualar-Daten erstellen */
   cgi = erstellen(str);
   free_cgi = cgi;
   if (cgi == NULL) {
      printf("Fehler beim Erstellen der "
             "Variablen/Werte-Liste!!\n");
      return EXIT_FAILURE;
   }
   verbinden();
   db_waehlen("mail_archiv");
   daten_anfuegen(cgi);

   verbindung_schliessen();
   print_html();
   return EXIT_SUCCESS;
}

