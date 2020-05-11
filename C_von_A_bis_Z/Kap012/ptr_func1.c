/* ptr_func1.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int (*ptr) (const char*, ...);
   ptr=printf;
   (*ptr)("Hallo Welt\n");
   return EXIT_SUCCESS;
}

