/* string3.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   /* Hallo!\n ... */
   char str[] = { 72, 97, 108, 108, 111, 33, 10, 0 }; 
   printf("%s\n",str);
   return EXIT_SUCCESS;
}

