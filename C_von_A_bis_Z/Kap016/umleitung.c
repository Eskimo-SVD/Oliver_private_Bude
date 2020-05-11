/* umleitung.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int c;

   while((c=getc(stdin)) != EOF)
      putc(c,stdout);
   return EXIT_SUCCESS;
}

