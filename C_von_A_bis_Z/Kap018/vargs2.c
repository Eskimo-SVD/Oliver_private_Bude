/* vargs2.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void print_zahlen(int anzahl, ...) {
   va_list zeiger;
   int zahl;
   int i;

   printf("Es werden %d Zahlen ausgegeben\n",anzahl);
   va_start(zeiger,anzahl);
   for(i = 1; i <= anzahl; i++) {
      zahl=va_arg(zeiger,int);
      printf("%d\t",zahl);
   }
   printf("\n");
   va_end(zeiger);
}

int main(void) {
   print_zahlen(4,3,2,4,7);
   print_zahlen(6,11,22,33,44,55,66);
   return EXIT_SUCCESS;
}

