/* wait.c */
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

static void child_status (int status) {
   if (WIFEXITED (status)) {
      printf ("Kind normal beendet mit Rückgabwert %d\n",
         WEXITSTATUS(status));
   }
   else if (WIFSIGNALED (status)) {
      printf ("Kind mit Signalnummer %d beendet\n",
         WTERMSIG(status));
      /* WCOREDUMP könnte hier stehen */
   }
   else if (WIFSTOPPED (status)) {
      printf ("Kind wurde angehalten mit Signalnummer %d\n",
         WSTOPSIG(status));
      /* I.d.R. wird dies SIGSTOP sein, aber es gibt */
      /* ja auch noch das ptrace()-Interface.        */
   }
}

int main (void) {
   pid_t pid;
   int status;
   int end;

   switch (pid = fork ()) {
   case -1:
      perror("fork()");
      return EXIT_FAILURE;
   case 0:
      printf (" --- Im Kindprozess ---\n");
      printf ("Wie wollen Sie den Prozess beenden?\n\n");
      printf ("- 1 - WIFEXITED   (normal)\n");
      printf ("- 2 - WIFSIGNALED (abnormal)\n");
      printf ("Ihre Auswahl : ");
      scanf ("%d", &end);
      if (end == 1)
         exit (66);
      else if (end == 2)
         abort ();  /* Entspricht kill(0, SIGABRT); */
      else
         printf ("Was den nun? ->%d<- ???\n", end);
      break;      /* Normale Beendigung mit 0 */
   default:       /* Elternprozess wartet auf das Kind mit pid */
      if (wait (&status) != pid) {
         perror("wait()");
         return EXIT_FAILURE;
      }
      /* Status vom Kind auswerten */
      child_status (status);
   }
   return EXIT_SUCCESS;
}
