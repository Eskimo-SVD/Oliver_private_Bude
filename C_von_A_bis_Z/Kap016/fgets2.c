/* fgets2.c */
#include <stdio.h>
#include <stdlib.h>
#define ZEILENLAENGE 80

int main(void) {
   FILE *quelle;
   char puffer[ZEILENLAENGE], name[20];

   printf("Welche Datei wollen Sie zum Lesen öffnen: ");
   scanf("%s",name);
   if( (quelle=fopen(name,"r")) == NULL) {
      fprintf(stderr, "Kann %s nicht oeffnen\n", name);
      return EXIT_FAILURE;
   }
   while(fgets(puffer, ZEILENLAENGE, quelle))
      fputs(puffer, stdout);
   return EXIT_SUCCESS;
}

