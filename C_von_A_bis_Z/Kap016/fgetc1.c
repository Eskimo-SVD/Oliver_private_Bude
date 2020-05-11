/* fgetc1.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int c;
   FILE *datei;

   datei=fopen("test.txt", "r");
   if(datei != NULL) {
      while( (c=fgetc(datei)) != EOF)
         putchar(c);
   }
   else {
      printf("Konnte Datei nicht finden bzw. öffnen!\n");
      return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}

