/* ggt2.c */
#include <stdio.h>
#include <stdlib.h>

unsigned long ggt(unsigned long a, unsigned long b) {
   unsigned long count;

   if(a==b)
      return a;
   else if( (a % b) == 0)
      return b;
   else
      for(count = b; count > 0; count--) {
         if( ( (a % count) + (b % count) ) == 0)
            return count;
      }
	return 0;
}

int main(void) {
   unsigned long a, b, c;

   printf("ggt = größter gemeinsamer Teiler\n");
   printf("Zahl 1: ");
   scanf("%lu",&a);
   printf("Zahl 2: ");
   scanf("%lu",&b);
   if(a<b) { /* a und b vertauschen */
      c=a; a=b; b=c;
   }
   printf("Der ggT von %lu und %lu ist %lu\n", a, b, ggt(a,b));
   return EXIT_SUCCESS;
}
