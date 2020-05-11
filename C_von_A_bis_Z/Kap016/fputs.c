/* fputs.c */
#include <stdio.h>
#include <stdlib.h>
#define ZEILENLAENGE 80

int main(void) {
   FILE *quelle, *kopie;
   char puffer[ZEILENLAENGE], name[20];

   printf("Welche Datei wollen Sie zum Lesen öffnen: ");
   scanf("%s",name);

   if( (quelle=fopen(name,"r")) == NULL) {
      fprintf(stderr,"Kann %s nicht oeffnen\n",name);
      return EXIT_FAILURE;
   }
   if( (kopie=fopen("kopie.txt","w")) == NULL) {
      fprintf(stderr,"Kann kopie.txt nicht oeffnen\n");
      return EXIT_FAILURE;
   }
   while(fgets(puffer,ZEILENLAENGE,quelle)) {
      fputs(puffer, kopie);
      puts(puffer);
   }
   return EXIT_SUCCESS;
}

