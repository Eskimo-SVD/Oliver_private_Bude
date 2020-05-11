/* raise_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigfunc(int sig) {
   if(sig == SIGINT)
      printf("SIGINT wurde ausgel�st\n");
}

int main(void) {
   signal(SIGINT,sigfunc);
   printf("Mit ENTER SIGINT ausl�sen\n");
   getchar();
   /* SIGINT ausl�sen */
   raise(SIGINT);
   return EXIT_SUCCESS;
}

