/* thread15.c */
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

static void cancel_test (void) {
   int oldstate;

   /* Thread als Unabbrechbar einrichten */
   if ((pthread_setcancelstate( PTHREAD_CANCEL_DISABLE,
                                &oldstate))!= 0) {
       printf("Fehler bei pthread_setcancelstate\n");
       exit (EXIT_FAILURE);
   }

   printf("Thread %ld im kritischen Codeabschnitt\n",
      pthread_self());
   sleep(5); // 5 Sekunden warten

   /* Alten Zustand des Threads wieder herstellen */
   if ((pthread_setcancelstate(oldstate, NULL))!= 0) {
       printf("Fehler bei pthread_setcancelstate\n");
       exit (EXIT_FAILURE);
   }
   printf("Thread %ld nach dem kritischen Codeabschnitt\n",
      pthread_self());
   pthread_exit ((void *) 0);
}

int main (void) {
   pthread_t t1;
   int *abbruch;

   printf("Main-Thread %ld gestartet\n", pthread_self());

   if((pthread_create(&t1, NULL, cancel_test, NULL)) != 0) {
      fprintf (stderr, "Fehler bei ptread_create ...\n");
      exit (EXIT_FAILURE);
   }
   /* Abbruch-Aufforderung an den Thread */
   pthread_cancel(t1);
   pthread_join (t1, &abbruch);
   if( abbruch == PTHREAD_CANCELED )
      printf("Thread %ld wurde abgebrochen\n", t1);
   printf("Main-Thread %ld beendet\n", pthread_self());
   return EXIT_SUCCESS;
}
