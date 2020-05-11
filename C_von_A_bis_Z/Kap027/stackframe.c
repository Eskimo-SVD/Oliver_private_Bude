/* stackframe.c */
#include <stdio.h>
#include <stdlib.h>

void my_func(int wert1, int wert2) {
   int summe;

   summe = wert1+wert2;
   printf("Summe: %d \n",summe);
}

int main(void) {
   my_func(10,29);
   return 0;
}

