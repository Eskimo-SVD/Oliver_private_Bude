/* fgetc2.c */
#include <stdio.h>
#include <stdlib.h>

void read_char(FILE *stream) {
   int c;

   while( (c=fgetc(stream)) !=EOF)
      putchar(c);
}

int main(int argc, char **argv) {
   FILE *datei;
   char filename[255];

   /* Falls die Datei zum �ffnen nicht 
    * als Argument �bergeben wurde ... */
   if(argc < 2) {
      printf("Welche Datei wollen sie �ffnen : ");
      scanf("%s",filename);
      datei = fopen(filename ,"r");
      if(datei != NULL)
         read_char(datei);
      else {
         printf("Fehler beim �ffnen von %s\n",filename);
         return EXIT_FAILURE;
      }
   }
   else {
      datei=fopen(argv[1],"r");
      if(datei != NULL)
         read_char(datei);
      else {
         printf("Konnte %s nicht �ffnen!\n",argv[1]);
         return EXIT_FAILURE;
      }   
   }
   return EXIT_SUCCESS;
}

