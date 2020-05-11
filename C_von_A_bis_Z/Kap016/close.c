/* close.c */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#ifdef __unix__
      #include <unistd.h>
#elif __MSDOS__ || __WIN32__ || _MSC_VER
      #include <io.h>
#endif

int main(void) {
   int fh;

   if((fh=open("adressen.txt", O_RDONLY | O_CREAT)) == -1) {
      perror("Fehler bei open");
      return EXIT_FAILURE;
   }
   if((close(fh)) == -1)
      printf("Fehler beim Schliessen der Datei\n");
   else
      printf("Datei wurde ordentlich geschlossen\n");
   return EXIT_SUCCESS;
}

