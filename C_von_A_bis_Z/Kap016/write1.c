/* write1.c */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#ifdef __unix__
      #include <unistd.h>
#elif __MSDOS__ || __WIN32__ || _MSC_VER
      #include <io.h>
#endif

int main(void) {
   int fh;
   char puffer[100];

   strcpy(puffer,"Dieser Text steht in \"test.txt\"\n");

   if((fh=open("test.txt",O_RDWR|O_CREAT|O_TRUNC)) == -1) {
      perror(NULL);   
      return EXIT_FAILURE; 
    }

   if((write(fh, &puffer, sizeof(puffer))) == -1) {
      perror("Fehler bei write");
      return EXIT_FAILURE;
   }
   printf("Erfolgreich in \"test.txt\" geschrieben\n");
   return EXIT_SUCCESS;
}

