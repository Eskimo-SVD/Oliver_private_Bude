/* goto.c */
#include <stdio.h>

int main(void) {
   int i,j,k;
   for(i=1; i<10; i++) {
      for(j=1; j<10; j++) {
         for(k=1; k<10; k++) {
            printf("Tiefe Verschachtelungsebene\n");
            goto RAUS;
         }
      }
   }
   RAUS : printf("Mit einem Sprung raus hier \n");
   return 0;
}

