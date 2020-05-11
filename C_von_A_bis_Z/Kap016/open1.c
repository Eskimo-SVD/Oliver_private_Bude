/* open1.c */
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

   if((fh=open("adress.txt", O_RDWR|O_CREAT|O_TRUNC))==-1) {
      perror("Fehler bei open()");
      return EXIT_FAILURE;
   }
   close(fh);
   return EXIT_SUCCESS;
}

