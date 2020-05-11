/* iso_ascii.c */
#include <stdio.h>

int main(void) {
   int i;
   for(i=0; i < 254; i++) {
         if(i==27)   // ESC-Zeichen ignorieren
            continue;
         printf(" |%d : %c| ",i,i);
      }
   return 0;
}


