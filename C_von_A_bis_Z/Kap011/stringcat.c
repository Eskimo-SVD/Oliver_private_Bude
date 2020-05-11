/* stringcat.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char ziel[30] = "Hallo ";
   char name[20];

   printf("Wie heissen Sie: ");
   fgets(name, 20, stdin);

   strcat(ziel, name);
   printf("%s",ziel);
   return EXIT_SUCCESS;
}

