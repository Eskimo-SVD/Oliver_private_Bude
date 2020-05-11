/* raise_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigfunc(int sig) {
   if(sig == SIGINT)
      printf("SIGINT wurde ausgelöst\n");
}

int main(void) {
   signal(SIGINT,sigfunc);
   printf("Mit ENTER SIGINT auslösen\n");
   getchar();
   /* SIGINT auslösen */
   raise(SIGINT);
   return EXIT_SUCCESS;
}

