/* more_mem.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF 8192

int main(void) {
   char *buffer;
   int reserviert=0;
   int i;
   static size_t len = BUF; /* Speicheranforderung */

   buffer = malloc(sizeof("Hallo Welt"));
   strcpy(buffer, "Hallo Welt"); 

   while(reserviert != BUF && len != 0) {
      buffer = realloc(buffer, len);
      /* Speicher konnte nicht alloziert werden */
      if(buffer == NULL) {
         len /= 2;  /* Versuchen wir es mit der Hälfte */
      } 
      else {
         reserviert += len;
      } 
   }

   for(i = 0; i < reserviert; i++)
      buffer[i] = 'x';
   buffer[i]='\0';
   printf("\n%s\n",buffer);
   return EXIT_FAILURE;
}

