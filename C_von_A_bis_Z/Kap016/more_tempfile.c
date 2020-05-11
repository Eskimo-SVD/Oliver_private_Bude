/* more_tempfile.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   FILE *tmp;
   int i;
   char tempdatei[L_tmpnam], zeile[1000];

   printf("Demo Funktion tmpnam ...\n");
   for(i = 1; i <= 4; i++) {
      if(i%2==0) {
         printf("%20d. %s\n",i,tmpnam(NULL));
      }
      else {
         tmpnam(tempdatei);
         printf("%20d. %s\n",i,tempdatei);
      }
   }
   printf("Demo Funktion tmpfile ...\n");
   tmp=tmpfile();
   if( NULL == tmp ) {
      fprintf(stderr,"Fehler bei tmpfile\n");
      return EXIT_FAILURE;
   }
   /* Wir schreiben mit fputs in die temporäre 
    * Datei, auf die tmp zeigt */
   fputs("Dieser Text wird in die temporäre"
         " Datei geschrieben\n", tmp);
   rewind(tmp);
   if(fgets(zeile,sizeof(zeile),tmp) == NULL) {
      fprintf(stderr, "Fehler bei fgets ...\n");
      return EXIT_FAILURE;
   }
   printf("%s\n",zeile);
   return EXIT_SUCCESS;
}

