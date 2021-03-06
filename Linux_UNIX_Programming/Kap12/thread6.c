/* thread6.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 2
#define BUF 255
#define COUNTER 10000000

static FILE *fz;

/* Statische Mutex-Variable */
pthread_mutex_t fz_mutex=PTHREAD_MUTEX_INITIALIZER;

static void open_file(const char *file) {
   fz = fopen( file, "w+" );
   if( fz == NULL ) {
      printf("Konnte Datei %s nicht �ffnen\n", file);
      exit(EXIT_FAILURE);
   }
}

static void thread_schreiben(void *name) {
   char string[BUF];

   printf("Bitte Eingabe machen: ");
   fgets(string, BUF, stdin);
   fputs(string, fz);
   fflush(fz);

   /* Mutex wieder freigeben */
   pthread_mutex_unlock( &fz_mutex );

   /* Thread-Ende */
   pthread_exit((void *)pthread_self());
}

static void thread_lesen(void *name) {
   char string[BUF];

   /* Mutex sperren */
   pthread_mutex_lock( &fz_mutex );
   rewind(fz);
   fgets(string, BUF, fz);
   printf("Ausgabe Thread %ld: ", pthread_self());
   fputs(string, stdout);
   fflush(stdout);

   /* Mutex wieder freigeben */
   pthread_mutex_unlock( &fz_mutex );

   /* Thread-Ende */
   pthread_exit((void *)pthread_self());
}


int main (void) {
   static pthread_t th1, th2;
   static int ret1, ret2;

   printf("->Haupt-Thread (ID:%ld) gestartet...\n",
      pthread_self());
   open_file("testfile");

   /* Mutex sperren */
   pthread_mutex_lock( &fz_mutex );   

   /* Threads erzeugen */
   if( pthread_create( &th1, NULL, &thread_schreiben,
                       NULL)!=0) {
      fprintf (stderr, "Konnte keinen Thread erzeugen\n");
      exit (EXIT_FAILURE);
   }
   /* Threads erzeugen */
   if(pthread_create(&th2,NULL, &thread_lesen, NULL) != 0) {
      fprintf (stderr, "Konnte keinen Thread erzeugen\n");
      exit (EXIT_FAILURE);
   }
   pthread_join(th1, &ret1);
   pthread_join(th2, &ret2);

   printf("<-Thread %ld fertig\n", th1);
   printf("<-Thread %ld fertig\n", th1);
   printf("<-Haupt-Thread (ID:%ld) fertig...\n",
      pthread_self());
   return EXIT_SUCCESS;
}
