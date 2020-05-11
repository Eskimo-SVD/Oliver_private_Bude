/* time1.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef  __unix__
   #define clrscr() printf("\x1B[2J")
#else
   #include <stdlib.h>
   #define clrscr() system("cls")
#endif

int main(void) {
   time_t t;

   time(&t);
   while(1) {
      clrscr();
      printf("%ld\n",t);
      printf("Mit <STRG><C> bzw. <STRG><D> beenden!! ");
      time(&t);
   }
   return EXIT_SUCCESS;
}

