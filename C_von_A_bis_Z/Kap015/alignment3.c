/* alignment3.c */
#include <stdio.h>
#include <stdlib.h>

/* #pragma pack(1); */
enum{TRUE,FALSE}__attribute__ ((packed));

int main(void) {
   printf("%u Bytes\n", sizeof(TRUE));
   return EXIT_SUCCESS;
}

