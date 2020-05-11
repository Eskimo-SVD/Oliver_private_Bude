/* malloc4.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF 80

int main(void) {
   char puffer[BUF];
   char *dyn_string;
   
   printf("Ein Text mit max. 80 Zeichen: ");
   fgets(puffer, BUF, stdin);
   
   dyn_string = malloc(strlen(puffer) + 1);
   if(dyn_string != NULL)
      strncpy(dyn_string, puffer, strlen(puffer) + 1);
   else {
      printf("Konnte keinen Speicherplatz reservieren\n");
      return EXIT_FAILURE;
   }
   printf("%s",dyn_string);
   free(dyn_string);
   return EXIT_SUCCESS;
}

