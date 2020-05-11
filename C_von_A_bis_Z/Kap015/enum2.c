/* enum2.c */
#include <stdio.h>
#include <stdlib.h>

enum BOOL { FALSE, TRUE };

int main(void) {
   int zahl; 
   printf("Gib mir eine Zahl (0-9): ");

   if( (scanf("%d",&zahl)) == FALSE )
      printf("Das war keine Zahl!\n");
   else 
      printf("Vielen Dank!\n");

   if( (zahl==7) == TRUE)
      printf("Wow, die 7, meine Lieblingszahl\n");
   return EXIT_SUCCESS;
}

