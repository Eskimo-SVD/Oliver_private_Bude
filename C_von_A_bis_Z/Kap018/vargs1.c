/* vargs1.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int add(int zahlen, ...) {
   va_list zeiger;
   int zahl;

   va_start(zeiger,zahlen);   
   do {
      zahl = va_arg(zeiger,int);
      zahlen += zahl;
   } while(zahl != 0);
      
   va_end(zeiger);
   return zahlen;
}

int main(void) {
   int erg;

   printf("%d\n",add(11,12,13,0));
   printf("%d\n",add(99,66,33,22,11,0));
   erg = add(10, 13, 11, 0) + add(9, 8, 11, 0);
   printf("%d\n",erg);   
   return EXIT_SUCCESS;
}

