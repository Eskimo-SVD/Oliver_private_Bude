/* strstr.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char string[] = "Das ist ein Teststring";
   char suchstring[] = "ein";

   if( strstr(string, suchstring) != NULL)
      printf("Suchstring \"%s\" gefunden\n", suchstring);
   return EXIT_SUCCESS;
}

