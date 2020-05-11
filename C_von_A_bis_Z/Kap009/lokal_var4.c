/* func4.c */
#include <stdio.h>

void aendern(void) {
   int i = 111;
   printf("In der Funktion aendern: %d\n",i);
}

int main(void) {
   int i=333;

   printf("%d\n",i);
   aendern();
   printf("%d\n",i);
   return 0;
}

