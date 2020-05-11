/* feof.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int c;

   while( (c = getc(stdin)) )
      if(feof(stdin) != 0)
         break;
      else
         putc(c,stdout);
   return EXIT_SUCCESS;
}

