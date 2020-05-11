/* grown_file.c */
#include <stdio.h>
#include <stdlib.h>

/* Bitte anpassen */
#define DATEI "datei.txt"

int main(void) {
   FILE *fp;
   int c;

   fp = fopen(DATEI, "r");
   if(fp == NULL) {
      fprintf(stderr, "Konnte %s nicht öffnen\n", DATEI);
      return EXIT_SUCCESS;
   }
   while(1) {   
      while( (c=fgetc(fp)) ) {      /* Zeichenweise einlesen */
         if(c == EOF)         /* Ist es EOF */
            ungetc(c,fp);     /* Letztes Zeichen zurück */
         else
            fputc(c, stdout); /* Ausgeben */
      }
   }
   /* Wird nie erreicht */
   fclose(fp);
   return EXIT_SUCCESS;
}

