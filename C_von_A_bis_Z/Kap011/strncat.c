/* strncat.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15

int main(void) {
   char string[MAX] = "Hallo ";
   char puffer[20];
   /* Vorhandenen Platz in string ermitteln*/
   size_t len = MAX - strlen(string)+1;

   printf("Ihr Name: ");
   fgets(puffer, 20, stdin);
   strncat(string, puffer, len);
   printf("%s",string);
   return EXIT_SUCCESS;
}

