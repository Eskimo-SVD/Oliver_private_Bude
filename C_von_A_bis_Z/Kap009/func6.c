/* func6.c */
#include <stdio.h>

int i=333;  /* Globale Variable i */

void aendern(void) {
   i = 111;   /* Ändert die globale Variable */
   printf("In der Funktion aendern: %d\n",i);  /* 111 */
}

int main(void) {
   int i = 444;

   printf("%d\n",i);  /* 444 */
   aendern();
   printf("%d\n",i);  /* 444 */
   return 0;
}

