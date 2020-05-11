/* search_string.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF 255

int main(int argc, char *argv[]) {
   FILE *f;
   char searchstring[BUF], puffer[BUF];
   int counter = 1;

   if(argc < 2) {
      fprintf(stderr, "Verwendung : %s datei\n", *argv);
      return EXIT_FAILURE;
   }
   f = fopen(argv[1], "r");
   if(f == NULL) {
      printf("Fehler bei fopen()... \n");
      return EXIT_FAILURE;
   }
   printf("Wonach suchen Sie in %s : ", argv[1]);
   scanf("%s", searchstring);
   printf("\n");

   while( fgets(puffer, BUF, f) != NULL ) {
      if(strstr(puffer,searchstring) != 0)
         printf("Zeile %d : %s",counter,puffer);
      counter++;
   }
   printf("\n");
   return EXIT_SUCCESS;
}

