/* bufferoverflow2.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void overflow(void) {
   char zeichen[5];
   strcpy(zeichen, "1234567"); /*Überlauf*/
}

int main(void) {
   printf("Mein 1.Buffer Overflow\n");
   overflow();
   return EXIT_SUCCESS;
}

