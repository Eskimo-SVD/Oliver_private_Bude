/* strchr.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char str[] = "Ein String mit Worten";

   printf("%s\n",strchr(str, (int)'W'));
   return EXIT_SUCCESS;
}

