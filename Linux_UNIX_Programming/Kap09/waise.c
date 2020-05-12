/* waise.c */
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main (void) {
   pid_t pid;

   switch (pid = fork ()) {
   case -1:
      printf ("Fehler bei fork()\n");
      break;
   case 0:
      printf ("--- Im Kindprozess (%d) ---\n",getpid());
      printf("Elternprozess : %d\n", getppid());
      sleep(2);
      printf ("--- Im Kindprozess (%d) ---\n",getpid());
      printf("Elternprozess : %d\n", getppid());
      break;
   default:
      printf ("--- Im Elternprozess (%d) ---\n",getpid());
      sleep(1);
      printf(" --- Elternprozess beendet sich vorzeitig ---\n");
      exit(0);  /* Sofort beenden */
   }
   return EXIT_SUCCESS;
}
