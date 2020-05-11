/* strrchr.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char string[20];
   char *ptr;

   printf("Eingabe machen: ");
   fgets(string, 20 , stdin);
   /* Zeiger auf die Adresse des Zeichens \n */
   ptr = strrchr(string, '\n');
   /* Zeichen mit \0 überschreiben */
   *ptr = '\0';
   printf("%s",string);
   return EXIT_SUCCESS;
}

