/* my_itoa.c */
#include <stdio.h>
#include <stdlib.h>

char *my_itoa(int wert, int laenge) {
   char *ret =(char *) malloc(laenge+1 * sizeof(char));
   int i;

   for(i  =0; i < laenge; i++) {
      ret[laenge-i-1] = (wert % 10) + 48;
      wert = wert / 10;
   }
   ret[laenge]='\0';
   return ret;
}

int main(void) {
   printf("%s\n", my_itoa(1234,4));
   printf("%s\n", my_itoa(5432,6));
   return EXIT_SUCCESS;
}

