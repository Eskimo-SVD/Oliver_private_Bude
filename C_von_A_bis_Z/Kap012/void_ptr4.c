/* void_ptr4.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   void *void_ptr;
   int wert = 10;
   
   void_ptr=(int *)&wert;
   *(int *)void_ptr = 100;   
   printf("%d\n",wert);   /* 100 */
   return EXIT_SUCCESS;
}

