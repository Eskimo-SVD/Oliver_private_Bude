/* getline.c */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main(void) {
   FILE *fd;
   /* Bitte die Datei und event. den Pfad anpassen */
   char *datei = "/home/user/testdatei.txt";
   int nRet;
   size_t *t = malloc(0);

   char **gptr = malloc(sizeof(char*));
   *gptr = NULL;

   if ( (fd = fopen(datei,"r")) == NULL) {
      fprintf(stderr, "\nKonnte Datei %s nicht öffnen!", datei);
      return EXIT_FAILURE;
   }
   while( (nRet=getline(gptr, t, fd)) > 0)
      fputs(*gptr,stdout);
  return EXIT_SUCCESS;
}

