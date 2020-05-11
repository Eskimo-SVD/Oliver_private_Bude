/* for3.c */
#include <stdio.h>

int main(void) {
   int sek;

   for(sek = 5; sek > 0; sek--)
      printf("%d Sekunden!\n", sek);
   printf("Die Zeit ist abgelaufen! \n");
   return 0;
}

