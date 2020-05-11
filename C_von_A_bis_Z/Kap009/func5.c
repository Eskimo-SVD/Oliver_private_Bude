/* func5.c */
#include <stdio.h>

int i=333; /* Globale Variable */

void aendern(void) {
   i = 111;
   printf("In der Funktion aendern: %d\n",i); /* 111 */
}

int main(void) {
   printf("%d\n",i);  /* 333 */
   aendern();
   printf("%d\n",i);  /* 111 */
   return 0;
}

