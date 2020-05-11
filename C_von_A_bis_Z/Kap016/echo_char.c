/* echo_char.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int c;

   while( (c = getchar()) !='.')
      putchar(c);
   return EXIT_SUCCESS;
}

