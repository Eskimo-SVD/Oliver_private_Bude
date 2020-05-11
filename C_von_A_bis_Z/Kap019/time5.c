/* time5.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
   time_t start, stop;
   double diff;

   printf("Einen Augenblick bitte ...\n");
   start=time(NULL);
   while((diff=difftime(stop=time(NULL),start)) != 5);
   printf("%.1f sek. vorbei!!\n",diff);
   return EXIT_SUCCESS;
}

