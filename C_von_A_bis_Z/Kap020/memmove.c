/* memmove.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char str[21] = "1234567890";

   /* Den kompletten String nehmen und 
    * 10 Bytes weiter als Kopie ablegen */
   memmove(str+10, str, sizeof(str)-1);  
   printf("%s\n",str); 
   return EXIT_SUCCESS;
}

