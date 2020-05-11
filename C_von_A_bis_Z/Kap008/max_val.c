/* max_val.c */
#include <stdio.h>

int main(void) {
   int a=5,b=10;
   int max;
   max = (a > b) ? a : b;
   printf("Der größte Wert ist %d \n", max);
   return 0;
}

