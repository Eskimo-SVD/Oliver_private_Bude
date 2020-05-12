/* ping_pong.c */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef void (*sighandler_t)(int);

/* Flag kontrolliert die Beendigung der Hauptschleife */
volatile sig_atomic_t sigint = 1;

static sighandler_t
my_signal (int sig_nr, sighandler_t signalhandler) {
   struct sigaction neu_sig, alt_sig;

   neu_sig.sa_handler = signalhandler;
   sigemptyset (&neu_sig.sa_mask);
   neu_sig.sa_flags = SA_RESTART;
   if (sigaction (sig_nr, &neu_sig, &alt_sig) < 0)
      return SIG_ERR;
   return alt_sig.sa_handler;
}

/* Der Signalhandler */
static void catch_sigint (int sig_nr) {
   sigint--;
   /* brauchen wir nicht unbedingt, der Kernel arbeitet */
   /* neuerdings nach dem BSD-Schema statt SYSV.        */
   /* Der Handler bleibt eingerichtet.                  */
   my_signal (sig_nr, catch_sigint);
}

int main (void) {
   int i = 90000000, j, k;
   my_signal (SIGINT, catch_sigint);

/* Damit ist es m�glich, dass die Anweisungen in der Schleife */
/* noch fertig arbeiten ohne, dass bei Eintreffen des Signals  */
/* SIGINT das Programm abrupt unterbrochen wird. Im Beispiel  */
/* wird kein Ping ohne seinem Pong ausgegeben.                */
   while (sigint) {
      j = i;
      k = i;
      while (--j) ;
      while (--k) ;
      printf ("Ping-");
      j = i;
      k = i;
      while (--j) ;
      while (--k) ;
      printf ("Pong\n");
   }
   return EXIT_SUCCESS;
}
