/* search_and_replace.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define STRING_MAX 8192

int wort_begrenzer(char c) {
   return (c == ' ' || c == '\n' || c == '\t' || c == '\0' ||
       c == '.' || c == ',' || c == ';' || c == '!' ||c == '?');
}

/* Newline von fgets() entfernen */
void chomp(char *str) {
 size_t p=strlen(str);
 str[p-1] = '\0';
}

int main(int argc, char *argv[]) {
   FILE *file, *copy;
   char alt_string[STRING_MAX+1],neu_string[STRING_MAX+1],
        such_wort[STRING_MAX+1],replace_wort[STRING_MAX+1],
        *zgr;
   char puffer[STRING_MAX+1];
   int such_wortlen, i=0,w;
   size_t len=0;

   if(argc < 2) {
      fprintf(stderr, "Verwendung: %s datei\n", *argv);
      return EXIT_FAILURE;
   }
   file = fopen(argv[1],"r");    /* Datei zum Lesen öffnen     */
   copy = fopen(argv[1],"r+");   /* Datei zum Schreiben öffnen */
   if(file == NULL || copy == NULL) {
      printf("Fehler bei fopen()...\n");
      return EXIT_FAILURE;
   }
   alt_string[0]='\0';
   /* Kompletten String in alt_string legen ...  */
   /* Bitte ggf. selbst durch dynamische Speicherverwaltung 
     * genügend Platz schaffen! */
   while( (fgets(puffer,STRING_MAX+1,file)) != NULL ) {
      len += strlen(puffer)+1;
      if(len < STRING_MAX)
         strcat(alt_string, puffer);
      else {
         printf("Puffergroesse ueberschritten!\n");
         break;
      }
   }
   neu_string[0]='\0';

   printf("Welches Wort wollen Sie ersetzen : ");
   fgets(such_wort, STRING_MAX, stdin );
   chomp(such_wort);

   such_wortlen = strlen(such_wort); /* Länge des Suchwortes */
   for(w = 0; w < such_wortlen; w++)
   /* Nach Wortbegrenzern duchlaufen ... */
   if(wort_begrenzer(such_wort[w])) {
      printf("Keine Wortbegrenzer im Suchwort!!!\n");
      return EXIT_FAILURE;
   }
   printf("Durch welches Wort wollen Sie ersetzen : ");
   fgets(replace_wort, STRING_MAX, stdin);
   chomp(replace_wort);
   i = 0;
   while(1){
      if( (zgr=strstr(&alt_string[i], such_wort)) == NULL) {
         /* Kein Wort zu ersetzen */
         strcat(neu_string, &alt_string[i]);
         break;
      }
      else { /*..ansonsten von Byte i bis zgr in neu_string*/
         strncat(neu_string, &alt_string[i], zgr-&alt_string[i]);
         /* Jetzt überprüfen, ob wir ein Wort haben und
          * keinen Teilstring oder das Wort am Anfang steht */
         if( (zgr-&alt_string[0]==0 || 
              wort_begrenzer( *(zgr-1))) &&
              wort_begrenzer( *(zgr+such_wortlen))) {
            strcat(neu_string, replace_wort);
            /* Nach ersetztem Wort den Zeiger setzen ... */
            i += zgr + such_wortlen-&alt_string[i];
         }
         else {
            strncat(neu_string, zgr, 1);
            i += zgr + 1-&alt_string[i];
         }
      }
   } /* Ende while(1) */
   /* Für Testausgabe ... */
   /* printf("Neuer String : %s\n",neu_string); */
   strcpy(alt_string, neu_string);
   /* Achtung jetzt wirds ernst,
    * für Testausgabe in Kommentar setzen*/
   fputs(alt_string, copy);
   neu_string[0] = '\0';
   return EXIT_SUCCESS;
}

