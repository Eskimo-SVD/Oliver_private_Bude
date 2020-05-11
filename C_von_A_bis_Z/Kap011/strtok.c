/* strtok.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char string[] = "Ein Teststring mit mehreren Worten\n"
                   "und mehreren Zeilen.\t Ende\n";
   int i=1;
   char *ptr; 

   ptr = strtok(string, "\n\t ");
   while(ptr != NULL) {
      printf("% d. Wort: %s\n",i++,ptr);
      ptr = strtok(NULL, "\n\t ");
   }    
   return EXIT_SUCCESS;
}

