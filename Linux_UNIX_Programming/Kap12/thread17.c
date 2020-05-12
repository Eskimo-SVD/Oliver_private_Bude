/* thread17.c */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_THREADS 3

/* TSD-Datenschl�ssel */
static pthread_key_t tsd_key;

/* Schreibt einen Text in eine Datei f�r 
 * jeden aktuellen Thread */
void thread_write (const char* text) {
  /* TSD-Daten lesen */
  FILE* th_fp = (FILE*) pthread_getspecific (tsd_key);
  fprintf (th_fp, "%s\n", text);
}

/* Am Ende den Zeiger auf die Datei(en) schlie�en */
void thread_close (void* th_fp) {
  fclose ((FILE*) th_fp);
}

void* thread_tsd (void* args) {
  char th_fpname[20];
  FILE* th_fp;

  /* Einen threadspezifischen Dateinamen erzeugen */
  sprintf(th_fpname,"thread%d.thread",(int) pthread_self());
  /* Die Datei �ffnen  */
  th_fp = fopen (th_fpname, "w");
  if( th_fp == NULL )
    pthread_exit(NULL);
  /* TSD-Daten zu TSD-Schl�ssel festlegen */
  pthread_setspecific (tsd_key, th_fp);

  thread_write ("Thread wurde gestartet...\n");
  
  /* Hier kommt die eigentliche Arbeit des Threads hin */

  thread_write("Thread ist fertig...\n");
  pthread_exit(NULL);
}

int main (void) {
  int i;
  pthread_t threads[MAX_THREADS];

  /* Einen neuen TSD-Schl�ssel erzeugen - Beim Ende eines 
   * Threads wird die Funktion thread_close ausgef�hrt   */
  pthread_key_create (&tsd_key, thread_close);
  /* Threads erzeugen */
  for (i = 0; i < MAX_THREADS; ++i)
    pthread_create (&(threads[i]), NULL, thread_tsd, NULL);
  /* Auf die Threads warten  */
  for (i = 0; i < MAX_THREADS; ++i)
    pthread_join (threads[i], NULL);
  return EXIT_SUCCESS;
}
