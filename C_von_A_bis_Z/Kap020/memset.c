/* memset.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char credit_card[21] = "123456-aiex";
   char *ptr = strchr(credit_card, '-');

   *ptr++;
   /* Die letzten vier Zeichen der Kreditkartennummer
    * nicht angeben */
   memset(ptr, '*', 4);
   printf("%s\n",credit_card); 
   return EXIT_SUCCESS;
}

