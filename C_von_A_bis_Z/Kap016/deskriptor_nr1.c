/* deskriptor_nr1.c */
#include <stdio.h>
#include <stdlib.h>
#ifdef __unix__
     #include <unistd.h>
#elif __MSDOS__ || __WIN32__ || _MSC_VER
     #include <io.h>
#endif

int main(void) {
   char puffer[100];
   read(0, &puffer, sizeof(puffer));
   printf("%s",puffer);
   return EXIT_SUCCESS;
}

