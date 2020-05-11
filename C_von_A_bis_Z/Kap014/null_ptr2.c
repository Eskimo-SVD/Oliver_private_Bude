/* null_ptr2.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) { 
   int *ptr = NULL;
   int i = NULL;      // Falsch
     
   return EXIT_SUCCESS;
}

