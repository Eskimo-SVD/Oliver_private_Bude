/* fopen2.c */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
   FILE *datei;

   if(argc < 2) {
      printf("Verwendung : %s [datei_zum_Oeffnen]\n", *argv);
      return EXIT_FAILURE;
   }
   datei = fopen(argv[1], "r");
   if(datei != NULL)
      printf("Datei erfolgreich geöffnet\n");
   else {
      printf("Fehler beim Öffnen der Datei");
      return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}

