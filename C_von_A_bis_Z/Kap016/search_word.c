/* search_word.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF 255

/* Anpassen nach Bedarf... */
const char trennzeichen[] = ".;,:\"\' ";

int main(int argc, char *argv[]) {
   FILE *f;
   char searchstring[BUF];
   char puffer[BUF], puffer_bak[BUF];
   int counter=1;
   char *wort;

   if(argc < 2) {
      fprintf(stderr, "Verwendung : %s datei\n",*argv);
      return EXIT_FAILURE;
      }
   f=fopen(argv[1],"r");
   if(f == NULL) {
      printf("Fehler bei fopen()...");
      return EXIT_FAILURE;
   }
   printf("Wonach suchen Sie in %s : ",argv[1]);
   scanf("%s", searchstring);
   printf("\n");

   while(fgets(puffer, BUF, f) != NULL) {
      strcpy(puffer_bak, puffer);
      wort = strtok(puffer, trennzeichen);
      while(wort != NULL) {
         if(strcmp(wort,searchstring) == 0)
            printf("Zeile %d : %s",counter,puffer_bak);
         wort = strtok(NULL,trennzeichen);
      }
      counter++;
   }
   printf("\n");
   return EXIT_SUCCESS;
}

