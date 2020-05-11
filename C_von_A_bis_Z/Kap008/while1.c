/* while1.c */
#include <stdio.h>

int main(void) {
   int zahl=1, tmp=0;

   while(zahl <= 10) {
      tmp=tmp+zahl;
      printf("%d+",zahl++);     /* Zahl + 1 */
   } 
   printf("\b = %d\n",tmp);
   return 0;
}

