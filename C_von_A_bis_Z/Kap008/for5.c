/* for5.c */
#include <stdio.h>

int main(void) {
   char ch;

   for(ch = 'A'; ch <= 'Z'; ch++)
      printf("%c, ", ch);
   printf("\n");
   return 0;
}

