/* ggt1.c */
#include <stdio.h>
#include <stdlib.h>

unsigned long ggt(unsigned long a, unsigned long b) {
   if(a==b)
      return a;
   else if(a < b)
      return ggt(a, b-a);
   else
      return ggt(a-b, b);
}

int main(void) {
   unsigned long a, b;

   printf("ggt = größter gemeinsamer Teiler\n");
   printf("Zahl 1: ");
   scanf("%lu",&a);
   printf("Zahl 2: ");
   scanf("%lu",&b);
   printf("Der ggT von %lu und %lu ist %lu\n", a, b, ggt(a,b));
   return EXIT_SUCCESS;
}

