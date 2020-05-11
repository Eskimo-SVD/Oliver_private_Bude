/* strspn.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char string[] = "75301234-2123";
   int pos = strspn(string, "0123456789");

   printf("Position, welche keine Ziffer ist:");
   printf(" %d\n",pos); /* 8 */
   return EXIT_SUCCESS;
}

