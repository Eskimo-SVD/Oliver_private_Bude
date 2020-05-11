/* ggt3.c */
#include <stdio.h>
#include <stdlib.h>

unsigned long ggt(unsigned long a, unsigned long b) {
   if(b == 0)
      return a;
   return ggt(b, a % b);
}

int main(void) {
   unsigned long a, b;

   printf("ggt = größter gemeinsamer Teiler(mit 0 beenden)\n");
   printf("Zahl> ");
   scanf("%lu", &a);
   printf("Zahl> ");
   scanf("%lu", &b);
   a=ggt(a, b);

   while(1) {
      printf("Zahl> ");
      scanf("%lu", &b);
      if(b==0)
         break;
      a=ggt(a, b);
   }
   printf("-------->ggt = %lu\n", a);
   return EXIT_SUCCESS;
}

