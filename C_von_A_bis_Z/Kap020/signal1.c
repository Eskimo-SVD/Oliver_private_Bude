/* signal1.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigfunc(int sig) {
   int c;

   if(sig != SIGINT)
      return;
   else {
      printf("\nWollen Sie das Programm beenden (j/n) : ");
      c=getchar();
      if(c == 'j')
         exit (EXIT_FAILURE);
      else
         return;
   }
}

int main(void) {
   int i;

   signal(SIGINT, sigfunc);
   while(1) {
      printf("Mit STRG+C beenden");
      for(i = 0; i <= 48; i++)
         printf("\b");
   }
   return EXIT_SUCCESS;
}

