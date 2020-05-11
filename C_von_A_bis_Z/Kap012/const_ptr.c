/* const_ptr.c */
#include <stdio.h>
#include <stdlib.h>

void funktion1(char *str) {
   char *ptr;

   ptr = str+5;
   *ptr = '-';
}

int main(void) {
   char string1[] = "Hallo Welt\n";

   funktion1(string1);
   printf("%s\n",string1);
   return EXIT_SUCCESS;
}

