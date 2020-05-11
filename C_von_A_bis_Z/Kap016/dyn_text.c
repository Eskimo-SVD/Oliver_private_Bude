/* dyn_text.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* symb. Konstanten */
#define LINE 255       
#define ALLOC_LINE 10 

enum { SUCCESS, ERROR };

/* Funktions-Prototypen */
int read_file(char ***, char *, int *);
char **alloc_string_array(int, int);
int zeilen_hinzu_fuegen(char ***, int, int, int);
int string_anpassen(char **, int);
int string_groesse_veraendern(char **, int, int);
void free_string_array(char **, int);

/*  ***array == Ein Zeiger auf einen Zeiger einer Zeile mit 
 *  einem Zeiger auf die Länge der Zeile (*array[zeile][länge])  
 *  *fname == Name der zu öffnenden Datei
 *  *zeile_n == Zeiger auf Anzahl Zeilen
 *  Rückgabewert: SUCCESS wenn kein Fehler, ansonsten ERROR
 */          
int read_file(char ***array, char *fname, int *zeile_n) {
 char puffer[LINE] = {0}; /* Puffer zum zeilenweisen Einlesen  */
 char *newline = NULL;    /* Zeiger für neue Zeile             */
 FILE *f;                 /* Datei, welche geöffnet werden soll*/
 int error = SUCCESS;     /* Fehlerstatus                      */
 int zeile = 0;           /* aktuelle Zeile                    */
 int absatz_n;
 
 *zeile_n = 0;            /*Erste Zeile mit 0 initialisieren   */
 /* Speicher anfordern für ALLOC_LINE Zeilen a LINE Zeichen    */
 *array = alloc_string_array(ALLOC_LINE, LINE);
 if(NULL != *array) {
    f = fopen(fname, "r"); /* Datei fname zum Lesen öffnen */
    if(NULL != f) {
       *zeile_n = ALLOC_LINE; 
       absatz_n = 0;
       /* Solange kein Fehler auftritt, zeilenweise einlesen */
       while(0 == error && NULL != fgets(puffer, LINE, f)) {
          newline = strchr(puffer, '\n');
          if(NULL != newline)
             /* Newline-Zeichen gegen 
              * Terminierungszeichen austauschen */
               *newline = '\0'; 
             strcat( (*array)[zeile], puffer);
             if(NULL != newline) {
                absatz_n = 1;
                zeile++;
                /* Haben wir noch Platz im Speicher
                 * für weitere Zeilen */
                if(zeile >= *zeile_n) { 
                   /* Nein, dann an anfügen */
                   if(0 == zeilen_hinzu_fuegen(
                    array, *zeile_n, ALLOC_LINE, LINE) )
                      error = ERROR; 
                   else
                      /* Anzahl der Zeilen + 10 */
                      *zeile_n += ALLOC_LINE; 
                }
             }
             /* Kein Newline-Zeichen, dann Zeile länger als LINE
              * Zeichen, String der Länge anpassen  ->  Speicher
              * anfordern */
             else {
                absatz_n++;
                if(0 == string_groesse_veraendern(
                 *array, zeile, absatz_n * LINE))
                   error = ERROR;
             }   
       }/*while*/
       fclose(f);
       /* Wir sind am Ende vom Einlesen oder ein Fehler trat auf.
        * Es müssen allerdings noch die übrige(n) Zeile(n) in 
        * den Speicher eingelesen werden */
       if(0 == error && *zeile_n > zeile) {
          if(0 == zeilen_hinzu_fuegen(
           array, *zeile_n, zeile-*zeile_n, 0))
             error = ERROR; 
          *zeile_n = zeile;
       }        
    }
    else  /* Datei fname konnte nicht geöffnet werden */
       error = ERROR;
 }      
 else   /* Es konnte kein Speicher allokiert werden */
     error = ERROR;
 
 if(error != 0) { 
    /* Im Fall eines Fehler, Speicher wieder freigeben 
     * und Anzahl Zeilen auf 0 */
    free_string_array(*array, *zeile_n);
    *zeile_n = 0; 
 }
 else
     string_anpassen(*array, *zeile_n);
 return error;
} 

/*   zeilen_n == Anzahl Zeilen, wieviele reserviert werden sollen
 *   laenge   == Speicherplatz für die Länge jeder Zeile, 
 *               die angefordert wird
 *   Rückgabewert: Anfangsadresse des reservierten Speichers vom 
 *                 String-Array  (array[zeile][laenge])
 */
char **alloc_string_array(int zeilen_n, int laenge) {
 char **array = NULL;
 int zeile;
 int ret = SUCCESS;
   
 if(zeilen_n > 0 && laenge > 0) {
    /* Speicher für zeilen_n Zeilen reservieren */
    array = malloc(zeilen_n * sizeof(*array));
    if(NULL != array) {
       for(zeile=0; zeile < zeilen_n; zeile++) {
          /* Für jede zeile_n Zeile laenge Bytes 
           * Speicher reservieren */
          array[zeile] =
             malloc( laenge * sizeof(*array[zeile]) );
          if(NULL == array[zeile])
             ret = ERROR;
          else
             /*jede Zeile erstes Zeichen mit \0 initialisieren*/
             array[zeile][0] = '\0';
       }
       if(ERROR == ret) {  /* Bei Fehler Speicher freigeben */
          free_string_array(array, zeilen_n);
          array = NULL;
       }
    }
 }
 return array;
}

/*  ***array    == Ein Zeiger auf einen Zeiger einer Zeile mit 
 * einem Zeiger auf die Länge der Zeile ( *array[zeile][länge])  
 * alt_n_zeilen   == Anzahl akt. Zeilen im Speicher
 * n_zeilen_hinzu == Anzahl Zeilen, für die neuer Speicherplatz 
 * reserviert werden soll. Bei negativen Wert werden n Zeilen 
 * entfernt 
 * init_laenge    == Speicherplatz für die Länge jeder Zeile, die 
 *                   angefordert wird
 * Rückgabewert: 1 wenn Ok, ansonsten 0
*/  
int zeilen_hinzu_fuegen(char ***array_ptr, int alt_n_zeilen,
                        int n_zeilen_hinzu, int init_laenge) {
 char **ptr;
 int ret = 1;
 int zeile;
 int anzahl_alte_zeilen = alt_n_zeilen;

 /* Ein negativer Wert bedeutet Zeilen entfernen */
 if(n_zeilen_hinzu < 0) {
    for(zeile=anzahl_alte_zeilen-1; 
     zeile >= anzahl_alte_zeilen+n_zeilen_hinzu; zeile--)
       free( (*array_ptr)[zeile]);
 }
 /* Speicher für einzelne Zeilen reservieren */  
 ptr=realloc( *array_ptr, 
  (anzahl_alte_zeilen+n_zeilen_hinzu)*sizeof(**array_ptr));
 if(NULL != ptr) {
    *array_ptr = ptr;
    for(zeile=anzahl_alte_zeilen;
     ret && zeile < anzahl_alte_zeilen+n_zeilen_hinzu; zeile++) {
       /* Anzahl der Zeichen, welche jede Zeile 
        * aufnehmen kann, reservieren */
       (*array_ptr)[zeile] = malloc(init_laenge);
       if( NULL != (*array_ptr)[zeile])
          /* jede Zeile erstes Zeichen mit \0 initialisieren  */
          (*array_ptr)[zeile][0] = '\0';
       else
          ret = 0;
    }
 }    
 else
    ret = 0;
 return ret;
}

/*  **array_ptr == Ein Zeiger auf das String-Array
 *                 array[zeile][laenge]
 *      zeile_n == Anzahl Zeilen, welche angepasst werden
 * Rückgabewert bei Erfolg 0, ansonsten größer als 0
 */
int string_anpassen(char **array_ptr, int zeile_n) {
 int zeile;
 int anzahl_zeichen;
 int fehlschlag = 0;
 
 for(zeile = 0; zeile < zeile_n; zeile++) {
    /* Funktion strlen ließt das Terminierungszeichen
     * '\0' nicht mit -> daher +1 */
     anzahl_zeichen = strlen(array_ptr[zeile])+1;
     if(0 == string_groesse_veraendern(
      array_ptr, zeile, anzahl_zeichen))
        fehlschlag++;
 }
 return fehlschlag;
}

/*  **array_ptr == Ein Zeiger (Adresse) auf das String-Array 
 *  array[zeile][laenge]
 *      zeile   == Zeile, welche verändert werden soll
 * neu_laenge   == Anzahl Zeichen, die für die Zeile verändert 
 *                 werden soll 
 * Rückgabewert bei Erfolg SUCCESS, ansonsten bei Fehler ERROR
 */ 
int string_groesse_veraendern(char **array, int zeile, 
                              int neu_laenge) {
 char *ptr;
 int ret = SUCCESS;
 
 ptr = realloc(array[zeile], neu_laenge);
 if(ptr != NULL)
   array[zeile] = ptr;
 else 
   ret = ERROR; 
 return ret;
}

/*  **array_ptr == Ein Zeiger (Adresse) auf das String-Array
 *                 array[zeile][laenge]
 *    n_zeile   == Anzahl Zeilen, die freigegeben werden sollen*/
void free_string_array(char **array, int n_zeilen) {
 int zeile;

 if(array != NULL) {
    for(zeile= 0; zeile < n_zeilen; zeile++) {
       if(array[zeile] != NULL)
          free(array[zeile]);
    }  
 }
 free(array);
}
 
int main(void) { 
 char **array = NULL;
 char datei[255];
 int zeilen=0, i, auswahl, n, m;
 
 do {
    printf("Was wollen Sie tun?\n\n");
    printf("-1- Datei komplett in den Speicher einlesen\n");
    printf("-2- Inhalt der Datei im Speicher ausgeben\n");
    printf("-3- Datei im Speicher v. Zeile n bis m ausgeben\n");
    printf("-4- Den Speicher wieder freigeben\n");
    printf("-5- Ende\n\n");
    printf("Ihre Wahl : < >\b\b");
    scanf("%d",&auswahl);fflush(stdin);
    switch(auswahl) {
       case 1 : printf("Datei angeben( mit Pfadangabe ): ");
                scanf("%254s",datei);
                fflush(stdin);
                if( (read_file(&array, datei, &zeilen))==ERROR)
                    printf("Fehler beim Lesen in Speicher!!!\n");
                break;
       case 2 : if(zeilen == 0)
                   printf("Keine Daten vorhanden!\n");
                else
                   for(i=0; i<=zeilen-1; i++)
                      printf("%s\n",array[i]);
                break;
       case 3 : printf("Zeilenbeginn: ");
                scanf("%d",&n);
                fflush(stdin);
                if(n > 0 && n <= zeilen-1) {
                   printf("bis zur Zeile: ");
                   scanf("%d",&m);
                   fflush(stdin);
                   if(m >= n && m <= zeilen-1) {
                      for(i=n; i<=m-1; i++)
                         printf("%s\n",array[i]);
                   }
                   else
                      printf("?>>%d<<?\n",m);
                }
                else
                   printf("?>>%d<<?\n",n);
                break;
       case 4 : free_string_array(array, zeilen);
                zeilen=0;
                break; 
       default: break;
    }  
 } while(auswahl != 5);
 return EXIT_SUCCESS;
}

