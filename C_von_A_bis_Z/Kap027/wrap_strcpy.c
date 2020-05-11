/* wrap_strcpy.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX  10
 /* Damit es keine Kollision mit strcpy in string.h gibt */
#define strcpy Strcpy
#define DEBUG
/* #undef DEBUG */

void Strcpy(char *ziel, char *quelle) {
   int counter;
#ifdef DEBUG 
   /* DEBUG-INFO */
   size_t size = strlen(quelle)+1; 
   if( size > MAX )
      printf("DEBUG-INFO: Pufferüberlaufversuch\n");
   /* DEBUG-INFO Ende */
#endif

   for(counter=0; quelle[counter] != '\0' && counter < MAX-1;
     counter++)
      ziel[counter]=quelle[counter];
   /* Terminieren */
   ziel[counter] = '\0';
}

int main(int argc, char **argv) {
   char puffer[MAX];

   strcpy(puffer, "0123456789012345678");
   printf("puffer = %s\n",puffer);
   return EXIT_SUCCESS;
}

