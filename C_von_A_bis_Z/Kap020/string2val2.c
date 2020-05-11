/* string2val2.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char string1[] =  "256Vorrat";
   char string2[]=   "128Benoetigt";
   long zahl1, zahl2;
   
   zahl1 = atol(string1);
   zahl2 = strtol(string2, NULL, 10);   
   printf("zahl1: %ld; zahl2: %ld\n", zahl1, zahl2);
   return EXIT_SUCCESS;
}

