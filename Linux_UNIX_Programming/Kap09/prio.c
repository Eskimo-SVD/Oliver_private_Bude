/* prio.c */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main (void) {
   printf("Priorit�t:%d\n", getpriority(PRIO_PROCESS, getpid()));

   printf("Priorit�t um 10 reduzieren\n");
   if (setpriority (PRIO_PROCESS, getpid (), 10) == -1) {
      perror ("Fehler bei setpriority()");
      exit (EXIT_FAILURE);
   }
   printf("Priorit�t:%d\n", getpriority(PRIO_PROCESS, getpid()));

    printf("Priorit�t um 10 erh�hen (root-only)\n");
    if (setpriority (PRIO_PROCESS, getpid (), -10) == -1) {
      perror ("Fehler bei setpriority()");
      exit (EXIT_FAILURE);
   }
   printf("Priorit�t:%d\n", getpriority(PRIO_PROCESS, getpid()));
   return EXIT_SUCCESS;
}
