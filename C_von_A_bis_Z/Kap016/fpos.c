/* fpos.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   FILE *quelle;
   int c;
   char datei[20];
   fpos_t pos;

   printf("Welche Datei wollen Sie Öffnen : ");
   scanf("%s",datei);

   if( (quelle=fopen(datei,"r")) == NULL) {
      fprintf(stderr, "Konnte %s nicht oeffnen!!\n", datei);
      return EXIT_FAILURE;
   }
   /* Wir lesen die aktuelle Position unseres FILE-Zeigers */
   fgetpos(quelle,&pos);
   printf("Der Positionszeiger zeigt auf Byte : %ld\n",pos);

   while( (c=getc(quelle)) != EOF)
      putc(c,stdout);
   printf("Groesse der Datei= Byte : %ld\n", ftell(quelle));

   /* Wir setzen den FILE-Zeiger wieder zum Anfang der Datei */
   fsetpos(quelle,&pos);
   printf("Wir sind wieder an Position %ld\n",pos);
   return EXIT_SUCCESS;
}

