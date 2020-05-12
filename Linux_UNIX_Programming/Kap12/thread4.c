/* thread4.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define MAX_THREADS 3
#define BUF 255

/* Funktion ermittelt die Zuteilungs-Strategie *
 * und Priorit�t eines Threads */
static void getprio( pthread_t id ) {
   int policy;
   struct sched_param param;

   printf("\t->Thread %ld : ", id);
   if((pthread_getschedparam(id, &policy, &param)) == 0  ) {
      printf("Zuteilung: ");
      switch( policy ) {
         case SCHED_OTHER :  printf("SCHED_OTHER; "); break;
         case SCHED_FIFO  :  printf("SCHED_FIFO; ");  break;
         case SCHED_RR    :  printf("SCHED_RR; ");    break;
         default          :  printf("Unbekannt; ");  break;
      }
      printf("Priorit�t : %d\n", param.sched_priority);
   }
}

/* Funktion zum setzen der Zuteilungs-Strategie *
 * und Priori�t eines Threads */
static void setprio( pthread_t id, int policy, int prio ) {
   struct sched_param param;

   param.sched_priority=prio;
   if((pthread_setschedparam( pthread_self(),
                              policy, &param)) != 0  ) {
      printf("Konnte Zuteilungs-Strategie nicht �ndern\n");
      pthread_exit((void *)pthread_self());
   }
}

static void thread_prio_demo(void *name) {
   int policy;
   struct sched_param param;
   /*Aktuelle Zuteilungs-Strategie und Priorit�t erfragen */
   getprio(pthread_self());
   /* �ndern darf hier nur der root */
   if( getuid() != 0 ) {
      printf("Ver�ndern geht nur mit Superuser-Rechten\n");
      pthread_exit((void *)pthread_self());
   }
   /* Neue Zuteilungs-Strategie und Priorit�t festsetzen */
   setprio(pthread_self(), SCHED_RR, 2);
   /* Nochmals abfragen, ob erfolgreich ver�ndert ... */
   getprio(pthread_self());
   /* Thread-Ende */
   pthread_exit((void *)pthread_self());
}

int main (void) {
   int i;
   static int ret[MAX_THREADS];
   static pthread_t th[MAX_THREADS];

   printf("->Haupt-Thread (ID:%ld) gestartet...\n",
      pthread_self());
   /* Threads erzeugen */
   for (i = 0; i < MAX_THREADS; i++) {
      if (pthread_create ( &th[i],NULL, &thread_prio_demo,
                           NULL) != 0) {
         printf ("Konnte keinen Thread erzeugen\n");
         exit (EXIT_FAILURE);
      }
   }
   /* Auf die Threads warten */
   for (i = 0; i < MAX_THREADS; i++)
      pthread_join (th[i], &ret[i]);
   /* R�ckgabe der Threads auswerten */
   for (i = 0; i < MAX_THREADS; i++)
      printf("\t<-Thread %ld mit Arbeit fertig\n", ret[i]);
   printf("->Haupt-Thread (ID:%ld) fertig...\n",
      pthread_self());
   return EXIT_SUCCESS;
}
