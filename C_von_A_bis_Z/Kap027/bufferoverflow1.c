/* bufferoverflow1.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char *str = "0123456789012";
   char buf[10];

   strcpy(buf, str);
   printf("%s",buf);
   return EXIT_SUCCESS;
}

