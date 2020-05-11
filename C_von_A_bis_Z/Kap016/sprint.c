/* sprint.c */
#include <stdio.h>
#include <stdlib.h>
#define BUF 255

int main(void) {
   char string1[BUF];
   char string2[BUF];
   int anzahl = 10;
   char gegenstand[] = "Kartoffel";
   float liter = 1.55f;
   char fluessigkeit[] = "Limo";

   sprintf(string1, "%d kg %s\n",anzahl,gegenstand);
   sprintf(string2, "%.2f Liter %s\n",liter,fluessigkeit);

   printf("%s",string1);
   printf("%s",string2);
   return EXIT_SUCCESS;
}

