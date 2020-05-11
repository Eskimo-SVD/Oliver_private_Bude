/* nicht_gerade.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX 101

int main(void) {
   printf("Programmstart\n");

#if (MAX % 2) == 1
   #error "symb. Konstante MAX muss eine gerade Zahl sein!\n"
#endif

   printf("Programmende\n");
   return EXIT_SUCCESS;
}

