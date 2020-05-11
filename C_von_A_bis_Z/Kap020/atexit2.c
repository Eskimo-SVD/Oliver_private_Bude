/* atexit2.c */
#include <stdio.h>
#include <stdlib.h>

char *memPtr;

void free_malloc(void) {
   /* Wurde überhaupt Speicher reserviert? */
   if(memPtr == NULL)
      printf("Kein Speicher war reserviert!!!\n");
   else {
      free(memPtr);
      printf("Speicher wurde freigegeben!!\n");
   }
}

int main(void) {
   memPtr =(char *) malloc(10000);

   if(memPtr==NULL)
      printf("Konnte keinen Speicher reservieren\n");
   if(atexit (free_malloc) != 0)
      printf("Konnte Funktionshandler nicht einrichten\n");
      
   /* Nach vielen Zeilen Code beenden wir das Programm */      
   printf("Ein Fehler - Programm wird beendet - \n");
   exit(EXIT_FAILURE);
   printf("Wird nicht mehr ausgegeben\n");
   return EXIT_SUCCESS;
}

