/* memcmp.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char str1[] = "Have a lot of fun";
   char str2[] = "Have more than a lot of fun";
   int check, i;

   for(i = 4; i <= 10; i+=6) {
      check = memcmp( str1, str2, i);
      if(check == 0)
         printf("Vergleich %d Bytes: "
                "Beide Strings sind gleich\n", i);
      else
         printf("Die ersten %d Bytes sind "
                "unterschiedlich\n", i);
   }
   return EXIT_SUCCESS;
}

