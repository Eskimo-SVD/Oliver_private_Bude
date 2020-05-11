/* null_ptr1.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char *ptr1 = NULL;
   char *ptr2 = 0;
   
   if(ptr1 != NULL){
      /* ... */
   }
   if(ptr2 != 0) {
      /* ... */
   }   
   return EXIT_SUCCESS;
}

