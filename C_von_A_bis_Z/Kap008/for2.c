/* for2.c */
#include <stdio.h>

int main(void) {
   int zahl;

   for(zahl=1234; zahl >= 1; zahl/=10)
      printf("%d", zahl%10);
   printf("\n");
   return 0;
}

