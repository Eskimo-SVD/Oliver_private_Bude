/* shreeder.c */
#include <stdio.h>
#include <stdlib.h>

void my_remove(char *rm) {
   unsigned long size;

   FILE *rem=fopen(rm, "w+b");
   if(rem != NULL)  {
      fseek(rem, 0L, SEEK_END);  /* Stream an das Dateiende   */
      size=ftell(rem);           /* Gr�sse in Bytes ermitteln */
      /* Kompletten Inhalt mit \0 �berschreiben */
      fwrite((char *)'\0', 1, size, rem);
      /* damit die Datei gel�scht werden kann, schliessen */
      fclose(rem);
      remove(rm);    /* Jetzt weg damit */
   }
}

int main(void) {
   char datei[] = "test.txt";
   my_remove(datei);
   return EXIT_SUCCESS;
}

