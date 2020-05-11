/* string7.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char str[100];

   printf("Geben sie ein paar Wörter ein : ");
   fgets(str, 100, stdin);
   printf("Ihre Eingabe: %s\n",str);
   return EXIT_SUCCESS;
}

