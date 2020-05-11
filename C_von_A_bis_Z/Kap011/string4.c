/* string4.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int i;
   int str[] = { 72, 97, 108, 108, 111, 33, 10, 0 };

   for(i = 0; i < sizeof(str) / sizeof(int); i++)
      printf("%c", str[i]);
   return EXIT_SUCCESS;
}

