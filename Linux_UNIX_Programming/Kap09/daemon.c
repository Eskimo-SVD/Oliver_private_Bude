/* daemon.c */
#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int);

static sighandler_t 
handle_signal (int sig_nr, sighandler_t signalhandler) {
   struct sigaction neu_sig, alt_sig;

   neu_sig.sa_handler = signalhandler;
   sigemptyset (&neu_sig.sa_mask);
   neu_sig.sa_flags = SA_RESTART;
   if (sigaction (sig_nr, &neu_sig, &alt_sig) < 0)
      return SIG_ERR;
   return alt_sig.sa_handler;
}

static void start_daemon (const char *log_name, int facility) {
   int i;
   pid_t pid;

   /* Elternprozeß beenden, somit haben wir einen Waisen */
   /* dessen sie jetzt vorerst init annimmt              */
   if ((pid = fork ()) != 0)
      exit (EXIT_FAILURE);

   /* Unser Kindprozess wird zum Session-Führer. Mißlingt */
   /* dies, kann der Fehler daran liegen das der Prozeß   */
   /* bereit Sessionführer ist                            */
   if (setsid() < 0) {
      printf("%s kann nicht Session-Führer werden!\n", log_name);
      exit (EXIT_FAILURE);
   }
   /* Signal SIGHUP ignorieren */
   handle_signal (SIGHUP, SIG_IGN);
   /* Oder einfach: signal(SIGHUP, SIG_IGN) ... */
   /* Das Kind terminieren */
   if ((pid = fork ()) != 0)
      exit (EXIT_FAILURE);

   /* Gründe für das Arbeitsverzeichnis:
    * + core-Datei wird im aktuellen Arbeitsverzeichnis 
    *   hinterlegt.
    * + Damit bei Beendigung mit umount das Dateisystem sicher 
    *   abgehängt werde kann 
    */
   chdir ("/");

   /* Damit wir nicht die Bitmaske vom Elternprozeß     */
   /* erben bzw. diese bleiben, stellen wir diese auf 0 */
   umask (0);

   /*Wir schließen alle geöffneten Filedeskriptoren.... */
   for (i = sysconf (_SC_OPEN_MAX); i > 0; i--)
      close (i);

   /* Da unser Dämonprozeß selbst kein Terminal für */
   /* die Ausgabe hat....                           */
   openlog (log_name, LOG_PID | LOG_CONS| LOG_NDELAY, facility);
}

int main (int argc, char **argv) {
   int time   = 15;

   start_daemon ("meinDaemon", LOG_LOCAL0);
   while (1) {
      /* Enlossschleifen: Hier sollte nun der Code für den
       * Daemon stehen, was immer er auch tun soll.
       * Bspw. mit E-Mails abholen, versenden (was kein fieser
       * Verweis sein soll, um mit dem Spammen anzufangen), usw.
       * Bei Fehlermeldungen Beispiesweise:
       * if(dies_ist_Passiert)
       * syslog(LOG_WARNING, "dies_ist_Passiert");
       * else if(das_ist_Passiert)
       * syslog(LOG_INFO, "das_ist_Passiert"); 
       */
      syslog( LOG_NOTICE, "Daemon gestartet ...\n");
      sleep(time);
      syslog( LOG_NOTICE, "Daemon läuft bereits %d Sekunden\n",
         time);
      break;
   }
   syslog( LOG_NOTICE, "Daemon hat sich beendent\n");
   closelog();
   return EXIT_SUCCESS;
}

