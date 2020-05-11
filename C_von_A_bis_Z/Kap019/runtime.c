/* runtime.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
   clock_t prgstart, prgende;
   int c;

   prgstart=clock();
   printf("Geben Sie etwas ein und beenden Sie mit #\n");
   printf("\n > ");
   while((c=getchar())!= '#')
      putchar(c);
   prgende=clock();
   printf("Die Programmlaufzeit betrug %.2f Sekunden\n",
      (float)(prgende-prgstart) / CLOCKS_PER_SEC);
   return EXIT_SUCCESS;
}

