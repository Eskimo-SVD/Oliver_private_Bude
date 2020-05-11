/* nicht_fertig.c */
#include <stdio.h>
#include <stdlib.h>
#define FERTIG

int main(void) {
   printf("Programmstart!\n");

#ifdef FERTIG
   #error "Das Programm ist noch nicht fertig gestellt!!\n"
#endif

   printf("Programmende");
   return EXIT_SUCCESS;
}

