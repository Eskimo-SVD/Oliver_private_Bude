/* file_cat.c */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
   FILE *quell,*ziel;
   char c;
   int i;

   if(argc < 3) {
      printf("Fehler!!!!\n");
      printf("Mindestens 3 Argumente angeben :\n");
      printf("<Programmname><Ziel><Quelle1>"
             "(<Quelle2><Quelle_n>) \n");
      return EXIT_FAILURE;
   }
   ziel = fopen(argv[1], "a+");
   if(ziel == NULL) {
      printf("Konnte \"%s\" nicht erstellen bzw. nicht"
             " finden!\n", argv[1]);
      return EXIT_FAILURE;
   }

   for(i = 2; i < argc; i++) {
      if(argv[i] != NULL) {
         quell = fopen(argv[i], "r");
         if(NULL == quell) {
            printf("Konnte %s nicht öffnen\n", argv[i]);
            return EXIT_FAILURE;
         }
         else {
            while((c=getc(quell)) != EOF)
               putc(c,ziel);
            fclose(quell);
         }
      }
   }
   fclose(ziel);
   return EXIT_SUCCESS;
}

